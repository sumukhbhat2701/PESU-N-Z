/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    DOUBLE = 261,
    VOID = 262,
    LONG = 263,
    FOR = 264,
    DO = 265,
    MAIN = 266,
    WHILE = 267,
    IF = 268,
    ELSE = 269,
    PRINTF = 270,
    INCLUDE = 271,
    NL = 272,
    NUM = 273,
    ID = 274,
    DOT = 275,
    RETURN = 276,
    ADD = 277,
    SUBTRACT = 278,
    DIVIDE = 279,
    MULTIPLY = 280,
    LE = 281,
    GE = 282,
    EQ = 283,
    NE = 284,
    NOT = 285,
    GT = 286,
    LT = 287,
    INC = 288,
    DEC = 289,
    OR = 290,
    AND = 291,
    LEFTPARENTHESIS = 292,
    RIGHTPARENTHESIS = 293,
    LEFTBRACKET = 294,
    RIGHTBRACKET = 295,
    LEFTBRACES = 296,
    RIGHTBRACES = 297,
    COMMA = 298,
    SEMICOLON = 299,
    ASSIGN = 300,
    REFERENCE = 301,
    INTEGERCONSTANT = 302,
    FLOATCONSTANT = 303,
    CHARCONSTANT = 304,
    STRING = 305,
    ANDAND = 306,
    OROR = 307
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define CHAR 260
#define DOUBLE 261
#define VOID 262
#define LONG 263
#define FOR 264
#define DO 265
#define MAIN 266
#define WHILE 267
#define IF 268
#define ELSE 269
#define PRINTF 270
#define INCLUDE 271
#define NL 272
#define NUM 273
#define ID 274
#define DOT 275
#define RETURN 276
#define ADD 277
#define SUBTRACT 278
#define DIVIDE 279
#define MULTIPLY 280
#define LE 281
#define GE 282
#define EQ 283
#define NE 284
#define NOT 285
#define GT 286
#define LT 287
#define INC 288
#define DEC 289
#define OR 290
#define AND 291
#define LEFTPARENTHESIS 292
#define RIGHTPARENTHESIS 293
#define LEFTBRACKET 294
#define RIGHTBRACKET 295
#define LEFTBRACES 296
#define RIGHTBRACES 297
#define COMMA 298
#define SEMICOLON 299
#define ASSIGN 300
#define REFERENCE 301
#define INTEGERCONSTANT 302
#define FLOATCONSTANT 303
#define CHARCONSTANT 304
#define STRING 305
#define ANDAND 306
#define OROR 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
