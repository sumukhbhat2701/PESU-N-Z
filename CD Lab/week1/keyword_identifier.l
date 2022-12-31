%%  
int|float|char|for|while|if printf("%s is a keyword", yytext); // compulsory first
([a-z]|[A-Z]|_])([a-z]|[A-Z]|[0-9]|_)* printf("%s is a identifier", yytext);
.;
%%

int yywrap()  
{
	return 1;
}

int main()
{
	yylex(); 
	return 0;
}
