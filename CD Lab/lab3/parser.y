%{
	#include "sym_tab.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define YYSTYPE char*
	char *name;
	int size;
	int line;
	int type = -1;
	int scope = 0;
	char *value = "---";
	void yyerror(char* s); // error handling function
	int yylex(); // declare the function performing lexical analysis
	extern int yylineno; // track the line number
	int errors = 0;

%}

%token T_INT T_CHAR T_DOUBLE T_WHILE  T_INC T_DEC   T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_PRINTLN T_STRING  T_FLOAT T_BOOLEAN T_IF T_ELSE T_STRLITERAL T_DO T_INCLUDE T_HEADER T_MAIN T_ID T_NUM

%start START


%nonassoc T_IFX
%nonassoc T_ELSE

%%
START : PROG { printf("Valid syntax\n"); YYACCEPT; }	
        ;	
	  
PROG :  MAIN PROG				
	|DECLR ';' PROG 				
	| ASSGN ';' PROG 			
	| 					
	;
	 

DECLR : TYPE LISTVAR 
	;	


LISTVAR : LISTVAR ',' VAR 
	  | VAR
	  ;

VAR: T_ID '=' EXPR 	{
				/*
				    check if symbol is in the table
				    if it is then error for redeclared variable
				    else make entry and insert into table
				    insert value coming from EXPR
				    revert variables to default values:value,type
                   		 */
					if(check_symbol_table($1))
					{
						char err[] = "Redeclared Variable - ";
						strcat(err, $1);
						yyerror(err);
					}
					else
					{
						insert_into_table($1, size, type, yylineno, scope);
						insert_value_to_name($1, value);
						type = -1;
						value = "---";

					}
			}
     | T_ID 		{

					if(check_symbol_table($1))
					{
						char err[] = "Redeclared Variable - ";
						strcat(err, $1);
						yyerror(err);
					}
					else
					{
						name = $1;
						scope = 1;
						insert_into_table(name,size,type,yylineno,scope);
					}
			}	 

//assign type here to be returned to the declaration grammar
TYPE : T_INT  {size = 2; type = 2; }
       | T_FLOAT {size = 4; type = 3; } 
       | T_DOUBLE { size = 8; type = 4; }
       | T_CHAR { size = 1; type = 1; }
       ;
    
/* Grammar for assignment */   
ASSGN : T_ID '=' EXPR 	{
				if(!check_symbol_table($1))
				{
					char err[] = "Undeclared Variable - ";
					strcat(err, $1);
					yyerror(err);
				}
				insert_value_to_name($1, value);
			}
	;

EXPR : EXPR REL_OP E
       | E 	{ value = strdup($1); } //store value using value variable declared before
       ;
	   
/* Expression Grammar */	   
E : E '+' T 	{ 
		/*
		        check type
		        if character type return error
		        convert to int/float perform calculation
		        convert back to string 
		        copy to grammar rule E
          	*/

			  if(type == 2){
					sprintf($$,"%d",(atoi($1)+atoi($3)));
				}
				else if(type==3 || type==4){
					sprintf($$,"%lf",(atof($1)+atof($3)));
				}
				else{
					char err[] = "Incompatible type - ";
					strcat(err, $1);
					yyerror(err);
					$$="---";
				}
		}
    | E '-' T 	{ 
		/*
			check type
			if character type return error
			convert to int/float perform calculation
			convert back to string 
			copy to grammar rule E
            	*/

			if(type==2){
				sprintf($$,"%d",(atoi($1)-atoi($3)));
			}
			else if(type==3 || type==4){
				sprintf($$,"%lf",(atof($1)-atof($3)));
			}
			else{
				char err[] = "Incompatible type - ";
				strcat(err, $1);
				yyerror(err);
				$$="---";
			}
		}
    | T { $$ = strdup($1); }
    ;
	
	
T : T '*' F 	{ 
		/*
		        check type
		        if character type return error
		        convert to int/float perform calculation
		        convert back to string 
		        copy to grammar rule T
            	*/

				if(type==2){
					sprintf($$,"%d",(atoi($1)*atoi($3)));
				}
				else if(type==3 || type==4 ){
					sprintf($$,"%lf",(atof($1)*atof($3)));
				}
				else{
					char err[] = "Incompatible type - ";
					strcat(err, $1);
					yyerror(err);
					$$="---";
				}
		}
    | T '/' F 	{ 
		/*
		        check type
		        if character type return error
		        convert to int/float perform calculation
		        convert back to string 
		        copy to grammar rule T
           	*/

			   if(type==2){
					sprintf($$,"%d",(atoi($1)/atoi($3)));
				}
				else if(type==3 || type==4){
					sprintf($$,"%lf",(atof($1)/atof($3)));
				}
				else{
					char err[] = "Incompatible type - ";
					strcat(err, $1);
					yyerror(err);
					$$="---";
				}
		}
    | F { $$ = strdup($1); } //copy value from F to grammar rule T
    ;

F : '(' EXPR ')' { $$=strdup($2);}
    | T_ID 	{
		/*
		        check if variable is in table
		        check the value in the variable is default
		        if yes return error for variable not initialised
		        else duplicate value from T_STRLITERAL to F
		        check for type match
		        (secondary type variable used here)
            	*/
				if(check_symbol_table($1)){
					$$=strdup($1);
					type=type_from_value($1);
				}
				else{
					char err[] = "Variable not declared - ";
					strcat(err, $1);
					yyerror(err);
				}
	}
    | T_NUM 	{
    		/*
		        duplicate value from T_NUM to F
		        check for type match
		        (secondary type variable used here)
                */
				$$=strdup($1);
				type=type_from_value($1);
		}
    | T_STRLITERAL {
            	/*
			duplicate value from T_STRLITERAL to F
			check for type match
			(secondary type variable used here)
            	*/
				$$=strdup($1);
				type=type_from_value($1);
		}
    ;



REL_OP :   T_LESSEREQ
	   | T_GREATEREQ
	   | '<' 
	   | '>' 
	   | T_EQCOMP
	   | T_NOTEQUAL
	   ;	


/* Grammar for main function */
//increment and decrement at particular points in the grammar to implement scope tracking
MAIN : TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{' {scope++;} STMT '}'{scope--;};

EMPTY_LISTVAR : LISTVAR
		|	
		;

STMT : STMT_NO_BLOCK STMT
       | BLOCK STMT
       |
       ;


STMT_NO_BLOCK : DECLR ';'
       | ASSGN ';'
       | T_IF '(' COND ')' STMT %prec T_IFX	/* if loop*/
       | T_IF '(' COND ')' STMT T_ELSE STMT	/* if else loop */ 
       ;
       
//increment and decrement at particular points in the grammar to implement scope tracking
BLOCK : '{'{scope++;}  STMT '}'{scope--;} ;

COND : EXPR 
       | ASSGN
       ;


%%


/* error handling function */
void yyerror(char* s)
{
	printf("Error: %s at %d \n",s,yylineno);
	errors++;
}


int main(int argc, char* argv[])
{
	t = allocate_space_for_table();
	yyparse();
	display_symbol_table();
	return 0;

}
