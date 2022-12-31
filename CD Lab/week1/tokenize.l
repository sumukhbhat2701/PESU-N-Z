%%  
int|float|char|for|while|if printf("%s is a keyword ", yytext); // compulsory first
([a-z]|[A-Z]|_])([a-z]|[A-Z]|[0-9]|_)* printf("%s is a identifier ", yytext);
[(),{}] { ECHO; printf("-punctuation "); }  // { ... } for multiple actions
= printf("assignment operator ");
[0-9]+ { ECHO; printf("-constant "); }
[+/*-] { ECHO; printf("-operator "); }
[+][+] printf("increment operator ");
[-][-] printf("decrement operator "); 
; printf("semicolon ");
.|\n ECHO; // ignore new line and any unmatched patterns
%% 

int yywrap()  
{
	return 1;
}

int main()
{
	yyin = fopen("code.c", "r");
	yylex(); 
	fclose(yyin);
	return 0;
}
