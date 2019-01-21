// A Bison parser, made by GNU Bison 3.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

// //                    "%code top" blocks.
#line 1 "bison_sql.ypp" // lalr1.cc:425

    #include "bison_sql.hpp"
    #include "flex_sql.hpp"
    #include "../parser.hpp"

    #include <string>

    static yy::BisonParser::symbol_type yylex(yy::FlexScanner& scanner) {
        return scanner.get_next_token();
    }

    void yy::BisonParser::error(yy::location const&, const std::string&) {}

#line 52 "bison_sql.cpp" // lalr1.cc:425




#include "bison_sql.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 154 "bison_sql.cpp" // lalr1.cc:512

  /// Build a parser object.
   BisonParser :: BisonParser  (yy::FlexScanner& scanner_yyarg, sql::Parser& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   BisonParser ::~ BisonParser  ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
   BisonParser ::by_state::by_state ()
    : state (empty_state)
  {}

   BisonParser ::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
   BisonParser ::by_state::clear ()
  {
    state = empty_state;
  }

  void
   BisonParser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   BisonParser ::by_state::by_state (state_type s)
    : state (s)
  {}

   BisonParser ::symbol_number_type
   BisonParser ::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

   BisonParser ::stack_symbol_type::stack_symbol_type ()
  {}

   BisonParser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 80: // column_def
        value.YY_MOVE_OR_COPY< cmd::ColumnDefinition > (YY_MOVE (that.value));
        break;

      case 101: // table_name
        value.YY_MOVE_OR_COPY< cmd::TableDefinition > (YY_MOVE (that.value));
        break;

      case 90: // update_clause
        value.YY_MOVE_OR_COPY< cmd::UpdateClause > (YY_MOVE (that.value));
        break;

      case 81: // column_type
        value.YY_MOVE_OR_COPY< cmd::column_type > (YY_MOVE (that.value));
        break;

      case 79: // column_def_commalist
        value.YY_MOVE_OR_COPY< std::list<cmd::ColumnDefinition> > (YY_MOVE (that.value));
        break;

      case 89: // update_list
        value.YY_MOVE_OR_COPY< std::list<cmd::UpdateClause> > (YY_MOVE (that.value));
        break;

      case 100: // column_name
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Column> > (YY_MOVE (that.value));
        break;

      case 91: // delete_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Delete> > (YY_MOVE (that.value));
        break;

      case 82: // drop_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::DropTable> > (YY_MOVE (that.value));
        break;

      case 85: // optional_where
      case 93: // expr
      case 94: // operand
      case 95: // unary_operator
      case 96: // binary_operator
      case 97: // logical_operator
      case 98: // scalar_expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Expression> > (YY_MOVE (that.value));
        break;

      case 86: // insert_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Insert> > (YY_MOVE (that.value));
        break;

      case 76: // statement
      case 77: // show_statement
      case 78: // create_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Instruction> > (YY_MOVE (that.value));
        break;

      case 99: // literal_value
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Literal> > (YY_MOVE (that.value));
        break;

      case 83: // select_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Select> > (YY_MOVE (that.value));
        break;

      case 88: // update_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Update> > (YY_MOVE (that.value));
        break;

      case 87: // optional_column_list
      case 104: // id_comma_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<std::list<cmd::Column>> > (YY_MOVE (that.value));
        break;

      case 103: // literal_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<std::list<cmd::Literal>> > (YY_MOVE (that.value));
        break;

      case 84: // select_list
      case 92: // expr_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (YY_MOVE (that.value));
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // INTEGER_CONST
      case 6: // DOUBLE_CONST
      case 7: // TRUE
      case 8: // FALSE
      case 9: // DOUBLE
      case 10: // TEXT
      case 11: // INTEGER
      case 12: // CREATE
      case 13: // TABLE
      case 14: // DROP
      case 15: // SHOW
      case 16: // NULL_
      case 17: // SELECT
      case 18: // VALUES
      case 19: // INTO
      case 20: // INSERT
      case 21: // FROM
      case 22: // UPDATE
      case 23: // SET
      case 24: // WHERE
      case 25: // LIMIT
      case 26: // OFFSET
      case 27: // DELETE
      case 28: // CAST
      case 29: // AS
      case 30: // ESCAPE
      case 31: // ISNULL
      case 32: // NOTNULL
      case 33: // BETWEEN
      case 34: // DISTINCT
      case 35: // EXISTS
      case 36: // WHEN
      case 37: // THEN
      case 38: // ELSE
      case 39: // NOT
      case 40: // COLLATE
      case 41: // IS
      case 42: // IN
      case 43: // LIKE
      case 44: // GLOB
      case 45: // MATCH
      case 46: // REGEXP
      case 47: // AND
      case 48: // OR
      case 49: // EQUAL
      case 50: // NOTEQUAL
      case 51: // LESSEQUAL
      case 52: // GREATERQUALL
      case 53: // LESS
      case 54: // GREATER
      case 55: // CONCATENATION
      case 56: // LEFTSHIFT
      case 57: // RIGHTSHIFT
      case 58: // BINNOT
      case 59: // BINAND
      case 60: // BINOR
      case 61: // PLUS
      case 62: // MINUS
      case 63: // MULTIPLY
      case 64: // DIVISION
      case 65: // MOD
      case 66: // SEMICOLON
      case 67: // DOT
      case 68: // COMMA
      case 69: // OPENBRACKET
      case 70: // CLOSEBRACKET
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if defined __cplusplus && 201103L <= __cplusplus
    // that is emptied.
    that.state = empty_state;
#endif
  }

   BisonParser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 80: // column_def
        value.move< cmd::ColumnDefinition > (YY_MOVE (that.value));
        break;

      case 101: // table_name
        value.move< cmd::TableDefinition > (YY_MOVE (that.value));
        break;

      case 90: // update_clause
        value.move< cmd::UpdateClause > (YY_MOVE (that.value));
        break;

      case 81: // column_type
        value.move< cmd::column_type > (YY_MOVE (that.value));
        break;

      case 79: // column_def_commalist
        value.move< std::list<cmd::ColumnDefinition> > (YY_MOVE (that.value));
        break;

      case 89: // update_list
        value.move< std::list<cmd::UpdateClause> > (YY_MOVE (that.value));
        break;

      case 100: // column_name
        value.move< std::shared_ptr<cmd::Column> > (YY_MOVE (that.value));
        break;

      case 91: // delete_statement
        value.move< std::shared_ptr<cmd::Delete> > (YY_MOVE (that.value));
        break;

      case 82: // drop_statement
        value.move< std::shared_ptr<cmd::DropTable> > (YY_MOVE (that.value));
        break;

      case 85: // optional_where
      case 93: // expr
      case 94: // operand
      case 95: // unary_operator
      case 96: // binary_operator
      case 97: // logical_operator
      case 98: // scalar_expr
        value.move< std::shared_ptr<cmd::Expression> > (YY_MOVE (that.value));
        break;

      case 86: // insert_statement
        value.move< std::shared_ptr<cmd::Insert> > (YY_MOVE (that.value));
        break;

      case 76: // statement
      case 77: // show_statement
      case 78: // create_statement
        value.move< std::shared_ptr<cmd::Instruction> > (YY_MOVE (that.value));
        break;

      case 99: // literal_value
        value.move< std::shared_ptr<cmd::Literal> > (YY_MOVE (that.value));
        break;

      case 83: // select_statement
        value.move< std::shared_ptr<cmd::Select> > (YY_MOVE (that.value));
        break;

      case 88: // update_statement
        value.move< std::shared_ptr<cmd::Update> > (YY_MOVE (that.value));
        break;

      case 87: // optional_column_list
      case 104: // id_comma_list
        value.move< std::shared_ptr<std::list<cmd::Column>> > (YY_MOVE (that.value));
        break;

      case 103: // literal_list
        value.move< std::shared_ptr<std::list<cmd::Literal>> > (YY_MOVE (that.value));
        break;

      case 84: // select_list
      case 92: // expr_list
        value.move< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (YY_MOVE (that.value));
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // INTEGER_CONST
      case 6: // DOUBLE_CONST
      case 7: // TRUE
      case 8: // FALSE
      case 9: // DOUBLE
      case 10: // TEXT
      case 11: // INTEGER
      case 12: // CREATE
      case 13: // TABLE
      case 14: // DROP
      case 15: // SHOW
      case 16: // NULL_
      case 17: // SELECT
      case 18: // VALUES
      case 19: // INTO
      case 20: // INSERT
      case 21: // FROM
      case 22: // UPDATE
      case 23: // SET
      case 24: // WHERE
      case 25: // LIMIT
      case 26: // OFFSET
      case 27: // DELETE
      case 28: // CAST
      case 29: // AS
      case 30: // ESCAPE
      case 31: // ISNULL
      case 32: // NOTNULL
      case 33: // BETWEEN
      case 34: // DISTINCT
      case 35: // EXISTS
      case 36: // WHEN
      case 37: // THEN
      case 38: // ELSE
      case 39: // NOT
      case 40: // COLLATE
      case 41: // IS
      case 42: // IN
      case 43: // LIKE
      case 44: // GLOB
      case 45: // MATCH
      case 46: // REGEXP
      case 47: // AND
      case 48: // OR
      case 49: // EQUAL
      case 50: // NOTEQUAL
      case 51: // LESSEQUAL
      case 52: // GREATERQUALL
      case 53: // LESS
      case 54: // GREATER
      case 55: // CONCATENATION
      case 56: // LEFTSHIFT
      case 57: // RIGHTSHIFT
      case 58: // BINNOT
      case 59: // BINAND
      case 60: // BINOR
      case 61: // PLUS
      case 62: // MINUS
      case 63: // MULTIPLY
      case 64: // DIVISION
      case 65: // MOD
      case 66: // SEMICOLON
      case 67: // DOT
      case 68: // COMMA
      case 69: // OPENBRACKET
      case 70: // CLOSEBRACKET
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if defined __cplusplus && __cplusplus < 201103L
   BisonParser ::stack_symbol_type&
   BisonParser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 80: // column_def
        value.move< cmd::ColumnDefinition > (that.value);
        break;

      case 101: // table_name
        value.move< cmd::TableDefinition > (that.value);
        break;

      case 90: // update_clause
        value.move< cmd::UpdateClause > (that.value);
        break;

      case 81: // column_type
        value.move< cmd::column_type > (that.value);
        break;

      case 79: // column_def_commalist
        value.move< std::list<cmd::ColumnDefinition> > (that.value);
        break;

      case 89: // update_list
        value.move< std::list<cmd::UpdateClause> > (that.value);
        break;

      case 100: // column_name
        value.move< std::shared_ptr<cmd::Column> > (that.value);
        break;

      case 91: // delete_statement
        value.move< std::shared_ptr<cmd::Delete> > (that.value);
        break;

      case 82: // drop_statement
        value.move< std::shared_ptr<cmd::DropTable> > (that.value);
        break;

      case 85: // optional_where
      case 93: // expr
      case 94: // operand
      case 95: // unary_operator
      case 96: // binary_operator
      case 97: // logical_operator
      case 98: // scalar_expr
        value.move< std::shared_ptr<cmd::Expression> > (that.value);
        break;

      case 86: // insert_statement
        value.move< std::shared_ptr<cmd::Insert> > (that.value);
        break;

      case 76: // statement
      case 77: // show_statement
      case 78: // create_statement
        value.move< std::shared_ptr<cmd::Instruction> > (that.value);
        break;

      case 99: // literal_value
        value.move< std::shared_ptr<cmd::Literal> > (that.value);
        break;

      case 83: // select_statement
        value.move< std::shared_ptr<cmd::Select> > (that.value);
        break;

      case 88: // update_statement
        value.move< std::shared_ptr<cmd::Update> > (that.value);
        break;

      case 87: // optional_column_list
      case 104: // id_comma_list
        value.move< std::shared_ptr<std::list<cmd::Column>> > (that.value);
        break;

      case 103: // literal_list
        value.move< std::shared_ptr<std::list<cmd::Literal>> > (that.value);
        break;

      case 84: // select_list
      case 92: // expr_list
        value.move< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (that.value);
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // INTEGER_CONST
      case 6: // DOUBLE_CONST
      case 7: // TRUE
      case 8: // FALSE
      case 9: // DOUBLE
      case 10: // TEXT
      case 11: // INTEGER
      case 12: // CREATE
      case 13: // TABLE
      case 14: // DROP
      case 15: // SHOW
      case 16: // NULL_
      case 17: // SELECT
      case 18: // VALUES
      case 19: // INTO
      case 20: // INSERT
      case 21: // FROM
      case 22: // UPDATE
      case 23: // SET
      case 24: // WHERE
      case 25: // LIMIT
      case 26: // OFFSET
      case 27: // DELETE
      case 28: // CAST
      case 29: // AS
      case 30: // ESCAPE
      case 31: // ISNULL
      case 32: // NOTNULL
      case 33: // BETWEEN
      case 34: // DISTINCT
      case 35: // EXISTS
      case 36: // WHEN
      case 37: // THEN
      case 38: // ELSE
      case 39: // NOT
      case 40: // COLLATE
      case 41: // IS
      case 42: // IN
      case 43: // LIKE
      case 44: // GLOB
      case 45: // MATCH
      case 46: // REGEXP
      case 47: // AND
      case 48: // OR
      case 49: // EQUAL
      case 50: // NOTEQUAL
      case 51: // LESSEQUAL
      case 52: // GREATERQUALL
      case 53: // LESS
      case 54: // GREATER
      case 55: // CONCATENATION
      case 56: // LEFTSHIFT
      case 57: // RIGHTSHIFT
      case 58: // BINNOT
      case 59: // BINAND
      case 60: // BINOR
      case 61: // PLUS
      case 62: // MINUS
      case 63: // MULTIPLY
      case 64: // DIVISION
      case 65: // MOD
      case 66: // SEMICOLON
      case 67: // DOT
      case 68: // COMMA
      case 69: // OPENBRACKET
      case 70: // CLOSEBRACKET
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   BisonParser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   BisonParser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
   BisonParser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   BisonParser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if defined __cplusplus && 201103L <= __cplusplus
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   BisonParser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   BisonParser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   BisonParser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   BisonParser ::debug_level_type
   BisonParser ::debug_level () const
  {
    return yydebug_;
  }

  void
   BisonParser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   BisonParser ::state_type
   BisonParser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
   BisonParser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   BisonParser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   BisonParser ::operator() ()
  {
    return parse ();
  }

  int
   BisonParser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 80: // column_def
        yylhs.value.emplace< cmd::ColumnDefinition > ();
        break;

      case 101: // table_name
        yylhs.value.emplace< cmd::TableDefinition > ();
        break;

      case 90: // update_clause
        yylhs.value.emplace< cmd::UpdateClause > ();
        break;

      case 81: // column_type
        yylhs.value.emplace< cmd::column_type > ();
        break;

      case 79: // column_def_commalist
        yylhs.value.emplace< std::list<cmd::ColumnDefinition> > ();
        break;

      case 89: // update_list
        yylhs.value.emplace< std::list<cmd::UpdateClause> > ();
        break;

      case 100: // column_name
        yylhs.value.emplace< std::shared_ptr<cmd::Column> > ();
        break;

      case 91: // delete_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Delete> > ();
        break;

      case 82: // drop_statement
        yylhs.value.emplace< std::shared_ptr<cmd::DropTable> > ();
        break;

      case 85: // optional_where
      case 93: // expr
      case 94: // operand
      case 95: // unary_operator
      case 96: // binary_operator
      case 97: // logical_operator
      case 98: // scalar_expr
        yylhs.value.emplace< std::shared_ptr<cmd::Expression> > ();
        break;

      case 86: // insert_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Insert> > ();
        break;

      case 76: // statement
      case 77: // show_statement
      case 78: // create_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Instruction> > ();
        break;

      case 99: // literal_value
        yylhs.value.emplace< std::shared_ptr<cmd::Literal> > ();
        break;

      case 83: // select_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Select> > ();
        break;

      case 88: // update_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Update> > ();
        break;

      case 87: // optional_column_list
      case 104: // id_comma_list
        yylhs.value.emplace< std::shared_ptr<std::list<cmd::Column>> > ();
        break;

      case 103: // literal_list
        yylhs.value.emplace< std::shared_ptr<std::list<cmd::Literal>> > ();
        break;

      case 84: // select_list
      case 92: // expr_list
        yylhs.value.emplace< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ();
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // INTEGER_CONST
      case 6: // DOUBLE_CONST
      case 7: // TRUE
      case 8: // FALSE
      case 9: // DOUBLE
      case 10: // TEXT
      case 11: // INTEGER
      case 12: // CREATE
      case 13: // TABLE
      case 14: // DROP
      case 15: // SHOW
      case 16: // NULL_
      case 17: // SELECT
      case 18: // VALUES
      case 19: // INTO
      case 20: // INSERT
      case 21: // FROM
      case 22: // UPDATE
      case 23: // SET
      case 24: // WHERE
      case 25: // LIMIT
      case 26: // OFFSET
      case 27: // DELETE
      case 28: // CAST
      case 29: // AS
      case 30: // ESCAPE
      case 31: // ISNULL
      case 32: // NOTNULL
      case 33: // BETWEEN
      case 34: // DISTINCT
      case 35: // EXISTS
      case 36: // WHEN
      case 37: // THEN
      case 38: // ELSE
      case 39: // NOT
      case 40: // COLLATE
      case 41: // IS
      case 42: // IN
      case 43: // LIKE
      case 44: // GLOB
      case 45: // MATCH
      case 46: // REGEXP
      case 47: // AND
      case 48: // OR
      case 49: // EQUAL
      case 50: // NOTEQUAL
      case 51: // LESSEQUAL
      case 52: // GREATERQUALL
      case 53: // LESS
      case 54: // GREATER
      case 55: // CONCATENATION
      case 56: // LEFTSHIFT
      case 57: // RIGHTSHIFT
      case 58: // BINNOT
      case 59: // BINAND
      case 60: // BINOR
      case 61: // PLUS
      case 62: // MINUS
      case 63: // MULTIPLY
      case 64: // DIVISION
      case 65: // MOD
      case 66: // SEMICOLON
      case 67: // DOT
      case 68: // COMMA
      case 69: // OPENBRACKET
      case 70: // CLOSEBRACKET
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3:
#line 98 "bison_sql.ypp" // lalr1.cc:906
    {
            driver.AddInstruction(yystack_[0].value.as< std::shared_ptr<cmd::Instruction> > ());
        }
#line 1126 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 4:
#line 102 "bison_sql.ypp" // lalr1.cc:906
    {
            driver.AddInstruction(yystack_[0].value.as< std::shared_ptr<cmd::Instruction> > ());
        }
#line 1134 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 5:
#line 109 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = yystack_[0].value.as< std::shared_ptr<cmd::DropTable> > (); }
#line 1140 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 6:
#line 110 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = yystack_[0].value.as< std::shared_ptr<cmd::Instruction> > (); }
#line 1146 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 7:
#line 111 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = yystack_[0].value.as< std::shared_ptr<cmd::Instruction> > (); }
#line 1152 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 8:
#line 112 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = yystack_[0].value.as< std::shared_ptr<cmd::Select> > (); }
#line 1158 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 9:
#line 113 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = yystack_[0].value.as< std::shared_ptr<cmd::Insert> > (); }
#line 1164 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 10:
#line 114 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = yystack_[0].value.as< std::shared_ptr<cmd::Update> > (); }
#line 1170 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 11:
#line 115 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = yystack_[0].value.as< std::shared_ptr<cmd::Delete> > (); }
#line 1176 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 12:
#line 123 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = std::make_shared<cmd::ShowCreateTable>(yystack_[0].value.as< cmd::TableDefinition > ());
            yylhs.value.as< std::shared_ptr<cmd::Instruction> > ()->SetRaw(yystack_[2].value.as< std::string > () + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< cmd::TableDefinition > ().GetRaw());
        }
#line 1185 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 13:
#line 133 "bison_sql.ypp" // lalr1.cc:906
    {
            std::string raw = yystack_[5].value.as< std::string > () + " " + yystack_[4].value.as< std::string > () + " " + yystack_[3].value.as< cmd::TableDefinition > ().GetRaw() + " " + yystack_[2].value.as< std::string > ();
            for (auto& e : yystack_[1].value.as< std::list<cmd::ColumnDefinition> > ()) {
                raw += e.GetRaw() + ", ";
            }
            raw.pop_back();
            raw.pop_back();
            yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = std::make_shared<cmd::CreateTable>(yystack_[3].value.as< cmd::TableDefinition > (), yystack_[1].value.as< std::list<cmd::ColumnDefinition> > ());
            raw += yystack_[0].value.as< std::string > ();
            yylhs.value.as< std::shared_ptr<cmd::Instruction> > ()->SetRaw(raw);
        }
#line 1201 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 14:
#line 149 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::list<cmd::ColumnDefinition> > () = std::list<cmd::ColumnDefinition>({std::move(yystack_[0].value.as< cmd::ColumnDefinition > ())});
        }
#line 1209 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 15:
#line 153 "bison_sql.ypp" // lalr1.cc:906
    {
            yystack_[2].value.as< std::list<cmd::ColumnDefinition> > ().push_back(yystack_[0].value.as< cmd::ColumnDefinition > ());
            yylhs.value.as< std::list<cmd::ColumnDefinition> > () = std::move(yystack_[2].value.as< std::list<cmd::ColumnDefinition> > ());
        }
#line 1218 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 16:
#line 162 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< cmd::ColumnDefinition > () = cmd::ColumnDefinition(yystack_[1].value.as< std::string > (), yystack_[0].value.as< cmd::column_type > ().first);
            yylhs.value.as< cmd::ColumnDefinition > ().SetRaw(yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< cmd::column_type > ().second);
        }
#line 1227 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 17:
#line 170 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< cmd::column_type > () = std::make_pair(cmd::LiteralType::INTEGER, yystack_[0].value.as< std::string > ()); }
#line 1233 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 18:
#line 171 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< cmd::column_type > () = std::make_pair(cmd::LiteralType::DOUBLE, yystack_[0].value.as< std::string > ()); }
#line 1239 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 19:
#line 172 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< cmd::column_type > () = std::make_pair(cmd::LiteralType::TEXT, yystack_[0].value.as< std::string > ()); }
#line 1245 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 20:
#line 179 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::shared_ptr<cmd::DropTable> > () = std::make_shared<cmd::DropTable>(yystack_[0].value.as< cmd::TableDefinition > ());
            yylhs.value.as< std::shared_ptr<cmd::DropTable> > ()->SetRaw(yystack_[2].value.as< std::string > () + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< cmd::TableDefinition > ().GetRaw());
        }
#line 1254 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 21:
#line 189 "bison_sql.ypp" // lalr1.cc:906
    {
            std::string raw = yystack_[4].value.as< std::string > () + " ";
            if (yystack_[3].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () == nullptr) {
                raw += "*";
            } else {
                for (auto& e : *(yystack_[3].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ())) {
                    raw += e->GetRaw() + ", ";
                }
                raw.pop_back();
                raw.pop_back();
            }
            raw += " " + yystack_[2].value.as< std::string > () + " " + yystack_[1].value.as< cmd::TableDefinition > ().GetRaw() + " ";
            if (yystack_[3].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () == nullptr) {
                yylhs.value.as< std::shared_ptr<cmd::Select> > () = std::make_shared<cmd::Select>(yystack_[1].value.as< cmd::TableDefinition > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            } else {
                yylhs.value.as< std::shared_ptr<cmd::Select> > () = std::make_shared<cmd::Select>(yystack_[1].value.as< cmd::TableDefinition > (), *(yystack_[3].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ()), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            }
            if (yystack_[0].value.as< std::shared_ptr<cmd::Expression> > () != nullptr) { raw += " where " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw(); }
            yylhs.value.as< std::shared_ptr<cmd::Select> > ()->SetRaw(raw);
        }
#line 1279 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 22:
#line 213 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () = nullptr; }
#line 1285 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 23:
#line 214 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () = yystack_[0].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (); }
#line 1291 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 24:
#line 220 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1297 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 25:
#line 221 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = nullptr; }
#line 1303 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 26:
#line 229 "bison_sql.ypp" // lalr1.cc:906
    {
            std::string raw = yystack_[7].value.as< std::string > () + " " + yystack_[6].value.as< std::string > () + " " + yystack_[5].value.as< cmd::TableDefinition > ().GetRaw();

            if (yystack_[4].value.as< std::shared_ptr<std::list<cmd::Column>> > () == nullptr) {
                yylhs.value.as< std::shared_ptr<cmd::Insert> > () = std::make_shared<cmd::Insert>(yystack_[5].value.as< cmd::TableDefinition > (), *(yystack_[1].value.as< std::shared_ptr<std::list<cmd::Literal>> > ()));
            } else {
                yylhs.value.as< std::shared_ptr<cmd::Insert> > () = std::make_shared<cmd::Insert>(yystack_[5].value.as< cmd::TableDefinition > (), *(yystack_[1].value.as< std::shared_ptr<std::list<cmd::Literal>> > ()), *(yystack_[4].value.as< std::shared_ptr<std::list<cmd::Column>> > ()));
                raw += " ";
                for (auto& e : *(yystack_[4].value.as< std::shared_ptr<std::list<cmd::Column>> > ())) {
                    raw += e.GetRaw() + ", ";
                }
                raw.pop_back();
                raw.pop_back();
            }
            raw += " " + yystack_[3].value.as< std::string > () + " " + yystack_[2].value.as< std::string > ();
            for (auto& e : *(yystack_[1].value.as< std::shared_ptr<std::list<cmd::Literal>> > ())) {
                raw += e.GetRaw() + ", ";
            }
            raw.pop_back();
            raw.pop_back();
            raw +=  yystack_[0].value.as< std::string > ();
            yylhs.value.as< std::shared_ptr<cmd::Insert> > ()->SetRaw(raw);
        }
#line 1331 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 27:
#line 257 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > () = yystack_[0].value.as< std::shared_ptr<std::list<cmd::Column>> > (); }
#line 1337 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 28:
#line 258 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > () = nullptr; }
#line 1343 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 29:
#line 264 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::shared_ptr<cmd::Update> > () = std::make_shared<cmd::Update>(yystack_[3].value.as< cmd::TableDefinition > (), yystack_[1].value.as< std::list<cmd::UpdateClause> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            
            std::string raw = yystack_[4].value.as< std::string > () + " " + yystack_[3].value.as< cmd::TableDefinition > ().GetRaw() + " " + yystack_[2].value.as< std::string > ();
            for (auto& e : yystack_[1].value.as< std::list<cmd::UpdateClause> > ()) {
                raw += e.raw + ", ";
            }
            raw.pop_back();
            raw.pop_back();
            if (yystack_[0].value.as< std::shared_ptr<cmd::Expression> > () != nullptr) {
                raw += " where " +  yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw();
            }
            yylhs.value.as< std::shared_ptr<cmd::Update> > ()->SetRaw(raw);
        }
#line 1362 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 30:
#line 283 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::list<cmd::UpdateClause> > ().push_back(yystack_[0].value.as< cmd::UpdateClause > ());
        }
#line 1370 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 31:
#line 287 "bison_sql.ypp" // lalr1.cc:906
    {
            yystack_[2].value.as< std::list<cmd::UpdateClause> > ().push_back(yystack_[0].value.as< cmd::UpdateClause > ());
            yylhs.value.as< std::list<cmd::UpdateClause> > () = std::move(yystack_[2].value.as< std::list<cmd::UpdateClause> > ());
        }
#line 1379 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 32:
#line 296 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< cmd::UpdateClause > () = cmd::UpdateClause(cmd::Column(yystack_[2].value.as< std::string > ()), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[2].value.as< std::string > () + yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1387 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 33:
#line 305 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::shared_ptr<cmd::Delete> > () = std::make_shared<cmd::Delete>(yystack_[1].value.as< cmd::TableDefinition > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Delete> > ()->SetRaw(yystack_[3].value.as< std::string > () + " " + yystack_[2].value.as< std::string > () + " " + yystack_[1].value.as< cmd::TableDefinition > ().GetRaw() + (yystack_[0].value.as< std::shared_ptr<cmd::Expression> > () == nullptr ? "" : " where " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw()));
        }
#line 1396 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 34:
#line 315 "bison_sql.ypp" // lalr1.cc:906
    {  
            yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () = std::make_shared<std::list<std::shared_ptr<cmd::Expression>>>();
            yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ()->push_back(yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
        }
#line 1405 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 35:
#line 320 "bison_sql.ypp" // lalr1.cc:906
    {
            yystack_[2].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ()->push_back(yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () = yystack_[2].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ();
        }
#line 1414 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 36:
#line 328 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1420 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 37:
#line 329 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1426 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 38:
#line 334 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[1].value.as< std::shared_ptr<cmd::Expression> > ();
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::string > () + yystack_[1].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + yystack_[0].value.as< std::string > ());
        }
#line 1435 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 39:
#line 338 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1441 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 40:
#line 339 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1447 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 41:
#line 340 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1453 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 42:
#line 346 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::UNARY_MINUS, yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1462 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 43:
#line 351 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::UNARY_PLUS, yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1471 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 44:
#line 356 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::BIN_NOT, yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1480 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 45:
#line 361 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::NOT, yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1489 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 46:
#line 366 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::ISNULL, yystack_[1].value.as< std::shared_ptr<cmd::Expression> > ()); 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[1].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + yystack_[0].value.as< std::string > ());
        }
#line 1498 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 47:
#line 371 "bison_sql.ypp" // lalr1.cc:906
    {
            auto nodeIsNull = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::ISNULL, yystack_[1].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::NOT, nodeIsNull);
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[1].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + yystack_[0].value.as< std::string > ());
        }
#line 1508 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 48:
#line 381 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::LESS, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1517 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 49:
#line 386 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::GREATER, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1526 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 50:
#line 391 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::EQUAL, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());

        }
#line 1536 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 51:
#line 397 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::NOT_EQUAL, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1545 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 52:
#line 402 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::LESS_EQUAL, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1554 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 53:
#line 407 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::GREATER_EQUAL, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1563 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 54:
#line 412 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::PLUS, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1572 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 55:
#line 417 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::MINUS, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1581 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 56:
#line 422 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::MULTIPLY, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1590 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 57:
#line 427 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::DIVISION, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1599 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 58:
#line 432 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::MOD, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1608 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 59:
#line 437 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::CONCATENATION, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1617 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 60:
#line 446 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::AND, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1626 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 61:
#line 451 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::OR, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > ()->SetRaw(yystack_[2].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw() + " " + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()->GetRaw());
        }
#line 1635 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 62:
#line 459 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Literal> > (); }
#line 1641 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 63:
#line 460 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Column> > (); }
#line 1647 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 64:
#line 466 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(std::stoll(yystack_[0].value.as< std::string > ()));
            yylhs.value.as< std::shared_ptr<cmd::Literal> > ()->SetRaw(yystack_[0].value.as< std::string > ());

        }
#line 1657 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 65:
#line 472 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(std::stold(yystack_[0].value.as< std::string > ()));
            yylhs.value.as< std::shared_ptr<cmd::Literal> > ()->SetRaw(yystack_[0].value.as< std::string > ());
        }
#line 1666 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 66:
#line 477 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(yystack_[0].value.as< std::string > ());
            yylhs.value.as< std::shared_ptr<cmd::Literal> > ()->SetRaw("'" + yystack_[0].value.as< std::string > () + "'");
        }
#line 1675 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 67:
#line 482 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>();
            yylhs.value.as< std::shared_ptr<cmd::Literal> > ()->SetRaw(yystack_[0].value.as< std::string > ());
        }
#line 1684 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 68:
#line 487 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(true);
            yylhs.value.as< std::shared_ptr<cmd::Literal> > ()->SetRaw(yystack_[0].value.as< std::string > ());
        }
#line 1693 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 69:
#line 492 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(false);
            yylhs.value.as< std::shared_ptr<cmd::Literal> > ()->SetRaw(yystack_[0].value.as< std::string > ());
        }
#line 1702 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 70:
#line 501 "bison_sql.ypp" // lalr1.cc:906
    {        
            yylhs.value.as< std::shared_ptr<cmd::Column> > () = std::make_shared<cmd::Column>(yystack_[0].value.as< std::string > ());
            yylhs.value.as< std::shared_ptr<cmd::Column> > ()->SetRaw(yystack_[0].value.as< std::string > ());
        }
#line 1711 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 71:
#line 506 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Column> > () = std::make_shared<cmd::Column>(yystack_[0].value.as< std::string > (), yystack_[2].value.as< std::string > ());
            yylhs.value.as< std::shared_ptr<cmd::Column> > ()->SetRaw(yystack_[2].value.as< std::string > () + yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::string > ()); 
        }
#line 1720 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 72:
#line 511 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Column> > () = std::make_shared<cmd::Column>(yystack_[0].value.as< std::string > (), yystack_[2].value.as< std::string > (), yystack_[4].value.as< std::string > ());
            yylhs.value.as< std::shared_ptr<cmd::Column> > ()->SetRaw(yystack_[4].value.as< std::string > () + yystack_[3].value.as< std::string > () + yystack_[2].value.as< std::string > () + yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::string > ());
        }
#line 1729 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 73:
#line 521 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< cmd::TableDefinition > () = cmd::TableDefinition(yystack_[0].value.as< std::string > ());
            yylhs.value.as< cmd::TableDefinition > ().SetRaw(yystack_[0].value.as< std::string > ());
        }
#line 1738 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 74:
#line 526 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< cmd::TableDefinition > () = cmd::TableDefinition(yystack_[0].value.as< std::string > (), yystack_[2].value.as< std::string > ());
            yylhs.value.as< cmd::TableDefinition > ().SetRaw(yystack_[2].value.as< std::string > () + yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::string > ());
        }
#line 1747 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 77:
#line 542 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::shared_ptr<std::list<cmd::Literal>> > () = std::make_shared<std::list<cmd::Literal>>();
            yylhs.value.as< std::shared_ptr<std::list<cmd::Literal>> > ()->push_back(*(yystack_[0].value.as< std::shared_ptr<cmd::Literal> > ()));
        }
#line 1756 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 78:
#line 547 "bison_sql.ypp" // lalr1.cc:906
    {
            yystack_[2].value.as< std::shared_ptr<std::list<cmd::Literal>> > ()->push_back(*(yystack_[0].value.as< std::shared_ptr<cmd::Literal> > ()));
            yylhs.value.as< std::shared_ptr<std::list<cmd::Literal>> > () = yystack_[2].value.as< std::shared_ptr<std::list<cmd::Literal>> > ();
        }
#line 1765 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 79:
#line 556 "bison_sql.ypp" // lalr1.cc:906
    {   
            yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > () = std::make_shared<std::list<cmd::Column>>();
            yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > ()->push_back(cmd::Column(yystack_[0].value.as< std::string > ())); 
            yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > ()->back().SetRaw(yystack_[0].value.as< std::string > ());
        }
#line 1775 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 80:
#line 562 "bison_sql.ypp" // lalr1.cc:906
    {         
            yystack_[2].value.as< std::shared_ptr<std::list<cmd::Column>> > ()->push_back(cmd::Column(yystack_[0].value.as< std::string > ()));
            yystack_[2].value.as< std::shared_ptr<std::list<cmd::Column>> > ()->back().SetRaw(yystack_[0].value.as< std::string > ());
            yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > () = yystack_[2].value.as< std::shared_ptr<std::list<cmd::Column>> > ();
        }
#line 1785 "bison_sql.cpp" // lalr1.cc:906
    break;


#line 1789 "bison_sql.cpp" // lalr1.cc:906
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   BisonParser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
   BisonParser ::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char  BisonParser ::yypact_ninf_ = -110;

  const signed char  BisonParser ::yytable_ninf_ = -1;

  const short
   BisonParser ::yypact_[] =
  {
     138,    22,    39,    40,    -2,    35,    52,    36,    74,    13,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,    52,    52,
      52,     8,  -110,  -110,  -110,  -110,  -110,  -110,     4,     4,
       4,     4,  -110,     4,    43,    10,    -1,    50,  -110,  -110,
    -110,  -110,  -110,  -110,    52,     9,    60,    52,  -110,  -110,
     138,  -110,    15,  -110,  -110,    82,    67,  -110,  -110,  -110,
     -25,    52,     4,     4,     4,  -110,  -110,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,   103,
     104,   105,    85,  -110,   107,    56,  -110,    85,    -1,  -110,
      77,    84,    84,   115,   115,   115,   115,  -110,   -31,   -31,
      70,    70,    70,  -110,   108,    59,  -110,    91,    -5,  -110,
       4,  -110,    16,   -32,  -110,   139,  -110,    72,   140,     4,
     105,  -110,    -1,  -110,  -110,  -110,  -110,   107,  -110,  -110,
      64,  -110,    -1,  -110,  -110,  -110,   -28,    64,  -110,  -110
  };

  const unsigned char
   BisonParser ::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     6,     7,     5,     8,     9,    10,    11,     0,     0,
       0,    70,    66,    64,    65,    68,    69,    67,     0,     0,
       0,     0,    22,     0,     0,    23,    34,    36,    41,    39,
      37,    40,    62,    63,     0,    73,     0,     0,     1,    76,
      75,     2,     0,    20,    12,     0,    45,    44,    43,    42,
       0,     0,     0,     0,     0,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,    25,     4,     0,    71,    38,    25,    35,    60,
      61,    50,    51,    52,    53,    48,    49,    59,    54,    55,
      56,    57,    58,    79,     0,    27,    74,     0,    25,    30,
       0,    33,     0,     0,    14,     0,    21,     0,     0,     0,
       0,    29,    24,    18,    19,    17,    16,     0,    13,    72,
       0,    80,    32,    31,    15,    77,     0,     0,    26,    78
  };

  const signed char
   BisonParser ::yypgoto_[] =
  {
    -110,  -110,  -110,    94,  -110,  -110,  -110,    24,  -110,  -110,
    -110,  -110,   -69,  -110,  -110,  -110,  -110,    34,  -110,  -110,
     -33,    20,  -110,  -110,  -110,  -110,  -109,  -110,    -3,  -110,
    -110,  -110
  };

  const short
   BisonParser ::yydefgoto_[] =
  {
      -1,     8,     9,    10,    11,    12,   113,   114,   126,    13,
      14,    34,   111,    15,   104,    16,   108,   109,    17,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    46,    51,
     136,   105
  };

  const short
   BisonParser ::yytable_[] =
  {
      60,    21,    22,    23,    24,    25,    26,    21,    22,    23,
      24,    25,    26,    49,    27,    52,    53,    54,   116,   110,
      27,   135,    63,    64,    73,   123,   124,   125,   139,    88,
      89,    90,    76,    77,    78,    18,   127,    28,   128,   121,
     137,    79,   138,    28,    82,    86,    63,    64,    56,    57,
      58,    59,    19,    20,    44,    45,    29,    47,    87,    30,
      31,    32,    29,   120,    61,    30,    31,    33,    22,    23,
      24,    25,    26,    33,    48,    55,    80,   122,    62,    50,
      27,    65,    66,    81,    84,    85,   132,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    67,
      68,    69,    70,    71,    72,    73,   103,   106,   107,   110,
     112,    74,    75,    76,    77,    78,    67,    68,    69,    70,
      71,    72,    73,   115,    63,    73,   117,   118,    74,    75,
      76,    77,    78,    -1,    -1,    69,    70,    71,    72,    73,
     119,   130,   129,   131,    83,    74,    75,    76,    77,    78,
       1,   134,     2,     3,   133,     4,     0,     0,     5,     0,
       6,     0,     0,     0,     0,     7,    -1,    -1,    -1,    -1,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78
  };

  const short
   BisonParser ::yycheck_[] =
  {
      33,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,     0,    16,    18,    19,    20,    87,    24,
      16,   130,    47,    48,    55,     9,    10,    11,   137,    62,
      63,    64,    63,    64,    65,    13,    68,    39,    70,   108,
      68,    44,    70,    39,    47,    70,    47,    48,    28,    29,
      30,    31,    13,    13,    19,     3,    58,    21,    61,    61,
      62,    63,    58,    68,    21,    61,    62,    69,     4,     5,
       6,     7,     8,    69,     0,    67,    67,   110,    68,    66,
      16,    31,    32,    23,    69,     3,   119,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    49,
      50,    51,    52,    53,    54,    55,     3,     3,     3,    24,
       3,    61,    62,    63,    64,    65,    49,    50,    51,    52,
      53,    54,    55,    67,    47,    55,    18,    68,    61,    62,
      63,    64,    65,    49,    50,    51,    52,    53,    54,    55,
      49,    69,     3,     3,    50,    61,    62,    63,    64,    65,
      12,   127,    14,    15,   120,    17,    -1,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    27,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65
  };

  const unsigned char
   BisonParser ::yystos_[] =
  {
       0,    12,    14,    15,    17,    20,    22,    27,    74,    75,
      76,    77,    78,    82,    83,    86,    88,    91,    13,    13,
      13,     3,     4,     5,     6,     7,     8,    16,    39,    58,
      61,    62,    63,    69,    84,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    19,     3,   101,    21,     0,     0,
      66,   102,   101,   101,   101,    67,    94,    94,    94,    94,
      93,    21,    68,    47,    48,    31,    32,    49,    50,    51,
      52,    53,    54,    55,    61,    62,    63,    64,    65,   101,
      67,    23,   101,    76,    69,     3,    70,   101,    93,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,     3,    87,   104,     3,     3,    89,    90,
      24,    85,     3,    79,    80,    67,    85,    18,    68,    49,
      68,    85,    93,     9,    10,    11,    81,    68,    70,     3,
      69,     3,    93,    90,    80,    99,   103,    68,    70,    99
  };

  const unsigned char
   BisonParser ::yyr1_[] =
  {
       0,    73,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    79,    80,    81,    81,    81,
      82,    83,    84,    84,    85,    85,    86,    87,    87,    88,
      89,    89,    90,    91,    92,    92,    93,    93,    94,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104
  };

  const unsigned char
   BisonParser ::yyr2_[] =
  {
       0,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     6,     1,     3,     2,     1,     1,     1,
       3,     5,     1,     1,     2,     0,     8,     1,     0,     5,
       1,     3,     3,     4,     1,     3,     1,     1,     3,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     1,     3,     1,     1,     1,     3,     1,
       3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  BisonParser ::yytname_[] =
  {
  "END_FILE", "error", "$undefined", "IDENTIFIER", "STRING",
  "INTEGER_CONST", "DOUBLE_CONST", "TRUE", "FALSE", "DOUBLE", "TEXT",
  "INTEGER", "CREATE", "TABLE", "DROP", "SHOW", "NULL_", "SELECT",
  "VALUES", "INTO", "INSERT", "FROM", "UPDATE", "SET", "WHERE", "LIMIT",
  "OFFSET", "DELETE", "CAST", "AS", "ESCAPE", "ISNULL", "NOTNULL",
  "BETWEEN", "DISTINCT", "EXISTS", "WHEN", "THEN", "ELSE", "NOT",
  "COLLATE", "IS", "IN", "LIKE", "GLOB", "MATCH", "REGEXP", "AND", "OR",
  "EQUAL", "NOTEQUAL", "LESSEQUAL", "GREATERQUALL", "LESS", "GREATER",
  "CONCATENATION", "LEFTSHIFT", "RIGHTSHIFT", "BINNOT", "BINAND", "BINOR",
  "PLUS", "MINUS", "MULTIPLY", "DIVISION", "MOD", "SEMICOLON", "DOT",
  "COMMA", "OPENBRACKET", "CLOSEBRACKET", "UMINUS", "UPLUS", "$accept",
  "input", "sql_stmt_list", "statement", "show_statement",
  "create_statement", "column_def_commalist", "column_def", "column_type",
  "drop_statement", "select_statement", "select_list", "optional_where",
  "insert_statement", "optional_column_list", "update_statement",
  "update_list", "update_clause", "delete_statement", "expr_list", "expr",
  "operand", "unary_operator", "binary_operator", "logical_operator",
  "scalar_expr", "literal_value", "column_name", "table_name",
  "opt_semicolon", "literal_list", "id_comma_list", YY_NULLPTR
  };


  const unsigned short
   BisonParser ::yyrline_[] =
  {
       0,    93,    93,    97,   101,   109,   110,   111,   112,   113,
     114,   115,   122,   132,   148,   152,   161,   170,   171,   172,
     178,   188,   213,   214,   220,   221,   228,   257,   258,   264,
     282,   286,   295,   304,   314,   319,   328,   329,   334,   338,
     339,   340,   345,   350,   355,   360,   365,   370,   380,   385,
     390,   396,   401,   406,   411,   416,   421,   426,   431,   436,
     445,   450,   459,   460,   465,   471,   476,   481,   486,   491,
     500,   505,   510,   520,   525,   535,   536,   541,   546,   555,
     561
  };

  // Print the state stack on the debug stream.
  void
   BisonParser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   BisonParser ::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 2187 "bison_sql.cpp" // lalr1.cc:1217
