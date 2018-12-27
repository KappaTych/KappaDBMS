// A Bison parser, made by GNU Bison 3.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file bison_sql.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_BISON_SQL_HPP_INCLUDED
# define YY_YY_BISON_SQL_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 15 "bison_sql.ypp" // lalr1.cc:403

    #define YYDEBUG 1
    
    #include <memory>
    #include <utility>
    #include "../sql.hpp"

    namespace yy {
        class FlexScanner;
    }

    namespace sql {
        class Parser;
    }

#line 64 "bison_sql.hpp" // lalr1.cc:403


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

// Support move semantics when possible.
#if defined __cplusplus && 201103L <= __cplusplus
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif
# include "location.hh"

#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace yy {
#line 158 "bison_sql.hpp" // lalr1.cc:403

  /// A stack with random access from its top.
  template <typename T, typename S = std::vector<T> >
  class stack
  {
  public:
    // Hide our reversed order.
    typedef typename S::reverse_iterator iterator;
    typedef typename S::const_reverse_iterator const_iterator;
    typedef typename S::size_type size_type;

    stack (size_type n = 200)
      : seq_ (n)
    {}

    /// Random access.
    ///
    /// Index 0 returns the topmost element.
    T&
    operator[] (size_type i)
    {
      return seq_[size () - 1 - i];
    }

    /// Random access.
    ///
    /// Index 0 returns the topmost element.
    T&
    operator[] (int i)
    {
      return operator[] (size_type (i));
    }

    /// Random access.
    ///
    /// Index 0 returns the topmost element.
    const T&
    operator[] (size_type i) const
    {
      return seq_[size () - 1 - i];
    }

    /// Random access.
    ///
    /// Index 0 returns the topmost element.
    const T&
    operator[] (int i) const
    {
      return operator[] (size_type (i));
    }

    /// Steal the contents of \a t.
    ///
    /// Close to move-semantics.
    void
    push (YY_MOVE_REF (T) t)
    {
      seq_.push_back (T ());
      operator[](0).move (t);
    }

    void
    pop (int n = 1)
    {
      for (; 0 < n; --n)
        seq_.pop_back ();
    }

    void
    clear ()
    {
      seq_.clear ();
    }

    size_type
    size () const
    {
      return seq_.size ();
    }

    const_iterator
    begin () const
    {
      return seq_.rbegin ();
    }

    const_iterator
    end () const
    {
      return seq_.rend ();
    }

  private:
    stack (const stack&);
    stack& operator= (const stack&);
    /// The wrapped container.
    S seq_;
  };

  /// Present a slice of the top of a stack.
  template <typename T, typename S = stack<T> >
  class slice
  {
  public:
    slice (const S& stack, int range)
      : stack_ (stack)
      , range_ (range)
    {}

    const T&
    operator[] (int i) const
    {
      return stack_[range_ - i];
    }

  private:
    const S& stack_;
    int range_;
  };



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    variant (YY_RVREF (T) t)
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {}

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

# if defined __cplusplus && 201103L <= __cplusplus
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename U>
    T&
    emplace (U&& u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u));
    }
# else
    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
# if defined __cplusplus && 201103L <= __cplusplus
      emplace<T> (std::move (other.as<T> ()));
# else
      emplace<T> ();
      swap<T> (other);
# endif
      other.destroy<T> ();
    }

# if defined __cplusplus && 201103L <= __cplusplus
    /// Move the content of \a other to this.
    template <typename T>
    void
    move (self_type&& other)
    {
      emplace<T> (std::move (other.as<T> ()));
      other.destroy<T> ();
    }
#endif

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      emplace<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;
  };


  /// A Bison parser.
  class  BisonParser 
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // TRUE
      // FALSE
      char dummy1[sizeof (bool)];

      // column_def
      char dummy2[sizeof (cmd::ColumnDefinition)];

      // column_type
      char dummy3[sizeof (cmd::LiteralType)];

      // table_name
      char dummy4[sizeof (cmd::TableDefinition)];

      // update_clause
      char dummy5[sizeof (cmd::update_clause)];

      // DOUBLE_CONST
      char dummy6[sizeof (long double)];

      // INTEGER_CONST
      char dummy7[sizeof (long long)];

      // column_def_commalist
      char dummy8[sizeof (std::list<cmd::ColumnDefinition>)];

      // update_list
      char dummy9[sizeof (std::list<cmd::update_clause>)];

      // column_name
      char dummy10[sizeof (std::shared_ptr<cmd::Column>)];

      // delete_statement
      char dummy11[sizeof (std::shared_ptr<cmd::Delete>)];

      // drop_statement
      char dummy12[sizeof (std::shared_ptr<cmd::DropTable>)];

      // optional_where
      // expr
      // operand
      // unary_operator
      // binary_operator
      // logical_operator
      // scalar_expr
      char dummy13[sizeof (std::shared_ptr<cmd::Expression>)];

      // insert_statement
      char dummy14[sizeof (std::shared_ptr<cmd::Insert>)];

      // statement
      // show_statement
      // create_statement
      char dummy15[sizeof (std::shared_ptr<cmd::Instruction>)];

      // literal_value
      char dummy16[sizeof (std::shared_ptr<cmd::Literal>)];

      // select_statement
      char dummy17[sizeof (std::shared_ptr<cmd::Select>)];

      // update_statement
      char dummy18[sizeof (std::shared_ptr<cmd::Update>)];

      // optional_column_list
      // id_comma_list
      char dummy19[sizeof (std::shared_ptr<std::list<cmd::Column>>)];

      // literal_list
      char dummy20[sizeof (std::shared_ptr<std::list<cmd::Literal>>)];

      // select_list
      // expr_list
      char dummy21[sizeof (std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>>)];

      // IDENTIFIER
      // STRING
      // BLOB_STRING
      char dummy22[sizeof (std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof (union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END_FILE = 0,
        IDENTIFIER = 258,
        STRING = 259,
        BLOB_STRING = 260,
        INTEGER_CONST = 261,
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
        NULL_ = 272,
        SELECT = 273,
        VALUES = 274,
        INTO = 275,
        INSERT = 276,
        FROM = 277,
        UPDATE = 278,
        SET = 279,
        WHERE = 280,
        LIMIT = 281,
        OFFSET = 282,
        DELETE = 283,
        CAST = 284,
        AS = 285,
        ESCAPE = 286,
        ISNULL = 287,
        NOTNULL = 288,
        BETWEEN = 289,
        DISTINCT = 290,
        EXISTS = 291,
        WHEN = 292,
        THEN = 293,
        ELSE = 294,
        NOT = 295,
        COLLATE = 296,
        IS = 297,
        IN = 298,
        LIKE = 299,
        GLOB = 300,
        MATCH = 301,
        REGEXP = 302,
        AND = 303,
        OR = 304,
        EQUAL = 305,
        NOTEQUAL = 306,
        LESSEQUAL = 307,
        GREATERQUALL = 308,
        LESS = 309,
        GREATER = 310,
        CONCATENATION = 311,
        LEFTSHIFT = 312,
        RIGHTSHIFT = 313,
        BINNOT = 314,
        BINAND = 315,
        BINOR = 316,
        PLUS = 317,
        MINUS = 318,
        MULTIPLY = 319,
        DIVISION = 320,
        MOD = 321,
        SEMICOLON = 322,
        DOT = 323,
        COMMA = 324,
        OPENBRACKET = 325,
        CLOSEBRACKET = 326,
        UMINUS = 327,
        UPLUS = 328
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Move or copy constructor.
      basic_symbol (YY_RVREF (basic_symbol) other);


      /// Constructor for valueless symbols, and symbols from each type.
      basic_symbol (typename Base::kind_type t, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (bool) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (cmd::ColumnDefinition) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (cmd::LiteralType) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (cmd::TableDefinition) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (cmd::update_clause) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (long double) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (long long) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::list<cmd::ColumnDefinition>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::list<cmd::update_clause>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Column>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Delete>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::DropTable>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Expression>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Insert>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Instruction>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Literal>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Select>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Update>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<std::list<cmd::Column>>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<std::list<cmd::Literal>>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>>) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::string) v, YY_RVREF (location_type) l);


      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if defined __cplusplus && __cplusplus < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    /// Build a parser object.
     BisonParser  (yy::FlexScanner& scanner_yyarg, sql::Parser& driver_yyarg);
    virtual ~ BisonParser  ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Symbol constructors declarations.
    static
    symbol_type
    make_END_FILE (YY_COPY (location_type) l);

    static
    symbol_type
    make_IDENTIFIER (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_STRING (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_BLOB_STRING (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_INTEGER_CONST (YY_COPY (long long) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_TRUE (YY_COPY (bool) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_FALSE (YY_COPY (bool) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DOUBLE_CONST (YY_COPY (long double) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DOUBLE (YY_COPY (location_type) l);

    static
    symbol_type
    make_TEXT (YY_COPY (location_type) l);

    static
    symbol_type
    make_INTEGER (YY_COPY (location_type) l);

    static
    symbol_type
    make_CREATE (YY_COPY (location_type) l);

    static
    symbol_type
    make_TABLE (YY_COPY (location_type) l);

    static
    symbol_type
    make_DROP (YY_COPY (location_type) l);

    static
    symbol_type
    make_SHOW (YY_COPY (location_type) l);

    static
    symbol_type
    make_NULL_ (YY_COPY (location_type) l);

    static
    symbol_type
    make_SELECT (YY_COPY (location_type) l);

    static
    symbol_type
    make_VALUES (YY_COPY (location_type) l);

    static
    symbol_type
    make_INTO (YY_COPY (location_type) l);

    static
    symbol_type
    make_INSERT (YY_COPY (location_type) l);

    static
    symbol_type
    make_FROM (YY_COPY (location_type) l);

    static
    symbol_type
    make_UPDATE (YY_COPY (location_type) l);

    static
    symbol_type
    make_SET (YY_COPY (location_type) l);

    static
    symbol_type
    make_WHERE (YY_COPY (location_type) l);

    static
    symbol_type
    make_LIMIT (YY_COPY (location_type) l);

    static
    symbol_type
    make_OFFSET (YY_COPY (location_type) l);

    static
    symbol_type
    make_DELETE (YY_COPY (location_type) l);

    static
    symbol_type
    make_CAST (YY_COPY (location_type) l);

    static
    symbol_type
    make_AS (YY_COPY (location_type) l);

    static
    symbol_type
    make_ESCAPE (YY_COPY (location_type) l);

    static
    symbol_type
    make_ISNULL (YY_COPY (location_type) l);

    static
    symbol_type
    make_NOTNULL (YY_COPY (location_type) l);

    static
    symbol_type
    make_BETWEEN (YY_COPY (location_type) l);

    static
    symbol_type
    make_DISTINCT (YY_COPY (location_type) l);

    static
    symbol_type
    make_EXISTS (YY_COPY (location_type) l);

    static
    symbol_type
    make_WHEN (YY_COPY (location_type) l);

    static
    symbol_type
    make_THEN (YY_COPY (location_type) l);

    static
    symbol_type
    make_ELSE (YY_COPY (location_type) l);

    static
    symbol_type
    make_NOT (YY_COPY (location_type) l);

    static
    symbol_type
    make_COLLATE (YY_COPY (location_type) l);

    static
    symbol_type
    make_IS (YY_COPY (location_type) l);

    static
    symbol_type
    make_IN (YY_COPY (location_type) l);

    static
    symbol_type
    make_LIKE (YY_COPY (location_type) l);

    static
    symbol_type
    make_GLOB (YY_COPY (location_type) l);

    static
    symbol_type
    make_MATCH (YY_COPY (location_type) l);

    static
    symbol_type
    make_REGEXP (YY_COPY (location_type) l);

    static
    symbol_type
    make_AND (YY_COPY (location_type) l);

    static
    symbol_type
    make_OR (YY_COPY (location_type) l);

    static
    symbol_type
    make_EQUAL (YY_COPY (location_type) l);

    static
    symbol_type
    make_NOTEQUAL (YY_COPY (location_type) l);

    static
    symbol_type
    make_LESSEQUAL (YY_COPY (location_type) l);

    static
    symbol_type
    make_GREATERQUALL (YY_COPY (location_type) l);

    static
    symbol_type
    make_LESS (YY_COPY (location_type) l);

    static
    symbol_type
    make_GREATER (YY_COPY (location_type) l);

    static
    symbol_type
    make_CONCATENATION (YY_COPY (location_type) l);

    static
    symbol_type
    make_LEFTSHIFT (YY_COPY (location_type) l);

    static
    symbol_type
    make_RIGHTSHIFT (YY_COPY (location_type) l);

    static
    symbol_type
    make_BINNOT (YY_COPY (location_type) l);

    static
    symbol_type
    make_BINAND (YY_COPY (location_type) l);

    static
    symbol_type
    make_BINOR (YY_COPY (location_type) l);

    static
    symbol_type
    make_PLUS (YY_COPY (location_type) l);

    static
    symbol_type
    make_MINUS (YY_COPY (location_type) l);

    static
    symbol_type
    make_MULTIPLY (YY_COPY (location_type) l);

    static
    symbol_type
    make_DIVISION (YY_COPY (location_type) l);

    static
    symbol_type
    make_MOD (YY_COPY (location_type) l);

    static
    symbol_type
    make_SEMICOLON (YY_COPY (location_type) l);

    static
    symbol_type
    make_DOT (YY_COPY (location_type) l);

    static
    symbol_type
    make_COMMA (YY_COPY (location_type) l);

    static
    symbol_type
    make_OPENBRACKET (YY_COPY (location_type) l);

    static
    symbol_type
    make_CLOSEBRACKET (YY_COPY (location_type) l);

    static
    symbol_type
    make_UMINUS (YY_COPY (location_type) l);

    static
    symbol_type
    make_UPLUS (YY_COPY (location_type) l);



  private:
    /// This class is not copyable.
     BisonParser  (const  BisonParser &);
     BisonParser & operator= (const  BisonParser &);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const signed char yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short yytable_[];

  static const short yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


#if YYDEBUG
    /// For a symbol, its name in clear.
    static const char* const yytname_[];

  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if defined __cplusplus && __cplusplus < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 173,     ///< Last index in yytable_.
      yynnts_ = 32,  ///< Number of nonterminal symbols.
      yyfinal_ = 49, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 74  ///< Number of tokens.
    };


    // User arguments.
    yy::FlexScanner& scanner;
    sql::Parser& driver;
  };

  // Symbol number corresponding to token number t.
  inline
   BisonParser ::token_number_type
   BisonParser ::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
    };
    const unsigned user_token_number_max_ = 328;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
   BisonParser ::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol ()
    : value ()
    , location ()
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (YY_RVREF (basic_symbol) other)
    : Base (YY_MOVE (other))
    , value ()
    , location (YY_MOVE (other.location))
  {
    switch (other.type_get ())
    {
      case 7: // TRUE
      case 8: // FALSE
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (other.value));
        break;

      case 81: // column_def
        value.YY_MOVE_OR_COPY< cmd::ColumnDefinition > (YY_MOVE (other.value));
        break;

      case 82: // column_type
        value.YY_MOVE_OR_COPY< cmd::LiteralType > (YY_MOVE (other.value));
        break;

      case 102: // table_name
        value.YY_MOVE_OR_COPY< cmd::TableDefinition > (YY_MOVE (other.value));
        break;

      case 91: // update_clause
        value.YY_MOVE_OR_COPY< cmd::update_clause > (YY_MOVE (other.value));
        break;

      case 9: // DOUBLE_CONST
        value.YY_MOVE_OR_COPY< long double > (YY_MOVE (other.value));
        break;

      case 6: // INTEGER_CONST
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (other.value));
        break;

      case 80: // column_def_commalist
        value.YY_MOVE_OR_COPY< std::list<cmd::ColumnDefinition> > (YY_MOVE (other.value));
        break;

      case 90: // update_list
        value.YY_MOVE_OR_COPY< std::list<cmd::update_clause> > (YY_MOVE (other.value));
        break;

      case 101: // column_name
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Column> > (YY_MOVE (other.value));
        break;

      case 92: // delete_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Delete> > (YY_MOVE (other.value));
        break;

      case 83: // drop_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::DropTable> > (YY_MOVE (other.value));
        break;

      case 86: // optional_where
      case 94: // expr
      case 95: // operand
      case 96: // unary_operator
      case 97: // binary_operator
      case 98: // logical_operator
      case 99: // scalar_expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Expression> > (YY_MOVE (other.value));
        break;

      case 87: // insert_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Insert> > (YY_MOVE (other.value));
        break;

      case 77: // statement
      case 78: // show_statement
      case 79: // create_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Instruction> > (YY_MOVE (other.value));
        break;

      case 100: // literal_value
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Literal> > (YY_MOVE (other.value));
        break;

      case 84: // select_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Select> > (YY_MOVE (other.value));
        break;

      case 89: // update_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<cmd::Update> > (YY_MOVE (other.value));
        break;

      case 88: // optional_column_list
      case 105: // id_comma_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<std::list<cmd::Column>> > (YY_MOVE (other.value));
        break;

      case 104: // literal_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<std::list<cmd::Literal>> > (YY_MOVE (other.value));
        break;

      case 85: // select_list
      case 93: // expr_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (YY_MOVE (other.value));
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // BLOB_STRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (other.value));
        break;

      default:
        break;
    }

  }


  // Implementation of basic_symbol constructor for each type.
  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (location_type) l)
    : Base (t)
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (bool) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (cmd::ColumnDefinition) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (cmd::LiteralType) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (cmd::TableDefinition) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (cmd::update_clause) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (long double) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (long long) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::list<cmd::ColumnDefinition>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::list<cmd::update_clause>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Column>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Delete>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::DropTable>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Expression>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Insert>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Instruction>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Literal>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Select>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<cmd::Update>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<std::list<cmd::Column>>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<std::list<cmd::Literal>>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>>) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
   BisonParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::string) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}



  template <typename Base>
   BisonParser ::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  void
   BisonParser ::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
  switch (yytype)
    {
      case 7: // TRUE
      case 8: // FALSE
        value.template destroy< bool > ();
        break;

      case 81: // column_def
        value.template destroy< cmd::ColumnDefinition > ();
        break;

      case 82: // column_type
        value.template destroy< cmd::LiteralType > ();
        break;

      case 102: // table_name
        value.template destroy< cmd::TableDefinition > ();
        break;

      case 91: // update_clause
        value.template destroy< cmd::update_clause > ();
        break;

      case 9: // DOUBLE_CONST
        value.template destroy< long double > ();
        break;

      case 6: // INTEGER_CONST
        value.template destroy< long long > ();
        break;

      case 80: // column_def_commalist
        value.template destroy< std::list<cmd::ColumnDefinition> > ();
        break;

      case 90: // update_list
        value.template destroy< std::list<cmd::update_clause> > ();
        break;

      case 101: // column_name
        value.template destroy< std::shared_ptr<cmd::Column> > ();
        break;

      case 92: // delete_statement
        value.template destroy< std::shared_ptr<cmd::Delete> > ();
        break;

      case 83: // drop_statement
        value.template destroy< std::shared_ptr<cmd::DropTable> > ();
        break;

      case 86: // optional_where
      case 94: // expr
      case 95: // operand
      case 96: // unary_operator
      case 97: // binary_operator
      case 98: // logical_operator
      case 99: // scalar_expr
        value.template destroy< std::shared_ptr<cmd::Expression> > ();
        break;

      case 87: // insert_statement
        value.template destroy< std::shared_ptr<cmd::Insert> > ();
        break;

      case 77: // statement
      case 78: // show_statement
      case 79: // create_statement
        value.template destroy< std::shared_ptr<cmd::Instruction> > ();
        break;

      case 100: // literal_value
        value.template destroy< std::shared_ptr<cmd::Literal> > ();
        break;

      case 84: // select_statement
        value.template destroy< std::shared_ptr<cmd::Select> > ();
        break;

      case 89: // update_statement
        value.template destroy< std::shared_ptr<cmd::Update> > ();
        break;

      case 88: // optional_column_list
      case 105: // id_comma_list
        value.template destroy< std::shared_ptr<std::list<cmd::Column>> > ();
        break;

      case 104: // literal_list
        value.template destroy< std::shared_ptr<std::list<cmd::Literal>> > ();
        break;

      case 85: // select_list
      case 93: // expr_list
        value.template destroy< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > ();
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // BLOB_STRING
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  bool
   BisonParser ::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
   BisonParser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 7: // TRUE
      case 8: // FALSE
        value.move< bool > (YY_MOVE (s.value));
        break;

      case 81: // column_def
        value.move< cmd::ColumnDefinition > (YY_MOVE (s.value));
        break;

      case 82: // column_type
        value.move< cmd::LiteralType > (YY_MOVE (s.value));
        break;

      case 102: // table_name
        value.move< cmd::TableDefinition > (YY_MOVE (s.value));
        break;

      case 91: // update_clause
        value.move< cmd::update_clause > (YY_MOVE (s.value));
        break;

      case 9: // DOUBLE_CONST
        value.move< long double > (YY_MOVE (s.value));
        break;

      case 6: // INTEGER_CONST
        value.move< long long > (YY_MOVE (s.value));
        break;

      case 80: // column_def_commalist
        value.move< std::list<cmd::ColumnDefinition> > (YY_MOVE (s.value));
        break;

      case 90: // update_list
        value.move< std::list<cmd::update_clause> > (YY_MOVE (s.value));
        break;

      case 101: // column_name
        value.move< std::shared_ptr<cmd::Column> > (YY_MOVE (s.value));
        break;

      case 92: // delete_statement
        value.move< std::shared_ptr<cmd::Delete> > (YY_MOVE (s.value));
        break;

      case 83: // drop_statement
        value.move< std::shared_ptr<cmd::DropTable> > (YY_MOVE (s.value));
        break;

      case 86: // optional_where
      case 94: // expr
      case 95: // operand
      case 96: // unary_operator
      case 97: // binary_operator
      case 98: // logical_operator
      case 99: // scalar_expr
        value.move< std::shared_ptr<cmd::Expression> > (YY_MOVE (s.value));
        break;

      case 87: // insert_statement
        value.move< std::shared_ptr<cmd::Insert> > (YY_MOVE (s.value));
        break;

      case 77: // statement
      case 78: // show_statement
      case 79: // create_statement
        value.move< std::shared_ptr<cmd::Instruction> > (YY_MOVE (s.value));
        break;

      case 100: // literal_value
        value.move< std::shared_ptr<cmd::Literal> > (YY_MOVE (s.value));
        break;

      case 84: // select_statement
        value.move< std::shared_ptr<cmd::Select> > (YY_MOVE (s.value));
        break;

      case 89: // update_statement
        value.move< std::shared_ptr<cmd::Update> > (YY_MOVE (s.value));
        break;

      case 88: // optional_column_list
      case 105: // id_comma_list
        value.move< std::shared_ptr<std::list<cmd::Column>> > (YY_MOVE (s.value));
        break;

      case 104: // literal_list
        value.move< std::shared_ptr<std::list<cmd::Literal>> > (YY_MOVE (s.value));
        break;

      case 85: // select_list
      case 93: // expr_list
        value.move< std::shared_ptr<std::list<std::shared_ptr<cmd::Expression>>> > (YY_MOVE (s.value));
        break;

      case 3: // IDENTIFIER
      case 4: // STRING
      case 5: // BLOB_STRING
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
   BisonParser ::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
   BisonParser ::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
   BisonParser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
   BisonParser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
   BisonParser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
   BisonParser ::by_type::type_get () const
  {
    return type;
  }

  inline
   BisonParser ::token_type
   BisonParser ::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }

  // Implementation of make_symbol for each symbol type.
  inline
   BisonParser ::symbol_type
   BisonParser ::make_END_FILE (YY_COPY (location_type) l)
  {
    return symbol_type (token::END_FILE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_IDENTIFIER (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::IDENTIFIER, YY_MOVE (v), YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_STRING (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::STRING, YY_MOVE (v), YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_BLOB_STRING (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::BLOB_STRING, YY_MOVE (v), YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_INTEGER_CONST (YY_COPY (long long) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::INTEGER_CONST, YY_MOVE (v), YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_TRUE (YY_COPY (bool) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::TRUE, YY_MOVE (v), YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_FALSE (YY_COPY (bool) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::FALSE, YY_MOVE (v), YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_DOUBLE_CONST (YY_COPY (long double) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::DOUBLE_CONST, YY_MOVE (v), YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_DOUBLE (YY_COPY (location_type) l)
  {
    return symbol_type (token::DOUBLE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_TEXT (YY_COPY (location_type) l)
  {
    return symbol_type (token::TEXT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_INTEGER (YY_COPY (location_type) l)
  {
    return symbol_type (token::INTEGER, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_CREATE (YY_COPY (location_type) l)
  {
    return symbol_type (token::CREATE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_TABLE (YY_COPY (location_type) l)
  {
    return symbol_type (token::TABLE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_DROP (YY_COPY (location_type) l)
  {
    return symbol_type (token::DROP, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_SHOW (YY_COPY (location_type) l)
  {
    return symbol_type (token::SHOW, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_NULL_ (YY_COPY (location_type) l)
  {
    return symbol_type (token::NULL_, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_SELECT (YY_COPY (location_type) l)
  {
    return symbol_type (token::SELECT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_VALUES (YY_COPY (location_type) l)
  {
    return symbol_type (token::VALUES, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_INTO (YY_COPY (location_type) l)
  {
    return symbol_type (token::INTO, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_INSERT (YY_COPY (location_type) l)
  {
    return symbol_type (token::INSERT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_FROM (YY_COPY (location_type) l)
  {
    return symbol_type (token::FROM, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_UPDATE (YY_COPY (location_type) l)
  {
    return symbol_type (token::UPDATE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_SET (YY_COPY (location_type) l)
  {
    return symbol_type (token::SET, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_WHERE (YY_COPY (location_type) l)
  {
    return symbol_type (token::WHERE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_LIMIT (YY_COPY (location_type) l)
  {
    return symbol_type (token::LIMIT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_OFFSET (YY_COPY (location_type) l)
  {
    return symbol_type (token::OFFSET, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_DELETE (YY_COPY (location_type) l)
  {
    return symbol_type (token::DELETE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_CAST (YY_COPY (location_type) l)
  {
    return symbol_type (token::CAST, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_AS (YY_COPY (location_type) l)
  {
    return symbol_type (token::AS, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_ESCAPE (YY_COPY (location_type) l)
  {
    return symbol_type (token::ESCAPE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_ISNULL (YY_COPY (location_type) l)
  {
    return symbol_type (token::ISNULL, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_NOTNULL (YY_COPY (location_type) l)
  {
    return symbol_type (token::NOTNULL, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_BETWEEN (YY_COPY (location_type) l)
  {
    return symbol_type (token::BETWEEN, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_DISTINCT (YY_COPY (location_type) l)
  {
    return symbol_type (token::DISTINCT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_EXISTS (YY_COPY (location_type) l)
  {
    return symbol_type (token::EXISTS, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_WHEN (YY_COPY (location_type) l)
  {
    return symbol_type (token::WHEN, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_THEN (YY_COPY (location_type) l)
  {
    return symbol_type (token::THEN, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_ELSE (YY_COPY (location_type) l)
  {
    return symbol_type (token::ELSE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_NOT (YY_COPY (location_type) l)
  {
    return symbol_type (token::NOT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_COLLATE (YY_COPY (location_type) l)
  {
    return symbol_type (token::COLLATE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_IS (YY_COPY (location_type) l)
  {
    return symbol_type (token::IS, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_IN (YY_COPY (location_type) l)
  {
    return symbol_type (token::IN, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_LIKE (YY_COPY (location_type) l)
  {
    return symbol_type (token::LIKE, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_GLOB (YY_COPY (location_type) l)
  {
    return symbol_type (token::GLOB, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_MATCH (YY_COPY (location_type) l)
  {
    return symbol_type (token::MATCH, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_REGEXP (YY_COPY (location_type) l)
  {
    return symbol_type (token::REGEXP, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_AND (YY_COPY (location_type) l)
  {
    return symbol_type (token::AND, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_OR (YY_COPY (location_type) l)
  {
    return symbol_type (token::OR, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_EQUAL (YY_COPY (location_type) l)
  {
    return symbol_type (token::EQUAL, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_NOTEQUAL (YY_COPY (location_type) l)
  {
    return symbol_type (token::NOTEQUAL, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_LESSEQUAL (YY_COPY (location_type) l)
  {
    return symbol_type (token::LESSEQUAL, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_GREATERQUALL (YY_COPY (location_type) l)
  {
    return symbol_type (token::GREATERQUALL, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_LESS (YY_COPY (location_type) l)
  {
    return symbol_type (token::LESS, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_GREATER (YY_COPY (location_type) l)
  {
    return symbol_type (token::GREATER, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_CONCATENATION (YY_COPY (location_type) l)
  {
    return symbol_type (token::CONCATENATION, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_LEFTSHIFT (YY_COPY (location_type) l)
  {
    return symbol_type (token::LEFTSHIFT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_RIGHTSHIFT (YY_COPY (location_type) l)
  {
    return symbol_type (token::RIGHTSHIFT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_BINNOT (YY_COPY (location_type) l)
  {
    return symbol_type (token::BINNOT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_BINAND (YY_COPY (location_type) l)
  {
    return symbol_type (token::BINAND, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_BINOR (YY_COPY (location_type) l)
  {
    return symbol_type (token::BINOR, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_PLUS (YY_COPY (location_type) l)
  {
    return symbol_type (token::PLUS, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_MINUS (YY_COPY (location_type) l)
  {
    return symbol_type (token::MINUS, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_MULTIPLY (YY_COPY (location_type) l)
  {
    return symbol_type (token::MULTIPLY, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_DIVISION (YY_COPY (location_type) l)
  {
    return symbol_type (token::DIVISION, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_MOD (YY_COPY (location_type) l)
  {
    return symbol_type (token::MOD, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_SEMICOLON (YY_COPY (location_type) l)
  {
    return symbol_type (token::SEMICOLON, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_DOT (YY_COPY (location_type) l)
  {
    return symbol_type (token::DOT, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_COMMA (YY_COPY (location_type) l)
  {
    return symbol_type (token::COMMA, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_OPENBRACKET (YY_COPY (location_type) l)
  {
    return symbol_type (token::OPENBRACKET, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_CLOSEBRACKET (YY_COPY (location_type) l)
  {
    return symbol_type (token::CLOSEBRACKET, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_UMINUS (YY_COPY (location_type) l)
  {
    return symbol_type (token::UMINUS, YY_MOVE (l));
  }

  inline
   BisonParser ::symbol_type
   BisonParser ::make_UPLUS (YY_COPY (location_type) l)
  {
    return symbol_type (token::UPLUS, YY_MOVE (l));
  }



} // yy
#line 2444 "bison_sql.hpp" // lalr1.cc:403




#endif // !YY_YY_BISON_SQL_HPP_INCLUDED
