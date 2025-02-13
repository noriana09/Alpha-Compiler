/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     ID = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     FOR = 263,
     FUNCTION = 264,
     RETURN = 265,
     BREAK = 266,
     CONTINUE = 267,
     AND = 268,
     NOT = 269,
     OR = 270,
     LOC = 271,
     TRUE = 272,
     FALSE = 273,
     NIL = 274,
     ASSIGNMENT = 275,
     PLUS = 276,
     MINUS = 277,
     MUL = 278,
     DIV = 279,
     MOD = 280,
     EQUAL_TO = 281,
     NOT_EQUAL_TO = 282,
     PLUS_PLUS = 283,
     MINUS_MINUS = 284,
     GREATER_THAN = 285,
     LESS_THAN = 286,
     GREATER_THAN_OR_EQUAL = 287,
     LESS_THAN_OR_EQUAL = 288,
     STRING = 289,
     LEFT_BRACE = 290,
     RIGHT_BRACE = 291,
     LEFT_BRACKET = 292,
     RIGHT_BRACKET = 293,
     LEFT_PARENTHESIS = 294,
     RIGHT_PARENTHESIS = 295,
     SEMICOLON = 296,
     COMMA = 297,
     COLON = 298,
     DOUBLE_COLON = 299,
     DOT = 300,
     DOUBLE_DOT = 301,
     UMINUS = 302
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define FOR 263
#define FUNCTION 264
#define RETURN 265
#define BREAK 266
#define CONTINUE 267
#define AND 268
#define NOT 269
#define OR 270
#define LOC 271
#define TRUE 272
#define FALSE 273
#define NIL 274
#define ASSIGNMENT 275
#define PLUS 276
#define MINUS 277
#define MUL 278
#define DIV 279
#define MOD 280
#define EQUAL_TO 281
#define NOT_EQUAL_TO 282
#define PLUS_PLUS 283
#define MINUS_MINUS 284
#define GREATER_THAN 285
#define LESS_THAN 286
#define GREATER_THAN_OR_EQUAL 287
#define LESS_THAN_OR_EQUAL 288
#define STRING 289
#define LEFT_BRACE 290
#define RIGHT_BRACE 291
#define LEFT_BRACKET 292
#define RIGHT_BRACKET 293
#define LEFT_PARENTHESIS 294
#define RIGHT_PARENTHESIS 295
#define SEMICOLON 296
#define COMMA 297
#define COLON 298
#define DOUBLE_COLON 299
#define DOT 300
#define DOUBLE_DOT 301
#define UMINUS 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 81 "parser.y"
{
    int intVal;
    char* stringVal;
    float floatVal;
    struct forloop* forVal;
    struct expr* exprVal;
    struct call* call;
    struct SymbolTableEntry *tptr;
    struct Lc_stack_t* loop;
}
/* Line 1529 of yacc.c.  */
#line 154 "parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

