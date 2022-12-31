%%  
(" ")*"//"([a-z]|[A-Z]|[0-9]|" ")* printf("Single Line comment - %s",yytext); // just "" means space
(" ")*\/\*([a-z]|[A-Z]|[0-9]|" "|\n)*\*\/ printf("Multi Line comment - %s",yytext);
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
