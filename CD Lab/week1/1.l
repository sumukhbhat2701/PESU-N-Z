%{

%}

%%  // no rule => panic mode => o/p will be as same as i/p

%%

// some OS dont need yywrap() and main()
// yywrap() is called when processing is done by lexcompiler, returns 1 if done processing, otherwise return 0 if more processing is needed
int yywrap()  
{
	return 1;
}

int main()
{
	yylex();  // main() for lexcode
	return 0;
}
