%{
int lineno = 1; // default = 0
%}

%%

(.*)\n printf("%d  %s", lineno++, yytext); // yytext is a char string with token input stored - MATCH all characters with \n at the end - WITH no \n like in previous programs, it will print one \n per enter press dur to panic mode entering

%% 

int yywrap()  
{
	return 1;
}

int main()
{
	// yyin already declared for the purpose - default = stdin
	yyin = fopen("input.txt", "r");
	yylex(); 
	fclose(yyin);
	return 0;
}
