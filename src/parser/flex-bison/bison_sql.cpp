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
      case 7: // TRUE
      case 8: // FALSE
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 81: // column_def
        value.YY_MOVE_OR_COPY< cmd::ColumnDefinition > (YY_MOVE (that.value));
        break;

      case 82: // column_type
        value.YY_MOVE_OR_COPY< cmd::LiteralType > (YY_MOVE (that.value));
        break;

      case 102: // table_name
        value.YY_MOVE_OR_COPY< cmd::TableDefinition > (YY_MOVE (that.value));
        break;

      case 91: // update_clause
        value.YY_MOVE_OR_COPY< cmd::update_clause > (YY_MOVE (that.value));
        break;

      case 9: // DOUBLE_CONST
        value.YY_MOVE_OR_COPY< long double > (YY_MOVE (that.value));
        break;

      case 6: // INTEGER_CONST
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case 80: // column_def_commalist
        value.YY_MOVE_OR_COPY< std::list<cmd::ColumnDefinition> > (YY_MOVE (that.value));
        break;

      case 90: // update_list
        value.YY_MOVE_OR_COPY< std::list<cmd::update_clause> > (YY_MOVE (that.value));
        break;

      case 101: // column_name
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Column> > (YY_MOVE (that.value));
        break;

      case 92: // delete_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Delete> > (YY_MOVE (that.value));
        break;

      case 83: // drop_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::DropTable> > (YY_MOVE (that.value));
        break;

      case 86: // optional_where
      case 94: // expr
      case 95: // operand
      case 96: // unary_operator
      case 97: // binary_operator
      case 98: // logical_operator
      case 99: // scalar_expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Expression> > (YY_MOVE (that.value));
        break;

      case 87: // insert_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Insert> > (YY_MOVE (that.value));
        break;

      case 77: // statement
      case 78: // show_statement
      case 79: // create_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Instruction> > (YY_MOVE (that.value));
        break;

      case 100: // literal_value
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Literal> > (YY_MOVE (that.value));
        break;

      case 84: // select_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Select> > (YY_MOVE (that.value));
        break;

      case 89: // update_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Update> > (YY_MOVE (that.value));
        break;

      case 88: // optional_column_list
      case 105: // id_comma_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<std::list<cmd::Column>> > (YY_MOVE (that.value));
        break;

      case 104: // literal_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<std::list<cmd::Literal>> > (YY_MOVE (that.value));
        break;

      case 85: // select_list
      case 93: // expr_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (YY_MOVE (that.value));
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // BLOB_STRING
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
      case 7: // TRUE
      case 8: // FALSE
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 81: // column_def
        value.move< cmd::ColumnDefinition > (YY_MOVE (that.value));
        break;

      case 82: // column_type
        value.move< cmd::LiteralType > (YY_MOVE (that.value));
        break;

      case 102: // table_name
        value.move< cmd::TableDefinition > (YY_MOVE (that.value));
        break;

      case 91: // update_clause
        value.move< cmd::update_clause > (YY_MOVE (that.value));
        break;

      case 9: // DOUBLE_CONST
        value.move< long double > (YY_MOVE (that.value));
        break;

      case 6: // INTEGER_CONST
        value.move< long long > (YY_MOVE (that.value));
        break;

      case 80: // column_def_commalist
        value.move< std::list<cmd::ColumnDefinition> > (YY_MOVE (that.value));
        break;

      case 90: // update_list
        value.move< std::list<cmd::update_clause> > (YY_MOVE (that.value));
        break;

      case 101: // column_name
        value.move< std::shared_ptr<cmd::Column> > (YY_MOVE (that.value));
        break;

      case 92: // delete_statement
        value.move< std::shared_ptr<cmd::Delete> > (YY_MOVE (that.value));
        break;

      case 83: // drop_statement
        value.move< std::shared_ptr<cmd::DropTable> > (YY_MOVE (that.value));
        break;

      case 86: // optional_where
      case 94: // expr
      case 95: // operand
      case 96: // unary_operator
      case 97: // binary_operator
      case 98: // logical_operator
      case 99: // scalar_expr
        value.move< std::shared_ptr<cmd::Expression> > (YY_MOVE (that.value));
        break;

      case 87: // insert_statement
        value.move< std::shared_ptr<cmd::Insert> > (YY_MOVE (that.value));
        break;

      case 77: // statement
      case 78: // show_statement
      case 79: // create_statement
        value.move< std::shared_ptr<cmd::Instruction> > (YY_MOVE (that.value));
        break;

      case 100: // literal_value
        value.move< std::shared_ptr<cmd::Literal> > (YY_MOVE (that.value));
        break;

      case 84: // select_statement
        value.move< std::shared_ptr<cmd::Select> > (YY_MOVE (that.value));
        break;

      case 89: // update_statement
        value.move< std::shared_ptr<cmd::Update> > (YY_MOVE (that.value));
        break;

      case 88: // optional_column_list
      case 105: // id_comma_list
        value.move< std::shared_ptr<std::list<cmd::Column>> > (YY_MOVE (that.value));
        break;

      case 104: // literal_list
        value.move< std::shared_ptr<std::list<cmd::Literal>> > (YY_MOVE (that.value));
        break;

      case 85: // select_list
      case 93: // expr_list
        value.move< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (YY_MOVE (that.value));
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // BLOB_STRING
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
      case 7: // TRUE
      case 8: // FALSE
        value.move< bool > (that.value);
        break;

      case 81: // column_def
        value.move< cmd::ColumnDefinition > (that.value);
        break;

      case 82: // column_type
        value.move< cmd::LiteralType > (that.value);
        break;

      case 102: // table_name
        value.move< cmd::TableDefinition > (that.value);
        break;

      case 91: // update_clause
        value.move< cmd::update_clause > (that.value);
        break;

      case 9: // DOUBLE_CONST
        value.move< long double > (that.value);
        break;

      case 6: // INTEGER_CONST
        value.move< long long > (that.value);
        break;

      case 80: // column_def_commalist
        value.move< std::list<cmd::ColumnDefinition> > (that.value);
        break;

      case 90: // update_list
        value.move< std::list<cmd::update_clause> > (that.value);
        break;

      case 101: // column_name
        value.move< std::shared_ptr<cmd::Column> > (that.value);
        break;

      case 92: // delete_statement
        value.move< std::shared_ptr<cmd::Delete> > (that.value);
        break;

      case 83: // drop_statement
        value.move< std::shared_ptr<cmd::DropTable> > (that.value);
        break;

      case 86: // optional_where
      case 94: // expr
      case 95: // operand
      case 96: // unary_operator
      case 97: // binary_operator
      case 98: // logical_operator
      case 99: // scalar_expr
        value.move< std::shared_ptr<cmd::Expression> > (that.value);
        break;

      case 87: // insert_statement
        value.move< std::shared_ptr<cmd::Insert> > (that.value);
        break;

      case 77: // statement
      case 78: // show_statement
      case 79: // create_statement
        value.move< std::shared_ptr<cmd::Instruction> > (that.value);
        break;

      case 100: // literal_value
        value.move< std::shared_ptr<cmd::Literal> > (that.value);
        break;

      case 84: // select_statement
        value.move< std::shared_ptr<cmd::Select> > (that.value);
        break;

      case 89: // update_statement
        value.move< std::shared_ptr<cmd::Update> > (that.value);
        break;

      case 88: // optional_column_list
      case 105: // id_comma_list
        value.move< std::shared_ptr<std::list<cmd::Column>> > (that.value);
        break;

      case 104: // literal_list
        value.move< std::shared_ptr<std::list<cmd::Literal>> > (that.value);
        break;

      case 85: // select_list
      case 93: // expr_list
        value.move< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (that.value);
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // BLOB_STRING
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
      case 7: // TRUE
      case 8: // FALSE
        yylhs.value.emplace< bool > ();
        break;

      case 81: // column_def
        yylhs.value.emplace< cmd::ColumnDefinition > ();
        break;

      case 82: // column_type
        yylhs.value.emplace< cmd::LiteralType > ();
        break;

      case 102: // table_name
        yylhs.value.emplace< cmd::TableDefinition > ();
        break;

      case 91: // update_clause
        yylhs.value.emplace< cmd::update_clause > ();
        break;

      case 9: // DOUBLE_CONST
        yylhs.value.emplace< long double > ();
        break;

      case 6: // INTEGER_CONST
        yylhs.value.emplace< long long > ();
        break;

      case 80: // column_def_commalist
        yylhs.value.emplace< std::list<cmd::ColumnDefinition> > ();
        break;

      case 90: // update_list
        yylhs.value.emplace< std::list<cmd::update_clause> > ();
        break;

      case 101: // column_name
        yylhs.value.emplace< std::shared_ptr<cmd::Column> > ();
        break;

      case 92: // delete_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Delete> > ();
        break;

      case 83: // drop_statement
        yylhs.value.emplace< std::shared_ptr<cmd::DropTable> > ();
        break;

      case 86: // optional_where
      case 94: // expr
      case 95: // operand
      case 96: // unary_operator
      case 97: // binary_operator
      case 98: // logical_operator
      case 99: // scalar_expr
        yylhs.value.emplace< std::shared_ptr<cmd::Expression> > ();
        break;

      case 87: // insert_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Insert> > ();
        break;

      case 77: // statement
      case 78: // show_statement
      case 79: // create_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Instruction> > ();
        break;

      case 100: // literal_value
        yylhs.value.emplace< std::shared_ptr<cmd::Literal> > ();
        break;

      case 84: // select_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Select> > ();
        break;

      case 89: // update_statement
        yylhs.value.emplace< std::shared_ptr<cmd::Update> > ();
        break;

      case 88: // optional_column_list
      case 105: // id_comma_list
        yylhs.value.emplace< std::shared_ptr<std::list<cmd::Column>> > ();
        break;

      case 104: // literal_list
        yylhs.value.emplace< std::shared_ptr<std::list<cmd::Literal>> > ();
        break;

      case 85: // select_list
      case 93: // expr_list
        yylhs.value.emplace< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ();
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // BLOB_STRING
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
#line 100 "bison_sql.ypp" // lalr1.cc:906
    {
            driver.AddInstruction(yystack_[0].value.as< std::shared_ptr<cmd::Instruction> > ());
        }
#line 918 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 4:
#line 104 "bison_sql.ypp" // lalr1.cc:906
    {
            driver.AddInstruction(yystack_[0].value.as< std::shared_ptr<cmd::Instruction> > ());
        }
#line 926 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 6:
#line 112 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = yystack_[0].value.as< std::shared_ptr<cmd::Instruction> > (); }
#line 932 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 7:
#line 113 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = yystack_[0].value.as< std::shared_ptr<cmd::Instruction> > (); }
#line 938 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 12:
#line 125 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = std::make_shared<cmd::ShowCreateTable>(yystack_[0].value.as< cmd::TableDefinition > ());
        }
#line 946 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 13:
#line 134 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::shared_ptr<cmd::Instruction> > () = std::make_shared<cmd::CreateTable>(yystack_[3].value.as< cmd::TableDefinition > (), yystack_[1].value.as< std::list<cmd::ColumnDefinition> > ());
        }
#line 954 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 14:
#line 142 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::list<cmd::ColumnDefinition> > () = std::list<cmd::ColumnDefinition>({std::move(yystack_[0].value.as< cmd::ColumnDefinition > ())});
        }
#line 962 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 15:
#line 146 "bison_sql.ypp" // lalr1.cc:906
    {
            yystack_[2].value.as< std::list<cmd::ColumnDefinition> > ().push_back(yystack_[0].value.as< cmd::ColumnDefinition > ());
            yylhs.value.as< std::list<cmd::ColumnDefinition> > () = std::move(yystack_[2].value.as< std::list<cmd::ColumnDefinition> > ());
        }
#line 971 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 16:
#line 155 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< cmd::ColumnDefinition > () = cmd::ColumnDefinition(yystack_[1].value.as< std::string > (), yystack_[0].value.as< cmd::LiteralType > ());
        }
#line 979 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 17:
#line 162 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< cmd::LiteralType > () = cmd::LiteralType::INTEGER; }
#line 985 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 18:
#line 163 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< cmd::LiteralType > () = cmd::LiteralType::DOUBLE; }
#line 991 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 19:
#line 164 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< cmd::LiteralType > () = cmd::LiteralType::TEXT; }
#line 997 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 20:
#line 171 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::shared_ptr<cmd::DropTable> > () = std::make_shared<cmd::DropTable>(yystack_[0].value.as< cmd::TableDefinition > ());
        }
#line 1005 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 21:
#line 180 "bison_sql.ypp" // lalr1.cc:906
    {
            if (yystack_[3].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () == nullptr) {
                yylhs.value.as< std::shared_ptr<cmd::Select> > () = std::make_shared<cmd::Select>(yystack_[1].value.as< cmd::TableDefinition > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            } else {
                yylhs.value.as< std::shared_ptr<cmd::Select> > () = std::make_shared<cmd::Select>(yystack_[1].value.as< cmd::TableDefinition > (), *(yystack_[3].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ()), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            }
        }
#line 1017 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 22:
#line 191 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () = nullptr; }
#line 1023 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 23:
#line 192 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () = yystack_[0].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (); }
#line 1029 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 24:
#line 198 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1035 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 25:
#line 199 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = nullptr; }
#line 1041 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 26:
#line 207 "bison_sql.ypp" // lalr1.cc:906
    {
            if (yystack_[4].value.as< std::shared_ptr<std::list<cmd::Column>> > () == nullptr) {
                yylhs.value.as< std::shared_ptr<cmd::Insert> > () = std::make_shared<cmd::Insert>(yystack_[5].value.as< cmd::TableDefinition > (), *(yystack_[1].value.as< std::shared_ptr<std::list<cmd::Literal>> > ()));
            } else {
                yylhs.value.as< std::shared_ptr<cmd::Insert> > () = std::make_shared<cmd::Insert>(yystack_[5].value.as< cmd::TableDefinition > (), *(yystack_[1].value.as< std::shared_ptr<std::list<cmd::Literal>> > ()), *(yystack_[4].value.as< std::shared_ptr<std::list<cmd::Column>> > ()));
            }
        }
#line 1053 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 27:
#line 219 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > () = yystack_[0].value.as< std::shared_ptr<std::list<cmd::Column>> > (); }
#line 1059 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 28:
#line 220 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > () = nullptr; }
#line 1065 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 29:
#line 226 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::shared_ptr<cmd::Update> > () = std::make_shared<cmd::Update>(yystack_[3].value.as< cmd::TableDefinition > (), yystack_[1].value.as< std::list<cmd::update_clause> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
        }
#line 1073 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 30:
#line 234 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::list<cmd::update_clause> > ().push_back(yystack_[0].value.as< cmd::update_clause > ());
        }
#line 1081 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 31:
#line 238 "bison_sql.ypp" // lalr1.cc:906
    {
            yystack_[2].value.as< std::list<cmd::update_clause> > ().push_back(yystack_[0].value.as< cmd::update_clause > ());
            yylhs.value.as< std::list<cmd::update_clause> > () = std::move(yystack_[2].value.as< std::list<cmd::update_clause> > ());
        }
#line 1090 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 32:
#line 247 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< cmd::update_clause > ().first = cmd::Column(yystack_[2].value.as< std::string > ());
            yylhs.value.as< cmd::update_clause > ().second = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ();
        }
#line 1099 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 33:
#line 257 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::shared_ptr<cmd::Delete> > () = std::make_shared<cmd::Delete>(yystack_[1].value.as< cmd::TableDefinition > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
        }
#line 1107 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 34:
#line 266 "bison_sql.ypp" // lalr1.cc:906
    {  
            yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () = std::make_shared<std::list<std::shared_ptr<cmd::Expression>>>();
            yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ()->push_back(yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
        }
#line 1116 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 35:
#line 271 "bison_sql.ypp" // lalr1.cc:906
    {
            yystack_[2].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ()->push_back(yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > () = yystack_[2].value.as< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ();
        }
#line 1125 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 36:
#line 279 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1131 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 37:
#line 280 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1137 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 38:
#line 285 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[1].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1143 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 39:
#line 286 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1149 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 40:
#line 287 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1155 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 41:
#line 288 "bison_sql.ypp" // lalr1.cc:906
    { yylhs.value.as< std::shared_ptr<cmd::Expression> > () = yystack_[0].value.as< std::shared_ptr<cmd::Expression> > (); }
#line 1161 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 42:
#line 294 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::UNARY_MINUS, yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1169 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 43:
#line 298 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::UNARY_PLUS, yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1177 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 44:
#line 302 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::BIN_NOT, yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1185 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 45:
#line 306 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::NOT, yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1193 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 46:
#line 310 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::ISNULL, yystack_[1].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1201 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 47:
#line 314 "bison_sql.ypp" // lalr1.cc:906
    {
            auto nodeIsNull = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::ISNULL, yystack_[1].value.as< std::shared_ptr<cmd::Expression> > ());
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::UnaryOperation>(cmd::OperationType::NOT, nodeIsNull);
        }
#line 1210 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 48:
#line 323 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::LESS, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1218 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 49:
#line 327 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::GREATER, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1226 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 50:
#line 331 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::EQUAL, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1234 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 51:
#line 335 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::NOT_EQUAL, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1242 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 52:
#line 339 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::LESS_EQUAL, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1250 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 53:
#line 343 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::GREATER_EQUAL, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1258 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 54:
#line 347 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::PLUS, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1266 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 55:
#line 351 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::MINUS, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1274 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 56:
#line 355 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::MULTIPLY, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1282 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 57:
#line 359 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::DIVISION, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1290 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 58:
#line 363 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::MOD, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1298 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 59:
#line 367 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::CONCATENATION, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1306 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 60:
#line 375 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::AND, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1314 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 61:
#line 379 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Expression> > () = std::make_shared<cmd::BinaryOperation>(cmd::OperationType::OR, yystack_[2].value.as< std::shared_ptr<cmd::Expression> > (), yystack_[0].value.as< std::shared_ptr<cmd::Expression> > ()); 
        }
#line 1322 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 64:
#line 393 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(yystack_[0].value.as< long long > ()); 
        }
#line 1330 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 65:
#line 397 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(yystack_[0].value.as< long double > ()); 
        }
#line 1338 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 66:
#line 401 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(yystack_[0].value.as< std::string > ()); 
        }
#line 1346 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 67:
#line 405 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(yystack_[0].value.as< std::string > ()); 
        }
#line 1354 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 68:
#line 409 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(); 
        }
#line 1362 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 69:
#line 413 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(yystack_[0].value.as< bool > ()); 
        }
#line 1370 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 70:
#line 417 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Literal> > () = std::make_shared<cmd::Literal>(yystack_[0].value.as< bool > ()); 
        }
#line 1378 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 71:
#line 425 "bison_sql.ypp" // lalr1.cc:906
    {        
            yylhs.value.as< std::shared_ptr<cmd::Column> > () = std::make_shared<cmd::Column>(yystack_[0].value.as< std::string > ()); 
        }
#line 1386 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 72:
#line 429 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Column> > () = std::make_shared<cmd::Column>(yystack_[0].value.as< std::string > (), yystack_[2].value.as< std::string > ()); 
        }
#line 1394 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 73:
#line 433 "bison_sql.ypp" // lalr1.cc:906
    { 
            yylhs.value.as< std::shared_ptr<cmd::Column> > () = std::make_shared<cmd::Column>(yystack_[0].value.as< std::string > (), yystack_[2].value.as< std::string > (), yystack_[4].value.as< std::string > ()); 
        }
#line 1402 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 74:
#line 442 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< cmd::TableDefinition > () = cmd::TableDefinition(yystack_[0].value.as< std::string > ());
        }
#line 1410 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 75:
#line 446 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< cmd::TableDefinition > () = cmd::TableDefinition(yystack_[0].value.as< std::string > (), yystack_[2].value.as< std::string > ());
        }
#line 1418 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 78:
#line 461 "bison_sql.ypp" // lalr1.cc:906
    {
            yylhs.value.as< std::shared_ptr<std::list<cmd::Literal>> > () = std::make_shared<std::list<cmd::Literal>>();
            yylhs.value.as< std::shared_ptr<std::list<cmd::Literal>> > ()->push_back(*(yystack_[0].value.as< std::shared_ptr<cmd::Literal> > ()));
        }
#line 1427 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 79:
#line 466 "bison_sql.ypp" // lalr1.cc:906
    {
            yystack_[2].value.as< std::shared_ptr<std::list<cmd::Literal>> > ()->push_back(*(yystack_[0].value.as< std::shared_ptr<cmd::Literal> > ()));
            yylhs.value.as< std::shared_ptr<std::list<cmd::Literal>> > () = yystack_[2].value.as< std::shared_ptr<std::list<cmd::Literal>> > ();
        }
#line 1436 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 80:
#line 475 "bison_sql.ypp" // lalr1.cc:906
    {   
            yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > () = std::make_shared<std::list<cmd::Column>>();
            yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > ()->push_back(cmd::Column(yystack_[0].value.as< std::string > ())); 
        }
#line 1445 "bison_sql.cpp" // lalr1.cc:906
    break;

  case 81:
#line 480 "bison_sql.ypp" // lalr1.cc:906
    {         
            yystack_[2].value.as< std::shared_ptr<std::list<cmd::Column>> > ()->push_back(cmd::Column(yystack_[0].value.as< std::string > ()));
            yylhs.value.as< std::shared_ptr<std::list<cmd::Column>> > () = yystack_[2].value.as< std::shared_ptr<std::list<cmd::Column>> > ();
        }
#line 1454 "bison_sql.cpp" // lalr1.cc:906
    break;


#line 1458 "bison_sql.cpp" // lalr1.cc:906
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


  const signed char  BisonParser ::yypact_ninf_ = -99;

  const signed char  BisonParser ::yytable_ninf_ = -1;

  const short
   BisonParser ::yypact_[] =
  {
      51,     6,    20,    21,    -2,     1,    60,    43,    44,     8,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    60,    60,
      60,    12,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    19,
      19,    19,    19,   -99,    19,    48,    14,    39,    52,   -99,
     -99,   -99,   -99,   -99,   -99,    60,    42,    85,    60,   -99,
     -99,    51,   -99,    56,   -99,   -99,    73,    69,   -99,   -99,
     -99,   -39,    60,    19,    19,    19,   -99,   -99,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
     108,   109,   110,   103,   -99,   124,    61,   -99,   103,    39,
     -99,    82,    86,    86,    91,    91,    91,    91,   -99,   102,
     102,   104,   104,   104,   -99,   140,    92,   -99,   112,   -14,
     -99,    19,   -99,     7,   -28,   -99,   160,   -99,    94,   162,
      19,   110,   -99,    39,   -99,   -99,   -99,   -99,   124,   -99,
     -99,    41,   -99,    39,   -99,   -99,   -99,     2,    41,   -99,
     -99
  };

  const unsigned char
   BisonParser ::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     6,     7,     5,     8,     9,    10,    11,     0,     0,
       0,    71,    66,    67,    64,    69,    70,    65,    68,     0,
       0,     0,     0,    22,     0,     0,    23,    34,    36,    41,
      39,    37,    40,    62,    63,     0,    74,     0,     0,     1,
      77,    76,     2,     0,    20,    12,     0,    45,    44,    43,
      42,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,    25,     4,     0,    72,    38,    25,    35,
      60,    61,    50,    51,    52,    53,    48,    49,    59,    54,
      55,    56,    57,    58,    80,     0,    27,    75,     0,    25,
      30,     0,    33,     0,     0,    14,     0,    21,     0,     0,
       0,     0,    29,    24,    18,    19,    17,    16,     0,    13,
      73,     0,    81,    32,    31,    15,    78,     0,     0,    26,
      79
  };

  const signed char
   BisonParser ::yypgoto_[] =
  {
     -99,   -99,   -99,   118,   -99,   -99,   -99,    45,   -99,   -99,
     -99,   -99,   -72,   -99,   -99,   -99,   -99,    49,   -99,   -99,
     -34,    22,   -99,   -99,   -99,   -99,   -98,   -99,    -6,   -99,
     -99,   -99
  };

  const short
   BisonParser ::yydefgoto_[] =
  {
      -1,     8,     9,    10,    11,    12,   114,   115,   127,    13,
      14,    35,   112,    15,   105,    16,   109,   110,    17,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    47,    52,
     137,   106
  };

  const short
   BisonParser ::yytable_[] =
  {
      61,    21,    22,    23,    24,    25,    26,    27,    50,    64,
      65,   111,    53,    54,    55,    28,   117,   124,   125,   126,
      18,    45,    21,    22,    23,    24,    25,    26,    27,    89,
      90,    91,    87,   136,    19,    20,    28,   122,    29,    80,
     140,   128,    83,   129,    49,    22,    23,    24,    25,    26,
      27,    57,    58,    59,    60,   121,    88,    30,    28,    29,
      31,    32,    33,    46,     1,    48,     2,     3,    34,     4,
      62,   138,     5,   139,     6,    51,    86,   123,    30,     7,
      56,    31,    32,    63,    66,    67,   133,    64,    65,    34,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    68,    69,    70,    71,    72,    73,    74,    82,
      81,   104,   107,   108,    75,    76,    77,    78,    79,    68,
      69,    70,    71,    72,    73,    74,    85,   113,   111,   116,
      64,    75,    76,    77,    78,    79,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    75,    76,    77,    78,    79,    74,   118,
      74,   119,   120,   130,   131,   132,    77,    78,    79,    84,
     134,     0,     0,   135
  };

  const short
   BisonParser ::yycheck_[] =
  {
      34,     3,     4,     5,     6,     7,     8,     9,     0,    48,
      49,    25,    18,    19,    20,    17,    88,    10,    11,    12,
      14,    20,     3,     4,     5,     6,     7,     8,     9,    63,
      64,    65,    71,   131,    14,    14,    17,   109,    40,    45,
     138,    69,    48,    71,     0,     4,     5,     6,     7,     8,
       9,    29,    30,    31,    32,    69,    62,    59,    17,    40,
      62,    63,    64,     3,    13,    22,    15,    16,    70,    18,
      22,    69,    21,    71,    23,    67,     3,   111,    59,    28,
      68,    62,    63,    69,    32,    33,   120,    48,    49,    70,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    50,    51,    52,    53,    54,    55,    56,    24,
      68,     3,     3,     3,    62,    63,    64,    65,    66,    50,
      51,    52,    53,    54,    55,    56,    70,     3,    25,    68,
      48,    62,    63,    64,    65,    66,    50,    51,    52,    53,
      54,    55,    56,    52,    53,    54,    55,    56,    62,    63,
      64,    65,    66,    62,    63,    64,    65,    66,    56,    19,
      56,    69,    50,     3,    70,     3,    64,    65,    66,    51,
     121,    -1,    -1,   128
  };

  const unsigned char
   BisonParser ::yystos_[] =
  {
       0,    13,    15,    16,    18,    21,    23,    28,    75,    76,
      77,    78,    79,    83,    84,    87,    89,    92,    14,    14,
      14,     3,     4,     5,     6,     7,     8,     9,    17,    40,
      59,    62,    63,    64,    70,    85,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    20,     3,   102,    22,     0,
       0,    67,   103,   102,   102,   102,    68,    95,    95,    95,
      95,    94,    22,    69,    48,    49,    32,    33,    50,    51,
      52,    53,    54,    55,    56,    62,    63,    64,    65,    66,
     102,    68,    24,   102,    77,    70,     3,    71,   102,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,     3,    88,   105,     3,     3,    90,
      91,    25,    86,     3,    80,    81,    68,    86,    19,    69,
      50,    69,    86,    94,    10,    11,    12,    82,    69,    71,
       3,    70,     3,    94,    91,    81,   100,   104,    69,    71,
     100
  };

  const unsigned char
   BisonParser ::yyr1_[] =
  {
       0,    74,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    78,    79,    80,    80,    81,    82,    82,    82,
      83,    84,    85,    85,    86,    86,    87,    88,    88,    89,
      90,    90,    91,    92,    93,    93,    94,    94,    95,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105
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
       1,     1,     3,     5,     1,     3,     1,     1,     1,     3,
       1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  BisonParser ::yytname_[] =
  {
  "END_FILE", "error", "$undefined", "IDENTIFIER", "STRING",
  "BLOB_STRING", "INTEGER_CONST", "TRUE", "FALSE", "DOUBLE_CONST",
  "DOUBLE", "TEXT", "INTEGER", "CREATE", "TABLE", "DROP", "SHOW", "NULL_",
  "SELECT", "VALUES", "INTO", "INSERT", "FROM", "UPDATE", "SET", "WHERE",
  "LIMIT", "OFFSET", "DELETE", "CAST", "AS", "ESCAPE", "ISNULL", "NOTNULL",
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
       0,    95,    95,    99,   103,   111,   112,   113,   114,   115,
     116,   117,   124,   133,   141,   145,   154,   162,   163,   164,
     170,   179,   191,   192,   198,   199,   206,   219,   220,   226,
     233,   237,   246,   256,   265,   270,   279,   280,   285,   286,
     287,   288,   293,   297,   301,   305,   309,   313,   322,   326,
     330,   334,   338,   342,   346,   350,   354,   358,   362,   366,
     374,   378,   386,   387,   392,   396,   400,   404,   408,   412,
     416,   424,   428,   432,   441,   445,   454,   455,   460,   465,
     474,   479
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
#line 1857 "bison_sql.cpp" // lalr1.cc:1217
