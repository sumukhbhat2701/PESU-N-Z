%%  
. ;   // Error recovery => . => pattern = any character except new line and ; => no action => DOESNT print on entering
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
