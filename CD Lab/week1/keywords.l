%%  
int|float|char|for|while|if printf("%s is a keyword", yytext);  // define all the 32 keywords explicitly
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
