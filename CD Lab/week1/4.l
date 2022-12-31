%%  
[a-z] printf("Small case letter\n");  // for non small case letters, prints as it it i.e enters panic mode
. ; // goes line by line, so [a-z] is already has a rule, wont be affected i.e . here implies all characters except [a-z]
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
