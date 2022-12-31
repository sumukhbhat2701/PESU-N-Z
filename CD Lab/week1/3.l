%%  
. ECHO;  // mimicking 1.l without entering panic mode => SYNTAX: PATTERN ACTION;
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
