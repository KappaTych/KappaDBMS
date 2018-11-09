/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

#ifndef YY_YY_BISON_SQL_H_INCLUDED
# define YY_YY_BISON_SQL_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "bison_sql.ypp" /* yacc.c:1910  */


#include "../sql-stmt/Table.h"
#include "../sql-stmt/Expression.h"


#include "../../storage/datatypes/object.h"
#include "../../storage/StorageEngine.h"

#ifndef YYtypeDEF_YY_SCANNER_T
#define YYtypeDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif


#line 60 "bison_sql.h" /* yacc.c:1910  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    STRING = 259,
    BLOB_STRING = 260,
    INT_CONST = 261,
    TRUE = 262,
    FALSE = 263,
    DOUBLE_CONST = 264,
    DOUBLE = 265,
    TEXT = 266,
    INTEGER = 267,
    CREATE = 268,
    TABLE = 269,
    DROP = 270,
    SHOW = 271,
    NUL = 272,
    SELECT = 273,
    VALUES = 274,
    INTO = 275,
    INSERT = 276,
    FROM = 277
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "bison_sql.ypp" /* yacc.c:1910  */

    int64_t ival;
    double fval;
    bool bval;
    std::string* strval;
    
    sql::TableName* table_name;
    sql::ColumnDefinition* column;
    sql::DataType column_type_t;
    sql::Expression* expr_t;

    std::vector<sql::ColumnDefinition>* column_vec;
    std::vector<std::string>* id_vec;
    std::vector<sql::Expression>* expr_vec;

#line 111 "bison_sql.h" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_BISON_SQL_H_INCLUDED  */
