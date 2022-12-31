%%  
([a-z]|[A-Z]|_])([a-z]|[A-Z]|[0-9]|_)* printf("%s is a identifier", yytext);
.;
%%

int yywrap()  
{
	return 1;
}

int main()
{
	yyin = fopen("identifiers.txt", "r");
	yylex(); 
	fclose(yyin);
	return 0;
}
