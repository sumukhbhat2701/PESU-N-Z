%{
#include<stdio.h> // simply - printf() works without this in 4.l in RULE part?
%}

%%  
abb printf("1");
aba printf("2");
a printf("3");
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

/*
a => 3
ababa => 1b3



*/
