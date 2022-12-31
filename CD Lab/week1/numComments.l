%{
int sinCom = 0, mulCom = 0;

%}

%%  
"//"([a-z]|[A-Z]|[0-9]|" ")* printf("Single Line comment - %s - #%d",yytext, ++sinCom); // just " " means space
"/*"(.*)"*/" printf("Multi Line comment - %s - #%d",yytext, ++mulCom);   // .* => anything any number of times. use \ to surpass the actual meaning or use in quotes "..."
. ;
%%

int yywrap()  
{
	return 1;
}

int main()
{
	yyin = fopen("commentInput.c", "r");
	yylex(); 
	fclose(yyin);
	return 0;
}
