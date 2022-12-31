%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	extern FILE *yyin;
	extern FILE *yyout;
	
	int lineNumber = 1;
	void ret_print(char *token_type);
	void yyerror();
%}

%x MULTILINECOMMENT

alphabets 		[a-zA-Z]
numbers 		[0-9]
alphanumericals 		{alphabets}|{numbers}
print		[ -~]

ID 		[_a-zA-Z][_a-zA-Z0-9]{0,30}
INTEGERCONSTANT		"0"|[0-9]{numbers}*
FLOATCONSTANT		"0"|{numbers}*"."{numbers}+
CHARCONSTANT		(\'{print}\')|(\'\\[nftrbv]\')
STRING		\".*\"

%%

\n                  { lineNumber++; };
"//".*              ;
"/*"                {BEGIN MULTILINECOMMENT;}
<MULTILINECOMMENT>[\n]       { lineNumber++; }
<MULTILINECOMMENT>"*"[^/]    ;
<MULTILINECOMMENT>[^"*"]     ;
<MULTILINECOMMENT>"*/"       {BEGIN 0;}


^"#include"[ ]*<.+\.h> { return INCLUDE; }
"int"     { return INT; }
"long"     { return LONG; }
"float"   { return FLOAT; }
"char"    { return CHAR; }
"void"    { return VOID; }
"double"  { return DOUBLE; }
"return"  { return RETURN; }
"for"     { return FOR; }
"do"      { return DO; }
"main"    { return MAIN; }
"while"   { return WHILE; }
"if"      { return IF; }
"else"    { return ELSE; }
"printf"  { return PRINTF; }


"<="    { return LE; }
">="    { return GE; }
"=="    { return EQ; }
"!="    { return NE; }
"!"     { return NOT; }
">"     { return GT; }
"<"     { return LT; }
"."     { return DOT; }
"++"    { return INC; }
"--"    { return DEC; }
"||"    { return OR; }
"&&"    { return AND; }
"+"     { return ADD; }
"-"     { return SUBTRACT; }
"/"     { return DIVIDE; }
"*"     { return MULTIPLY; }


")"		{ return RIGHTPARENTHESIS; }
"]"		{ return RIGHTBRACES; }
"("		{ return LEFTPARENTHESIS; }
"["		{ return LEFTBRACES; }
"{"		{ return LEFTBRACKET; }
"}"		{ return RIGHTBRACKET; }
";"		{ return SEMICOLON; }
","		{ return COMMA; }
"="		{ return ASSIGN; }
"&"		{ return REFERENCE; }


{ID} 	{ return ID; }
{INTEGERCONSTANT} { return INTEGERCONSTANT; }
{FLOATCONSTANT} { return FLOATCONSTANT; }
{CHARCONSTANT} { return CHARCONSTANT; }
{STRING} { return STRING; }

[ \t\r\f]+ ;

.				{ return *yytext; }

%%
