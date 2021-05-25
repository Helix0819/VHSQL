/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         HSQL_STYPE
#define YYLTYPE         HSQL_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hsql_parse
#define yylex           hsql_lex
#define yyerror         hsql_error
#define yydebug         hsql_debug
#define yynerrs         hsql_nerrs

/* First part of user prologue.  */
#line 1 "bison_parser.y"

/**
 * bison_parser.y
 * defines bison_parser.h
 * outputs bison_parser.c
 *
 * Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "bison_parser.h"
#include "flex_lexer.h"

#include <stdio.h>
#include <string.h>

using namespace hsql;

int yyerror(YYLTYPE* llocp, SQLParserResult* result, yyscan_t scanner, const char *msg) {
	result->setIsValid(false);
	result->setErrorDetails(strdup(msg), llocp->first_line, llocp->first_column);
	return 0;
}


#line 106 "bison_parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_HSQL_BISON_PARSER_H_INCLUDED
# define YY_HSQL_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef HSQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HSQL_DEBUG 1
#  else
#   define HSQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HSQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HSQL_DEBUG */
#if HSQL_DEBUG
extern int hsql_debug;
#endif
/* "%code requires" blocks.  */
#line 35 "bison_parser.y"

// %code requires block

#include "../sql/statements.h"
#include "../SQLParserResult.h"
#include "parser_typedef.h"

// Auto update column and line number
#define YY_USER_ACTION \
		yylloc->first_line = yylloc->last_line; \
		yylloc->first_column = yylloc->last_column; \
		for(int i = 0; yytext[i] != '\0'; i++) { \
			yylloc->total_column++; \
			yylloc->string_length++; \
				if(yytext[i] == '\n') { \
						yylloc->last_line++; \
						yylloc->last_column = 0; \
				} \
				else { \
						yylloc->last_column++; \
				} \
		}

#line 181 "bison_parser.cpp"

/* Token type.  */
#ifndef HSQL_TOKENTYPE
# define HSQL_TOKENTYPE
  enum hsql_tokentype
  {
    SQL_IDENTIFIER = 258,
    SQL_STRING = 259,
    SQL_FLOATVAL = 260,
    SQL_INTVAL = 261,
    SQL_DEALLOCATE = 262,
    SQL_PARAMETERS = 263,
    SQL_INTERSECT = 264,
    SQL_TEMPORARY = 265,
    SQL_TIMESTAMP = 266,
    SQL_DISTINCT = 267,
    SQL_NVARCHAR = 268,
    SQL_RESTRICT = 269,
    SQL_TRUNCATE = 270,
    SQL_ANALYZE = 271,
    SQL_BETWEEN = 272,
    SQL_CASCADE = 273,
    SQL_COLUMNS = 274,
    SQL_CONTROL = 275,
    SQL_DEFAULT = 276,
    SQL_EXECUTE = 277,
    SQL_EXPLAIN = 278,
    SQL_INTEGER = 279,
    SQL_NATURAL = 280,
    SQL_PREPARE = 281,
    SQL_PRIMARY = 282,
    SQL_SCHEMAS = 283,
    SQL_SPATIAL = 284,
    SQL_VARCHAR = 285,
    SQL_VIRTUAL = 286,
    SQL_DESCRIBE = 287,
    SQL_BEFORE = 288,
    SQL_COLUMN = 289,
    SQL_CREATE = 290,
    SQL_DELETE = 291,
    SQL_DIRECT = 292,
    SQL_DOUBLE = 293,
    SQL_ESCAPE = 294,
    SQL_EXCEPT = 295,
    SQL_EXISTS = 296,
    SQL_EXTRACT = 297,
    SQL_CAST = 298,
    SQL_FORMAT = 299,
    SQL_GLOBAL = 300,
    SQL_HAVING = 301,
    SQL_IMPORT = 302,
    SQL_INSERT = 303,
    SQL_ISNULL = 304,
    SQL_OFFSET = 305,
    SQL_RENAME = 306,
    SQL_SCHEMA = 307,
    SQL_SELECT = 308,
    SQL_SORTED = 309,
    SQL_TABLES = 310,
    SQL_UNIQUE = 311,
    SQL_UNLOAD = 312,
    SQL_UPDATE = 313,
    SQL_VALUES = 314,
    SQL_AFTER = 315,
    SQL_ALTER = 316,
    SQL_CROSS = 317,
    SQL_DELTA = 318,
    SQL_FLOAT = 319,
    SQL_GROUP = 320,
    SQL_INDEX = 321,
    SQL_INNER = 322,
    SQL_LIMIT = 323,
    SQL_LOCAL = 324,
    SQL_MERGE = 325,
    SQL_MINUS = 326,
    SQL_ORDER = 327,
    SQL_OUTER = 328,
    SQL_RIGHT = 329,
    SQL_TABLE = 330,
    SQL_UNION = 331,
    SQL_USING = 332,
    SQL_WHERE = 333,
    SQL_CALL = 334,
    SQL_CASE = 335,
    SQL_CHAR = 336,
    SQL_COPY = 337,
    SQL_DATE = 338,
    SQL_DATETIME = 339,
    SQL_DESC = 340,
    SQL_DROP = 341,
    SQL_ELSE = 342,
    SQL_FILE = 343,
    SQL_FROM = 344,
    SQL_FULL = 345,
    SQL_HASH = 346,
    SQL_HINT = 347,
    SQL_INTO = 348,
    SQL_JOIN = 349,
    SQL_LEFT = 350,
    SQL_LIKE = 351,
    SQL_LOAD = 352,
    SQL_LONG = 353,
    SQL_NULL = 354,
    SQL_PLAN = 355,
    SQL_SHOW = 356,
    SQL_TEXT = 357,
    SQL_THEN = 358,
    SQL_TIME = 359,
    SQL_VIEW = 360,
    SQL_WHEN = 361,
    SQL_WITH = 362,
    SQL_ADD = 363,
    SQL_ALL = 364,
    SQL_AND = 365,
    SQL_ASC = 366,
    SQL_END = 367,
    SQL_FOR = 368,
    SQL_INT = 369,
    SQL_KEY = 370,
    SQL_NOT = 371,
    SQL_OFF = 372,
    SQL_SET = 373,
    SQL_TOP = 374,
    SQL_AS = 375,
    SQL_BY = 376,
    SQL_IF = 377,
    SQL_IN = 378,
    SQL_IS = 379,
    SQL_OF = 380,
    SQL_ON = 381,
    SQL_OR = 382,
    SQL_TO = 383,
    SQL_ARRAY = 384,
    SQL_CONCAT = 385,
    SQL_ILIKE = 386,
    SQL_SECOND = 387,
    SQL_MINUTE = 388,
    SQL_HOUR = 389,
    SQL_DAY = 390,
    SQL_MONTH = 391,
    SQL_YEAR = 392,
    SQL_TRUE = 393,
    SQL_FALSE = 394,
    SQL_TRANSACTION = 395,
    SQL_BEGIN = 396,
    SQL_COMMIT = 397,
    SQL_ROLLBACK = 398,
    SQL_DATABASE = 399,
    SQL_DATABASES = 400,
    SQL_EQUALS = 401,
    SQL_NOTEQUALS = 402,
    SQL_LESS = 403,
    SQL_GREATER = 404,
    SQL_LESSEQ = 405,
    SQL_GREATEREQ = 406,
    SQL_NOTNULL = 407,
    SQL_UMINUS = 408
  };
#endif

/* Value type.  */
#if ! defined HSQL_STYPE && ! defined HSQL_STYPE_IS_DECLARED
union HSQL_STYPE
{
#line 95 "bison_parser.y"

	double fval;
	int64_t ival;
	char* sval;
	uintmax_t uval;
	bool bval;

	hsql::SQLStatement* statement;
	hsql::SelectStatement* 	select_stmt;
	hsql::ImportStatement* 	import_stmt;
	hsql::ExportStatement* 	export_stmt;
	hsql::CreateStatement* 	create_stmt;
	hsql::InsertStatement* 	insert_stmt;
	hsql::DeleteStatement* 	delete_stmt;
	hsql::UpdateStatement* 	update_stmt;
	hsql::DropStatement*   	drop_stmt;
	hsql::PrepareStatement* prep_stmt;
	hsql::ExecuteStatement* exec_stmt;
	hsql::ShowStatement*    show_stmt;
	hsql::TransactionStatement* transaction_stmt;

	hsql::TableName table_name;
	hsql::TableRef* table;
	hsql::Expr* expr;
	hsql::OrderDescription* order;
	hsql::OrderType order_type;
	hsql::WithDescription* with_description_t;
	hsql::DatetimeField datetime_field;
	hsql::LimitDescription* limit;
	hsql::ColumnDefinition* column_t;
	hsql::ColumnType column_type_t;
	hsql::ImportType import_type_t;
	hsql::GroupByDescription* group_t;
	hsql::UpdateClause* update_t;
	hsql::Alias* alias_t;
	hsql::SetOperation* set_operator_t;

	std::vector<hsql::SQLStatement*>* stmt_vec;

	std::vector<char*>* str_vec;
	std::vector<hsql::TableRef*>* table_vec;
	std::vector<hsql::ColumnDefinition*>* column_vec;
	std::vector<hsql::UpdateClause*>* update_vec;
	std::vector<hsql::Expr*>* expr_vec;
	std::vector<hsql::OrderDescription*>* order_vec;
	std::vector<hsql::WithDescription*>* with_description_vec;

#line 394 "bison_parser.cpp"

};
typedef union HSQL_STYPE HSQL_STYPE;
# define HSQL_STYPE_IS_TRIVIAL 1
# define HSQL_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HSQL_LTYPE && ! defined HSQL_LTYPE_IS_DECLARED
typedef struct HSQL_LTYPE HSQL_LTYPE;
struct HSQL_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HSQL_LTYPE_IS_DECLARED 1
# define HSQL_LTYPE_IS_TRIVIAL 1
#endif



int hsql_parse (hsql::SQLParserResult* result, yyscan_t scanner);

#endif /* !YY_HSQL_BISON_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL \
             && defined HSQL_STYPE_IS_TRIVIAL && HSQL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   785

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  271
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  494

#define YYUNDEFTOK  2
#define YYMAXUTOK   408


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   160,     2,     2,
     165,   166,   158,   156,   169,   157,   167,   159,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   168,
     149,   146,   150,   170,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   163,     2,   164,   161,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   147,   148,   151,   152,   153,   154,   155,   162
};

#if HSQL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   269,   269,   290,   296,   305,   309,   313,   316,   319,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   343,
     344,   349,   350,   354,   358,   370,   373,   376,   382,   383,
     390,   397,   400,   404,   418,   424,   433,   450,   454,   457,
     466,   480,   483,   488,   493,   505,   518,   525,   532,   540,
     547,   548,   552,   553,   557,   558,   565,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   589,   590,   591,   595,
     596,   599,   602,   603,   613,   619,   625,   630,   637,   638,
     647,   656,   669,   676,   687,   688,   698,   707,   708,   712,
     724,   728,   732,   746,   747,   750,   751,   762,   763,   767,
     777,   790,   797,   801,   805,   812,   815,   821,   833,   834,
     838,   842,   843,   847,   852,   853,   857,   862,   866,   867,
     871,   872,   876,   877,   881,   885,   886,   887,   893,   894,
     898,   899,   900,   901,   902,   903,   910,   911,   915,   916,
     920,   921,   925,   935,   936,   937,   938,   939,   943,   944,
     945,   946,   947,   948,   949,   950,   951,   952,   953,   957,
     958,   962,   963,   964,   965,   966,   970,   971,   972,   973,
     974,   975,   976,   977,   978,   979,   980,   984,   985,   989,
     990,   991,   992,   998,   999,  1000,  1001,  1005,  1006,  1010,
    1011,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1025,  1026,
    1030,  1034,  1038,  1039,  1040,  1041,  1042,  1043,  1047,  1051,
    1055,  1059,  1060,  1061,  1062,  1066,  1067,  1068,  1069,  1070,
    1074,  1078,  1079,  1083,  1084,  1088,  1092,  1096,  1108,  1109,
    1119,  1120,  1124,  1125,  1134,  1135,  1140,  1151,  1160,  1161,
    1166,  1167,  1172,  1173,  1178,  1179,  1184,  1185,  1194,  1195,
    1199,  1203,  1207,  1214,  1227,  1235,  1245,  1264,  1265,  1266,
    1267,  1268,  1269,  1270,  1271,  1272,  1273,  1278,  1287,  1288,
    1293,  1294
};
#endif

#if HSQL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "FLOATVAL",
  "INTVAL", "DEALLOCATE", "PARAMETERS", "INTERSECT", "TEMPORARY",
  "TIMESTAMP", "DISTINCT", "NVARCHAR", "RESTRICT", "TRUNCATE", "ANALYZE",
  "BETWEEN", "CASCADE", "COLUMNS", "CONTROL", "DEFAULT", "EXECUTE",
  "EXPLAIN", "INTEGER", "NATURAL", "PREPARE", "PRIMARY", "SCHEMAS",
  "SPATIAL", "VARCHAR", "VIRTUAL", "DESCRIBE", "BEFORE", "COLUMN",
  "CREATE", "DELETE", "DIRECT", "DOUBLE", "ESCAPE", "EXCEPT", "EXISTS",
  "EXTRACT", "CAST", "FORMAT", "GLOBAL", "HAVING", "IMPORT", "INSERT",
  "ISNULL", "OFFSET", "RENAME", "SCHEMA", "SELECT", "SORTED", "TABLES",
  "UNIQUE", "UNLOAD", "UPDATE", "VALUES", "AFTER", "ALTER", "CROSS",
  "DELTA", "FLOAT", "GROUP", "INDEX", "INNER", "LIMIT", "LOCAL", "MERGE",
  "MINUS", "ORDER", "OUTER", "RIGHT", "TABLE", "UNION", "USING", "WHERE",
  "CALL", "CASE", "CHAR", "COPY", "DATE", "DATETIME", "DESC", "DROP",
  "ELSE", "FILE", "FROM", "FULL", "HASH", "HINT", "INTO", "JOIN", "LEFT",
  "LIKE", "LOAD", "LONG", "NULL", "PLAN", "SHOW", "TEXT", "THEN", "TIME",
  "VIEW", "WHEN", "WITH", "ADD", "ALL", "AND", "ASC", "END", "FOR", "INT",
  "KEY", "NOT", "OFF", "SET", "TOP", "AS", "BY", "IF", "IN", "IS", "OF",
  "ON", "OR", "TO", "ARRAY", "CONCAT", "ILIKE", "SECOND", "MINUTE", "HOUR",
  "DAY", "MONTH", "YEAR", "TRUE", "FALSE", "TRANSACTION", "BEGIN",
  "COMMIT", "ROLLBACK", "DATABASE", "DATABASES", "'='", "EQUALS",
  "NOTEQUALS", "'<'", "'>'", "LESS", "GREATER", "LESSEQ", "GREATEREQ",
  "NOTNULL", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "UMINUS", "'['",
  "']'", "'('", "')'", "'.'", "';'", "','", "'?'", "$accept", "input",
  "statement_list", "statement", "preparable_statement", "opt_hints",
  "hint_list", "hint", "transaction_statement", "opt_transaction_keyword",
  "prepare_statement", "prepare_target_query", "execute_statement",
  "import_statement", "file_type", "file_path", "opt_file_type",
  "export_statement", "show_statement", "create_statement",
  "opt_not_exists", "column_def_commalist", "column_def", "column_type",
  "opt_column_nullable", "opt_unique", "opt_primary", "key_columns",
  "drop_statement", "opt_exists", "delete_statement", "truncate_statement",
  "insert_statement", "opt_column_list", "update_statement",
  "update_clause_commalist", "update_clause", "select_statement",
  "select_within_set_operation",
  "select_within_set_operation_no_parentheses", "select_with_paren",
  "select_no_paren", "set_operator", "set_type", "opt_all",
  "select_clause", "opt_distinct", "select_list", "opt_from_clause",
  "from_clause", "opt_where", "opt_group", "opt_having", "opt_order",
  "order_list", "order_desc", "opt_order_type", "opt_top", "opt_limit",
  "expr_list", "opt_literal_list", "literal_list", "expr_alias", "expr",
  "operand", "scalar_expr", "unary_expr", "binary_expr", "logic_expr",
  "in_expr", "case_expr", "case_list", "exists_expr", "comp_expr",
  "function_expr", "extract_expr", "cast_expr", "datetime_field",
  "array_expr", "array_index", "between_expr", "column_name", "literal",
  "string_literal", "bool_literal", "num_literal", "int_literal",
  "null_literal", "param_expr", "table_ref", "table_ref_atomic",
  "nonjoin_table_ref_atomic", "table_ref_commalist", "table_ref_name",
  "table_ref_name_no_alias", "table_name", "table_alias",
  "opt_table_alias", "alias", "opt_alias", "opt_with_clause",
  "with_clause", "with_description_list", "with_description",
  "join_clause", "opt_join_type", "join_condition", "opt_semicolon",
  "ident_commalist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,    61,   401,   402,    60,
      62,   403,   404,   405,   406,   407,    43,    45,    42,    47,
      37,    94,   408,    91,    93,    40,    41,    46,    59,    44,
      63
};
# endif

#define YYPACT_NINF (-393)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-269)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     532,    51,   157,   177,   180,   157,   -50,    29,    39,    97,
     157,   157,   -48,     3,   193,    81,    81,    81,   208,    41,
    -393,   126,  -393,   126,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,   -20,  -393,   225,    86,  -393,
      87,   175,  -393,   159,   159,   269,   157,   283,   157,   174,
    -393,   -46,   178,   178,   302,   157,  -393,  -393,   192,   145,
    -393,  -393,  -393,  -393,  -393,  -393,   527,  -393,   226,  -393,
    -393,   198,   -20,    30,  -393,    23,  -393,   316,     8,   317,
     206,   157,   157,  -393,   246,  -393,   237,   166,   333,   331,
     331,   296,   157,   157,  -393,  -393,   179,   193,  -393,   181,
     336,   337,   188,   189,  -393,  -393,  -393,   -20,   236,   235,
     -20,    55,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
     195,   191,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,   306,   -52,   166,   254,  -393,   331,   355,    56,   216,
     -57,  -393,   262,  -393,   262,  -393,  -393,  -393,  -393,  -393,
     368,  -393,  -393,   254,  -393,  -393,   300,  -393,  -393,    30,
    -393,  -393,   254,   300,   254,   146,  -393,  -393,     8,  -393,
     370,   272,    48,   260,   -38,   219,   220,   221,   150,   324,
     218,   335,  -393,   194,    54,   372,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,   294,  -393,  -131,   223,  -393,   254,   333,  -393,
     353,  -393,  -393,   233,   -49,  -393,   311,   232,  -393,    57,
      55,   -20,   234,  -393,    84,    55,    54,   358,   -24,  -393,
     314,  -393,   352,  -393,  -393,    -7,  -393,   295,   298,   272,
       6,    16,   356,   377,   254,   254,   -34,    13,   249,   335,
     561,   254,    80,   251,   -87,   254,   254,   335,  -393,   335,
     -35,   253,    69,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   336,   157,
    -393,   417,     8,    54,  -393,   283,     8,  -393,   368,    14,
     246,  -393,   254,  -393,   422,  -393,  -393,  -393,  -393,   254,
    -393,  -393,  -393,  -393,   254,   254,   331,  -393,   263,  -393,
    -393,   264,  -393,  -393,  -393,  -393,   118,  -393,    48,   427,
     266,  -393,  -393,   254,  -393,  -393,   271,  -393,  -393,  -393,
    -393,  -393,  -393,   343,   104,   102,    95,   254,   254,  -393,
     356,   339,    63,  -393,  -393,  -393,   328,   495,   582,   335,
     274,   194,  -393,   342,   279,   582,   582,   582,   582,   622,
     622,   622,   622,    80,    80,   -74,   -74,   -74,   -66,   281,
    -393,  -393,    85,  -393,   107,  -393,   272,  -393,   301,  -393,
     277,  -393,    38,  -393,   378,  -393,  -393,  -393,    54,    54,
    -393,   441,   442,  -393,   359,  -393,  -393,   287,   454,   114,
    -393,   254,   352,   254,   254,  -393,   134,   115,   299,  -393,
     335,   582,   194,   303,   121,  -393,  -393,  -393,  -393,   305,
     366,  -393,  -393,  -393,   388,   394,   402,   384,    14,   473,
    -393,  -393,  -393,   362,  -393,   313,   318,  -393,   454,  -393,
     125,  -393,   -68,   319,    54,   138,  -393,   254,  -393,   561,
     320,   132,  -393,  -393,    38,    14,  -393,  -393,  -393,    14,
     332,   315,   254,  -393,  -393,   133,  -393,   484,  -393,  -393,
    -393,    54,  -393,  -393,  -393,  -393,   382,   355,   -12,  -393,
    -393,   325,   254,   140,   254,  -393,    17,    54,  -393,  -393,
      54,   330,   338,  -393
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    29,    29,     0,   269,
       3,    20,    18,    20,    17,     8,     9,     7,    11,    16,
      13,    14,    12,    15,    10,     0,   248,     0,   238,    81,
      32,     0,    43,    51,    51,     0,     0,     0,     0,     0,
     237,     0,    79,    79,     0,     0,    41,    44,     0,   250,
     251,    28,    25,    27,    26,     1,   249,     2,     0,     6,
       5,   129,     0,    90,    91,   121,    76,     0,   139,     0,
       0,     0,     0,    49,   115,    36,     0,    85,     0,     0,
       0,     0,     0,     0,    77,    42,     0,     0,     4,     0,
       0,   109,     0,     0,   103,   104,   102,     0,   106,     0,
       0,   135,   239,   220,   223,   225,   226,   221,   222,   227,
       0,   138,   140,   215,   216,   217,   224,   218,   219,    31,
      30,     0,     0,    85,     0,    80,     0,     0,     0,     0,
     115,    87,    39,    37,    39,    78,    74,    75,   253,   252,
       0,   128,   108,     0,    98,    97,   121,    94,    93,    95,
     105,   101,     0,   121,     0,     0,    99,    33,     0,    50,
       0,   249,    70,     0,   211,     0,     0,     0,     0,     0,
       0,     0,   213,     0,   114,   143,   150,   151,   152,   145,
     147,   153,   146,   166,   154,   155,   156,   157,   149,   144,
     159,   160,     0,   270,     0,     0,    83,     0,     0,    86,
       0,    35,    40,    23,     0,    21,   112,   110,   136,   247,
     135,     0,   120,   122,   127,   135,   131,   133,   130,   141,
       0,    47,     0,    71,    69,     0,    52,     0,     0,   249,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,   161,     0,     0,     0,     0,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,    89,    88,     0,     0,    19,     0,     0,
     115,   111,     0,   245,     0,   246,   142,    92,    96,     0,
     126,   125,   124,   100,     0,     0,     0,    58,     0,    61,
      60,     0,    65,    59,    64,    57,    68,    46,    70,     0,
       0,    48,   198,     0,   212,   214,     0,   202,   203,   204,
     205,   206,   207,     0,     0,     0,     0,     0,     0,   185,
       0,     0,     0,   158,   148,   177,   178,     0,   173,     0,
       0,     0,   164,     0,   176,   175,   191,   192,   193,   194,
     195,   196,   197,   168,   167,   170,   169,   171,   172,     0,
      34,   271,     0,    38,     0,    22,   249,   113,   228,   230,
       0,   232,   243,   231,   117,   137,   244,   123,   134,   132,
      45,     0,     0,    66,     0,    54,    53,     0,     0,     0,
     189,     0,     0,     0,     0,   183,     0,     0,     0,   208,
       0,   174,     0,     0,     0,   165,   209,    82,    24,     0,
       0,   265,   257,   263,   261,   264,   259,     0,     0,     0,
     242,   236,   240,     0,   107,     0,     0,    67,     0,    72,
       0,   199,     0,     0,   187,     0,   186,     0,   190,   210,
       0,     0,   181,   179,   243,     0,   260,   262,   258,     0,
     229,   244,     0,    62,    63,     0,    56,     0,   200,   201,
     184,   188,   182,   180,   233,   254,   266,     0,   119,    55,
      73,     0,     0,     0,     0,   116,     0,   267,   255,   241,
     118,   211,     0,   256
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -393,  -393,  -393,   425,  -393,   475,  -393,   211,  -393,    68,
    -393,  -393,  -393,  -393,   222,   -83,   371,  -393,  -393,  -393,
     462,  -393,   199,   122,  -393,  -393,  -393,    78,  -393,   470,
    -393,  -393,  -393,   403,  -393,  -393,   329,  -156,   -60,  -393,
      -6,   -69,   -51,  -393,  -393,   -45,   308,  -393,  -393,  -393,
    -124,  -393,  -393,   -85,  -393,   239,  -393,  -393,    43,  -249,
    -393,   -80,   248,  -134,  -133,  -393,  -393,  -393,  -393,  -393,
    -393,   297,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,    59,   -67,   -84,  -393,  -393,   -92,  -393,  -393,  -393,
    -392,    91,  -393,  -393,  -393,    -1,  -393,    96,   322,  -393,
    -393,  -393,  -393,   455,  -393,  -393,  -393,  -393,    74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,    21,    69,   214,   215,    22,    62,
      23,   130,    24,    25,    86,   142,   211,    26,    27,    28,
      81,   235,   236,   316,   395,   237,   238,   440,    29,    92,
      30,    31,    32,   138,    33,   140,   141,    34,   156,   157,
     158,    74,   107,   108,   161,    75,   153,   216,   290,   291,
     135,   434,   485,   111,   222,   223,   302,   101,   166,   217,
     120,   121,   218,   219,   185,   186,   187,   188,   189,   190,
     191,   247,   192,   193,   194,   195,   196,   333,   197,   198,
     199,   200,   201,   123,   124,   125,   126,   127,   128,   377,
     378,   379,   380,   381,    49,   382,   430,   431,   432,   296,
      35,    36,    59,    60,   383,   427,   488,    67,   204
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     184,    39,   342,   103,    42,   143,   143,   144,   151,    50,
      51,   122,   113,   114,   115,   231,   209,    38,   152,   324,
     491,   134,    55,   255,   110,    43,   305,    52,   224,    73,
     226,   228,   104,    71,   484,   280,   460,   170,   281,   104,
     256,   293,   255,    89,   246,    84,   250,    87,   252,   254,
     163,   232,   143,   202,    95,    44,   263,    53,    56,   256,
     293,   349,   159,   105,   263,   159,   102,   476,   171,   206,
     105,   220,   245,   283,   399,   233,   255,    37,   225,   344,
     132,   133,    90,   321,    63,    64,   255,   277,   350,   278,
     148,   146,   147,   256,    45,   109,    54,   278,   468,   106,
     337,   229,   414,   256,   234,   164,   106,   116,   221,    71,
     334,   335,   208,   172,   253,   205,   250,   287,    46,   338,
     288,   345,   346,   165,   347,   339,   348,   240,    47,   241,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,    72,   117,   118,    57,   174,
     113,   114,   115,   174,   113,   114,   115,   292,   429,   317,
      38,   298,   318,   451,   255,   224,   384,   255,   352,   300,
     388,   389,   322,   326,   325,   182,   159,   294,   119,   376,
      40,   256,   404,    41,   256,   353,   369,   175,   176,   177,
      48,   175,   176,   177,   255,   301,    58,   174,   113,   114,
     115,   338,   372,   406,   407,   403,   374,   405,    65,    66,
     263,   256,   255,   478,   255,   122,   411,   393,   447,   122,
     419,    61,   143,   390,   402,   255,   178,   409,    76,   256,
     178,   256,   292,    68,   394,   175,   176,   177,   274,   275,
     276,   277,   256,   278,   255,   116,   446,    71,   255,   116,
     470,   417,    78,    77,   168,   227,   245,   174,   113,   114,
     115,   256,   179,   297,    79,   256,   179,   442,   303,   444,
     445,   408,    83,   418,   178,   180,   168,   449,   370,   180,
     441,    80,   413,   292,   117,   118,    85,   453,   117,   118,
     292,   466,    88,   116,   467,   175,   176,   177,   473,   479,
      91,   292,   467,   181,   182,    94,   489,   181,   182,   281,
     179,   183,    96,   471,    97,   183,   119,   100,    99,   112,
     119,   129,   131,   180,   134,   136,   420,   174,   113,   114,
     115,   137,   117,   118,   178,   113,   139,   145,   174,   113,
     114,   115,   115,   450,    72,   160,   150,   169,   487,   152,
     490,   181,   182,   116,   154,   155,   162,   420,   203,   183,
     168,   167,   207,   421,   119,   248,   176,   177,   422,   210,
     179,   213,   109,   230,   423,   424,   307,   176,   177,    14,
     239,   251,   308,   180,   242,   243,   244,   279,   282,   257,
     309,   425,   117,   118,   421,  -266,   426,   285,   286,   422,
     289,   292,   306,   299,   178,   423,   424,   420,   304,    71,
     319,   181,   182,   320,   340,   178,   310,   343,   351,   183,
     371,   258,   425,   116,   119,   386,  -266,   426,   391,   392,
     397,   398,   401,   311,   116,   349,   312,   400,   255,   412,
     249,   415,   278,   433,   421,   416,   428,   435,   436,   422,
     313,   249,   438,   180,   314,   423,   424,   439,   437,   481,
     455,   456,   117,   118,   180,   448,   315,   457,   259,   452,
    -234,   454,   425,   117,   118,   458,   461,   426,   459,   463,
     477,   181,   182,   462,   464,   469,   472,   480,   260,   183,
     486,    98,   181,   182,   119,   261,   262,   241,    70,   375,
     183,  -235,   263,   264,   493,   119,    82,   373,   482,   327,
     328,   329,   330,   331,   332,   212,   465,   396,   265,   266,
     267,   268,   269,    93,   443,   270,   271,  -268,   272,   273,
     274,   275,   276,   277,     1,   278,   173,   284,   387,     1,
     385,   295,     2,   336,   258,   492,   475,     2,   323,     3,
     474,   483,   149,     4,     3,     0,     0,     0,     4,     5,
       0,     0,     6,     7,     5,     0,     0,     6,     7,     0,
       0,     0,     0,     0,     8,     9,     0,     0,     0,     8,
       9,     0,     0,     0,     0,    10,     0,     0,     0,     0,
      10,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   410,     0,     0,     0,    11,
     258,   341,     0,    12,    11,     0,     0,     0,    12,   262,
       0,     0,     0,     0,     0,   263,   264,     0,    13,     0,
       0,   258,     0,    13,    14,     0,     0,     0,     0,    14,
       0,   265,   266,   267,   268,   269,     0,     0,   270,   271,
       0,   272,   273,   274,   275,   276,   277,   259,   278,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    16,
      17,   258,     0,    15,    16,    17,     0,   341,  -269,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   265,   266,   267,
     268,   269,   263,  -269,   270,   271,     0,   272,   273,   274,
     275,   276,   277,     0,   278,     0,     0,     0,  -269,  -269,
    -269,   268,   269,     0,     0,   270,   271,     0,   272,   273,
     274,   275,   276,   277,     0,   278,   262,     0,     0,     0,
       0,     0,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -269,  -269,     0,     0,  -269,  -269,     0,   272,   273,
     274,   275,   276,   277,     0,   278
};

static const yytype_int16 yycheck[] =
{
     134,     2,   251,    72,     5,    89,    90,    90,   100,    10,
      11,    78,     4,     5,     6,   171,   140,     3,    12,     3,
       3,    78,    19,   110,    75,    75,    50,    75,   162,    35,
     164,   165,     9,    53,    46,   166,   428,    89,   169,     9,
     127,     3,   110,    89,   178,    46,   179,    48,   181,   183,
     110,     3,   136,   136,    55,   105,   130,   105,    55,   127,
       3,    96,   107,    40,   130,   110,    72,   459,   120,   138,
      40,   156,   106,   207,   323,    27,   110,    26,   163,   166,
      81,    82,   128,   239,    16,    17,   110,   161,   123,   163,
      96,    92,    93,   127,   144,    72,   144,   163,   166,    76,
      87,   168,   351,   127,    56,    50,    76,    99,   159,    53,
     244,   245,   169,   165,   183,    59,   249,   166,    89,   106,
     169,   255,   256,    68,   257,   112,   259,   165,    89,   167,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   165,   138,   139,   145,     3,
       4,     5,     6,     3,     4,     5,     6,   169,   120,   166,
       3,   221,   169,   412,   110,   299,   290,   110,    99,    85,
     304,   305,   166,   242,   158,   158,   221,   120,   170,   165,
       3,   127,    87,     3,   127,   116,   278,    41,    42,    43,
      93,    41,    42,    43,   110,   111,     3,     3,     4,     5,
       6,   106,   282,   337,   338,   103,   286,   112,     0,   168,
     130,   127,   110,   462,   110,   282,   349,    99,   103,   286,
     376,   140,   306,   306,   120,   110,    80,   164,     3,   127,
      80,   127,   169,   107,   116,    41,    42,    43,   158,   159,
     160,   161,   127,   163,   110,    99,   112,    53,   110,    99,
     112,   166,   165,   167,   169,   109,   106,     3,     4,     5,
       6,   127,   116,   220,    89,   127,   116,   401,   225,   403,
     404,   340,     3,   166,    80,   129,   169,   410,   279,   129,
     166,   122,   351,   169,   138,   139,     3,   166,   138,   139,
     169,   166,   118,    99,   169,    41,    42,    43,   166,   166,
     122,   169,   169,   157,   158,     3,   166,   157,   158,   169,
     116,   165,   120,   447,   169,   165,   170,   119,    92,     3,
     170,     4,   116,   129,    78,    88,    25,     3,     4,     5,
       6,   165,   138,   139,    80,     4,     3,    41,     3,     4,
       5,     6,     6,   412,   165,   109,   165,    41,   482,    12,
     484,   157,   158,    99,   166,   166,   121,    25,     3,   165,
     169,   166,   146,    62,   170,    41,    42,    43,    67,   107,
     116,     3,    72,     3,    73,    74,    24,    42,    43,   107,
     120,   163,    30,   129,   165,   165,   165,    93,   165,    17,
      38,    90,   138,   139,    62,    94,    95,    44,   165,    67,
      89,   169,    88,   169,    80,    73,    74,    25,    50,    53,
     115,   157,   158,   115,   165,    80,    64,   166,   165,   165,
       3,    49,    90,    99,   170,     3,    94,    95,   165,   165,
       3,   165,    89,    81,    99,    96,    84,   166,   110,   165,
     116,    99,   163,    65,    62,   164,   169,     6,     6,    67,
      98,   116,   165,   129,   102,    73,    74,     3,    99,    77,
      94,    73,   138,   139,   129,   166,   114,    73,    96,   166,
     169,   166,    90,   138,   139,    73,     3,    95,    94,   166,
     165,   157,   158,   121,   166,   166,   166,     3,   116,   165,
     165,    66,   157,   158,   170,   123,   124,   167,    23,   288,
     165,   169,   130,   131,   166,   170,    44,   285,   126,   132,
     133,   134,   135,   136,   137,   144,   438,   318,   146,   147,
     148,   149,   150,    53,   402,   153,   154,     0,   156,   157,
     158,   159,   160,   161,     7,   163,   133,   208,   299,     7,
     292,   219,    15,   246,    49,   486,   455,    15,   240,    22,
     454,   477,    97,    26,    22,    -1,    -1,    -1,    26,    32,
      -1,    -1,    35,    36,    32,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      58,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    82,
      49,   116,    -1,    86,    82,    -1,    -1,    -1,    86,   124,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   101,    -1,
      -1,    49,    -1,   101,   107,    -1,    -1,    -1,    -1,   107,
      -1,   146,   147,   148,   149,   150,    -1,    -1,   153,   154,
      -1,   156,   157,   158,   159,   160,   161,    96,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,    49,    -1,   141,   142,   143,    -1,   116,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   146,   147,   148,
     149,   150,   130,   131,   153,   154,    -1,   156,   157,   158,
     159,   160,   161,    -1,   163,    -1,    -1,    -1,   146,   147,
     148,   149,   150,    -1,    -1,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,   163,   124,    -1,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,    -1,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,   163
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     7,    15,    22,    26,    32,    35,    36,    47,    48,
      58,    82,    86,   101,   107,   141,   142,   143,   172,   173,
     174,   175,   179,   181,   183,   184,   188,   189,   190,   199,
     201,   202,   203,   205,   208,   271,   272,    26,     3,   266,
       3,     3,   266,    75,   105,   144,    89,    89,    93,   265,
     266,   266,    75,   105,   144,    19,    55,   145,     3,   273,
     274,   140,   180,   180,   180,     0,   168,   278,   107,   176,
     176,    53,   165,   211,   212,   216,     3,   167,   165,    89,
     122,   191,   191,     3,   266,     3,   185,   266,   118,    89,
     128,   122,   200,   200,     3,   266,   120,   169,   174,    92,
     119,   228,   211,   212,     9,    40,    76,   213,   214,    72,
     213,   224,     3,     4,     5,     6,    99,   138,   139,   170,
     231,   232,   253,   254,   255,   256,   257,   258,   259,     4,
     182,   116,   266,   266,    78,   221,    88,   165,   204,     3,
     206,   207,   186,   254,   186,    41,   266,   266,   211,   274,
     165,   257,    12,   217,   166,   166,   209,   210,   211,   216,
     109,   215,   121,   209,    50,    68,   229,   166,   169,    41,
      89,   120,   165,   204,     3,    41,    42,    43,    80,   116,
     129,   157,   158,   165,   234,   235,   236,   237,   238,   239,
     240,   241,   243,   244,   245,   246,   247,   249,   250,   251,
     252,   253,   186,     3,   279,    59,   212,   146,   169,   221,
     107,   187,   187,     3,   177,   178,   218,   230,   233,   234,
     224,   213,   225,   226,   234,   224,   234,   109,   234,   253,
       3,   208,     3,    27,    56,   192,   193,   196,   197,   120,
     165,   167,   165,   165,   165,   106,   234,   242,    41,   116,
     235,   163,   235,   212,   234,   110,   127,    17,    49,    96,
     116,   123,   124,   130,   131,   146,   147,   148,   149,   150,
     153,   154,   156,   157,   158,   159,   160,   161,   163,    93,
     166,   169,   165,   234,   207,    44,   165,   166,   169,    89,
     219,   220,   169,     3,   120,   269,   270,   229,   209,   169,
      85,   111,   227,   229,    50,    50,    88,    24,    30,    38,
      64,    81,    84,    98,   102,   114,   194,   166,   169,   115,
     115,   208,   166,   217,     3,   158,   212,   132,   133,   134,
     135,   136,   137,   248,   234,   234,   242,    87,   106,   112,
     165,   116,   230,   166,   166,   234,   234,   235,   235,    96,
     123,   165,    99,   116,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   257,
     266,     3,   232,   185,   232,   178,   165,   260,   261,   262,
     263,   264,   266,   275,   221,   233,     3,   226,   234,   234,
     186,   165,   165,    99,   116,   195,   193,     3,   165,   230,
     166,    89,   120,   103,    87,   112,   234,   234,   212,   164,
     110,   235,   165,   212,   230,    99,   164,   166,   166,   208,
      25,    62,    67,    73,    74,    90,    95,   276,   169,   120,
     267,   268,   269,    65,   222,     6,     6,    99,   165,     3,
     198,   166,   234,   194,   234,   234,   112,   103,   166,   235,
     212,   230,   166,   166,   166,    94,    73,    73,    73,    94,
     261,     3,   121,   166,   166,   198,   166,   169,   166,   166,
     112,   234,   166,   166,   268,   262,   261,   165,   230,   166,
       3,    77,   126,   279,    46,   223,   165,   234,   277,   166,
     234,     3,   252,   166
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   171,   172,   173,   173,   174,   174,   174,   174,   174,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   176,
     176,   177,   177,   178,   178,   179,   179,   179,   180,   180,
     181,   182,   183,   183,   184,   184,   185,   186,   187,   187,
     188,   189,   189,   189,   189,   190,   190,   190,   190,   190,
     191,   191,   192,   192,   193,   193,   193,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   195,   195,   195,   196,
     196,   197,   198,   198,   199,   199,   199,   199,   200,   200,
     201,   202,   203,   203,   204,   204,   205,   206,   206,   207,
     208,   208,   208,   209,   209,   210,   210,   211,   211,   212,
     212,   213,   214,   214,   214,   215,   215,   216,   217,   217,
     218,   219,   219,   220,   221,   221,   222,   222,   223,   223,
     224,   224,   225,   225,   226,   227,   227,   227,   228,   228,
     229,   229,   229,   229,   229,   229,   230,   230,   231,   231,
     232,   232,   233,   234,   234,   234,   234,   234,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   236,
     236,   237,   237,   237,   237,   237,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   239,   239,   240,
     240,   240,   240,   241,   241,   241,   241,   242,   242,   243,
     243,   244,   244,   244,   244,   244,   244,   244,   245,   245,
     246,   247,   248,   248,   248,   248,   248,   248,   249,   250,
     251,   252,   252,   252,   252,   253,   253,   253,   253,   253,
     254,   255,   255,   256,   256,   257,   258,   259,   260,   260,
     261,   261,   262,   262,   263,   263,   264,   265,   266,   266,
     267,   267,   268,   268,   269,   269,   270,   270,   271,   271,
     272,   273,   273,   274,   275,   275,   275,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   277,   278,   278,
     279,   279
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       0,     1,     3,     1,     4,     2,     2,     2,     1,     0,
       4,     1,     2,     5,     7,     5,     1,     1,     3,     0,
       5,     2,     3,     2,     2,     8,     7,     6,     7,     3,
       3,     0,     1,     3,     3,     6,     5,     1,     1,     1,
       1,     1,     4,     4,     1,     1,     1,     2,     0,     1,
       0,     1,     1,     3,     4,     4,     3,     3,     2,     0,
       4,     2,     8,     5,     3,     0,     5,     1,     3,     3,
       2,     2,     6,     1,     1,     1,     3,     3,     3,     3,
       5,     2,     1,     1,     1,     1,     0,     7,     1,     0,
       1,     1,     0,     2,     2,     0,     4,     0,     2,     0,
       3,     0,     1,     3,     2,     1,     1,     0,     2,     0,
       2,     2,     4,     2,     4,     0,     1,     3,     1,     0,
       1,     3,     2,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     2,     2,     2,     3,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     3,     3,     3,     5,
       6,     5,     6,     4,     6,     3,     5,     4,     5,     4,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       6,     6,     1,     1,     1,     1,     1,     1,     4,     4,
       5,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     4,     1,     3,     2,     1,     1,     3,
       1,     5,     1,     0,     2,     1,     1,     0,     1,     0,
       2,     1,     3,     3,     4,     6,     8,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     0,     1,     1,     0,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if HSQL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, hsql::SQLParserResult* result, yyscan_t scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HSQL_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HSQL_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
    case 3: /* IDENTIFIER  */
#line 149 "bison_parser.y"
            { free( (((*yyvaluep).sval)) ); }
#line 1871 "bison_parser.cpp"
        break;

    case 4: /* STRING  */
#line 149 "bison_parser.y"
            { free( (((*yyvaluep).sval)) ); }
#line 1877 "bison_parser.cpp"
        break;

    case 5: /* FLOATVAL  */
#line 147 "bison_parser.y"
            { }
#line 1883 "bison_parser.cpp"
        break;

    case 6: /* INTVAL  */
#line 147 "bison_parser.y"
            { }
#line 1889 "bison_parser.cpp"
        break;

    case 173: /* statement_list  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).stmt_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).stmt_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).stmt_vec));
}
#line 1902 "bison_parser.cpp"
        break;

    case 174: /* statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).statement)); }
#line 1908 "bison_parser.cpp"
        break;

    case 175: /* preparable_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).statement)); }
#line 1914 "bison_parser.cpp"
        break;

    case 176: /* opt_hints  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1927 "bison_parser.cpp"
        break;

    case 177: /* hint_list  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1940 "bison_parser.cpp"
        break;

    case 178: /* hint  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 1946 "bison_parser.cpp"
        break;

    case 179: /* transaction_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).transaction_stmt)); }
#line 1952 "bison_parser.cpp"
        break;

    case 181: /* prepare_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).prep_stmt)); }
#line 1958 "bison_parser.cpp"
        break;

    case 182: /* prepare_target_query  */
#line 149 "bison_parser.y"
            { free( (((*yyvaluep).sval)) ); }
#line 1964 "bison_parser.cpp"
        break;

    case 183: /* execute_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).exec_stmt)); }
#line 1970 "bison_parser.cpp"
        break;

    case 184: /* import_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).import_stmt)); }
#line 1976 "bison_parser.cpp"
        break;

    case 185: /* file_type  */
#line 147 "bison_parser.y"
            { }
#line 1982 "bison_parser.cpp"
        break;

    case 186: /* file_path  */
#line 149 "bison_parser.y"
            { free( (((*yyvaluep).sval)) ); }
#line 1988 "bison_parser.cpp"
        break;

    case 187: /* opt_file_type  */
#line 147 "bison_parser.y"
            { }
#line 1994 "bison_parser.cpp"
        break;

    case 188: /* export_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).export_stmt)); }
#line 2000 "bison_parser.cpp"
        break;

    case 189: /* show_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).show_stmt)); }
#line 2006 "bison_parser.cpp"
        break;

    case 190: /* create_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).create_stmt)); }
#line 2012 "bison_parser.cpp"
        break;

    case 191: /* opt_not_exists  */
#line 147 "bison_parser.y"
            { }
#line 2018 "bison_parser.cpp"
        break;

    case 192: /* column_def_commalist  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).column_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).column_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).column_vec));
}
#line 2031 "bison_parser.cpp"
        break;

    case 193: /* column_def  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).column_t)); }
#line 2037 "bison_parser.cpp"
        break;

    case 194: /* column_type  */
#line 147 "bison_parser.y"
            { }
#line 2043 "bison_parser.cpp"
        break;

    case 195: /* opt_column_nullable  */
#line 147 "bison_parser.y"
            { }
#line 2049 "bison_parser.cpp"
        break;

    case 196: /* opt_unique  */
#line 147 "bison_parser.y"
            { }
#line 2055 "bison_parser.cpp"
        break;

    case 197: /* opt_primary  */
#line 147 "bison_parser.y"
            { }
#line 2061 "bison_parser.cpp"
        break;

    case 198: /* key_columns  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).str_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 2074 "bison_parser.cpp"
        break;

    case 199: /* drop_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).drop_stmt)); }
#line 2080 "bison_parser.cpp"
        break;

    case 200: /* opt_exists  */
#line 147 "bison_parser.y"
            { }
#line 2086 "bison_parser.cpp"
        break;

    case 201: /* delete_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).delete_stmt)); }
#line 2092 "bison_parser.cpp"
        break;

    case 202: /* truncate_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).delete_stmt)); }
#line 2098 "bison_parser.cpp"
        break;

    case 203: /* insert_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).insert_stmt)); }
#line 2104 "bison_parser.cpp"
        break;

    case 204: /* opt_column_list  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).str_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 2117 "bison_parser.cpp"
        break;

    case 205: /* update_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).update_stmt)); }
#line 2123 "bison_parser.cpp"
        break;

    case 206: /* update_clause_commalist  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).update_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).update_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).update_vec));
}
#line 2136 "bison_parser.cpp"
        break;

    case 207: /* update_clause  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).update_t)); }
#line 2142 "bison_parser.cpp"
        break;

    case 208: /* select_statement  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).select_stmt)); }
#line 2148 "bison_parser.cpp"
        break;

    case 209: /* select_within_set_operation  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).select_stmt)); }
#line 2154 "bison_parser.cpp"
        break;

    case 210: /* select_within_set_operation_no_parentheses  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).select_stmt)); }
#line 2160 "bison_parser.cpp"
        break;

    case 211: /* select_with_paren  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).select_stmt)); }
#line 2166 "bison_parser.cpp"
        break;

    case 212: /* select_no_paren  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).select_stmt)); }
#line 2172 "bison_parser.cpp"
        break;

    case 213: /* set_operator  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).set_operator_t)); }
#line 2178 "bison_parser.cpp"
        break;

    case 214: /* set_type  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).set_operator_t)); }
#line 2184 "bison_parser.cpp"
        break;

    case 215: /* opt_all  */
#line 147 "bison_parser.y"
            { }
#line 2190 "bison_parser.cpp"
        break;

    case 216: /* select_clause  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).select_stmt)); }
#line 2196 "bison_parser.cpp"
        break;

    case 217: /* opt_distinct  */
#line 147 "bison_parser.y"
            { }
#line 2202 "bison_parser.cpp"
        break;

    case 218: /* select_list  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2215 "bison_parser.cpp"
        break;

    case 219: /* opt_from_clause  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).table)); }
#line 2221 "bison_parser.cpp"
        break;

    case 220: /* from_clause  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).table)); }
#line 2227 "bison_parser.cpp"
        break;

    case 221: /* opt_where  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2233 "bison_parser.cpp"
        break;

    case 222: /* opt_group  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).group_t)); }
#line 2239 "bison_parser.cpp"
        break;

    case 223: /* opt_having  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2245 "bison_parser.cpp"
        break;

    case 224: /* opt_order  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).order_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 2258 "bison_parser.cpp"
        break;

    case 225: /* order_list  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).order_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 2271 "bison_parser.cpp"
        break;

    case 226: /* order_desc  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).order)); }
#line 2277 "bison_parser.cpp"
        break;

    case 227: /* opt_order_type  */
#line 147 "bison_parser.y"
            { }
#line 2283 "bison_parser.cpp"
        break;

    case 228: /* opt_top  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).limit)); }
#line 2289 "bison_parser.cpp"
        break;

    case 229: /* opt_limit  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).limit)); }
#line 2295 "bison_parser.cpp"
        break;

    case 230: /* expr_list  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2308 "bison_parser.cpp"
        break;

    case 231: /* opt_literal_list  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2321 "bison_parser.cpp"
        break;

    case 232: /* literal_list  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2334 "bison_parser.cpp"
        break;

    case 233: /* expr_alias  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2340 "bison_parser.cpp"
        break;

    case 234: /* expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2346 "bison_parser.cpp"
        break;

    case 235: /* operand  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2352 "bison_parser.cpp"
        break;

    case 236: /* scalar_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2358 "bison_parser.cpp"
        break;

    case 237: /* unary_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2364 "bison_parser.cpp"
        break;

    case 238: /* binary_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2370 "bison_parser.cpp"
        break;

    case 239: /* logic_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2376 "bison_parser.cpp"
        break;

    case 240: /* in_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2382 "bison_parser.cpp"
        break;

    case 241: /* case_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2388 "bison_parser.cpp"
        break;

    case 242: /* case_list  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2394 "bison_parser.cpp"
        break;

    case 243: /* exists_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2400 "bison_parser.cpp"
        break;

    case 244: /* comp_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2406 "bison_parser.cpp"
        break;

    case 245: /* function_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2412 "bison_parser.cpp"
        break;

    case 246: /* extract_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2418 "bison_parser.cpp"
        break;

    case 247: /* cast_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2424 "bison_parser.cpp"
        break;

    case 248: /* datetime_field  */
#line 147 "bison_parser.y"
            { }
#line 2430 "bison_parser.cpp"
        break;

    case 249: /* array_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2436 "bison_parser.cpp"
        break;

    case 250: /* array_index  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2442 "bison_parser.cpp"
        break;

    case 251: /* between_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2448 "bison_parser.cpp"
        break;

    case 252: /* column_name  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2454 "bison_parser.cpp"
        break;

    case 253: /* literal  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2460 "bison_parser.cpp"
        break;

    case 254: /* string_literal  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2466 "bison_parser.cpp"
        break;

    case 255: /* bool_literal  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2472 "bison_parser.cpp"
        break;

    case 256: /* num_literal  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2478 "bison_parser.cpp"
        break;

    case 257: /* int_literal  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2484 "bison_parser.cpp"
        break;

    case 258: /* null_literal  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2490 "bison_parser.cpp"
        break;

    case 259: /* param_expr  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2496 "bison_parser.cpp"
        break;

    case 260: /* table_ref  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).table)); }
#line 2502 "bison_parser.cpp"
        break;

    case 261: /* table_ref_atomic  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).table)); }
#line 2508 "bison_parser.cpp"
        break;

    case 262: /* nonjoin_table_ref_atomic  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).table)); }
#line 2514 "bison_parser.cpp"
        break;

    case 263: /* table_ref_commalist  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).table_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).table_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).table_vec));
}
#line 2527 "bison_parser.cpp"
        break;

    case 264: /* table_ref_name  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).table)); }
#line 2533 "bison_parser.cpp"
        break;

    case 265: /* table_ref_name_no_alias  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).table)); }
#line 2539 "bison_parser.cpp"
        break;

    case 266: /* table_name  */
#line 148 "bison_parser.y"
            { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2545 "bison_parser.cpp"
        break;

    case 267: /* table_alias  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).alias_t)); }
#line 2551 "bison_parser.cpp"
        break;

    case 268: /* opt_table_alias  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).alias_t)); }
#line 2557 "bison_parser.cpp"
        break;

    case 269: /* alias  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).alias_t)); }
#line 2563 "bison_parser.cpp"
        break;

    case 270: /* opt_alias  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).alias_t)); }
#line 2569 "bison_parser.cpp"
        break;

    case 271: /* opt_with_clause  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).with_description_vec)); }
#line 2575 "bison_parser.cpp"
        break;

    case 272: /* with_clause  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).with_description_vec)); }
#line 2581 "bison_parser.cpp"
        break;

    case 273: /* with_description_list  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).with_description_vec)); }
#line 2587 "bison_parser.cpp"
        break;

    case 274: /* with_description  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).with_description_t)); }
#line 2593 "bison_parser.cpp"
        break;

    case 275: /* join_clause  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).table)); }
#line 2599 "bison_parser.cpp"
        break;

    case 276: /* opt_join_type  */
#line 147 "bison_parser.y"
            { }
#line 2605 "bison_parser.cpp"
        break;

    case 277: /* join_condition  */
#line 158 "bison_parser.y"
            { delete (((*yyvaluep).expr)); }
#line 2611 "bison_parser.cpp"
        break;

    case 279: /* ident_commalist  */
#line 150 "bison_parser.y"
            {
	if ((((*yyvaluep).str_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 2624 "bison_parser.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (hsql::SQLParserResult* result, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 73 "bison_parser.y"
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
	yylloc.total_column = 0;
	yylloc.string_length = 0;
}

#line 2742 "bison_parser.cpp"

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 269 "bison_parser.y"
                                             {
			for (SQLStatement* stmt : *(yyvsp[-1].stmt_vec)) {
				// Transfers ownership of the statement.
				result->addStatement(stmt);
			}

			unsigned param_id = 0;
			for (void* param : yyloc.param_list) {
				if (param != nullptr) {
					Expr* expr = (Expr*) param;
					expr->ival = param_id;
					result->addParameter(expr);
					++param_id;
				}
			}
			delete (yyvsp[-1].stmt_vec);
		}
#line 2957 "bison_parser.cpp"
    break;

  case 3:
#line 290 "bison_parser.y"
                          {
			(yyvsp[0].statement)->stringLength = yylloc.string_length;
			yylloc.string_length = 0;
			(yyval.stmt_vec) = new std::vector<SQLStatement*>();
			(yyval.stmt_vec)->push_back((yyvsp[0].statement));
		}
#line 2968 "bison_parser.cpp"
    break;

  case 4:
#line 296 "bison_parser.y"
                                             {
			(yyvsp[0].statement)->stringLength = yylloc.string_length;
			yylloc.string_length = 0;
			(yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
			(yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
		}
#line 2979 "bison_parser.cpp"
    break;

  case 5:
#line 305 "bison_parser.y"
                                            {
			(yyval.statement) = (yyvsp[-1].prep_stmt);
			(yyval.statement)->hints = (yyvsp[0].expr_vec);
		}
#line 2988 "bison_parser.cpp"
    break;

  case 6:
#line 309 "bison_parser.y"
                                               {
			(yyval.statement) = (yyvsp[-1].statement);
			(yyval.statement)->hints = (yyvsp[0].expr_vec);
		}
#line 2997 "bison_parser.cpp"
    break;

  case 7:
#line 313 "bison_parser.y"
                               {
			(yyval.statement) = (yyvsp[0].show_stmt);
		}
#line 3005 "bison_parser.cpp"
    break;

  case 8:
#line 316 "bison_parser.y"
                                 {
			(yyval.statement) = (yyvsp[0].import_stmt);
		 }
#line 3013 "bison_parser.cpp"
    break;

  case 9:
#line 319 "bison_parser.y"
                                 {
			(yyval.statement) = (yyvsp[0].export_stmt);
		 }
#line 3021 "bison_parser.cpp"
    break;

  case 10:
#line 326 "bison_parser.y"
                                 { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 3027 "bison_parser.cpp"
    break;

  case 11:
#line 327 "bison_parser.y"
                                 { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 3033 "bison_parser.cpp"
    break;

  case 12:
#line 328 "bison_parser.y"
                                 { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 3039 "bison_parser.cpp"
    break;

  case 13:
#line 329 "bison_parser.y"
                                 { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3045 "bison_parser.cpp"
    break;

  case 14:
#line 330 "bison_parser.y"
                                   { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3051 "bison_parser.cpp"
    break;

  case 15:
#line 331 "bison_parser.y"
                                 { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 3057 "bison_parser.cpp"
    break;

  case 16:
#line 332 "bison_parser.y"
                               { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 3063 "bison_parser.cpp"
    break;

  case 17:
#line 333 "bison_parser.y"
                                  { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 3069 "bison_parser.cpp"
    break;

  case 18:
#line 334 "bison_parser.y"
                                      { (yyval.statement) = (yyvsp[0].transaction_stmt); }
#line 3075 "bison_parser.cpp"
    break;

  case 19:
#line 343 "bison_parser.y"
                                { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 3081 "bison_parser.cpp"
    break;

  case 20:
#line 344 "bison_parser.y"
                { (yyval.expr_vec) = nullptr; }
#line 3087 "bison_parser.cpp"
    break;

  case 21:
#line 349 "bison_parser.y"
               { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3093 "bison_parser.cpp"
    break;

  case 22:
#line 350 "bison_parser.y"
                             { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3099 "bison_parser.cpp"
    break;

  case 23:
#line 354 "bison_parser.y"
                           {
			(yyval.expr) = Expr::make(kExprHint);
			(yyval.expr)->name = (yyvsp[0].sval);
		}
#line 3108 "bison_parser.cpp"
    break;

  case 24:
#line 358 "bison_parser.y"
                                          {
			(yyval.expr) = Expr::make(kExprHint);
			(yyval.expr)->name = (yyvsp[-3].sval);
			(yyval.expr)->exprList = (yyvsp[-1].expr_vec);
		}
#line 3118 "bison_parser.cpp"
    break;

  case 25:
#line 370 "bison_parser.y"
                                  {
            (yyval.transaction_stmt) = new TransactionStatement(kBeginTransaction);
        }
#line 3126 "bison_parser.cpp"
    break;

  case 26:
#line 373 "bison_parser.y"
                                       {
            (yyval.transaction_stmt) = new TransactionStatement(kRollbackTransaction);
        }
#line 3134 "bison_parser.cpp"
    break;

  case 27:
#line 376 "bison_parser.y"
                                     {
            (yyval.transaction_stmt) = new TransactionStatement(kCommitTransaction);
        }
#line 3142 "bison_parser.cpp"
    break;

  case 30:
#line 390 "bison_parser.y"
                                                             {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-2].sval);
			(yyval.prep_stmt)->query = (yyvsp[0].sval);
		}
#line 3152 "bison_parser.cpp"
    break;

  case 32:
#line 400 "bison_parser.y"
                                   {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[0].sval);
		}
#line 3161 "bison_parser.cpp"
    break;

  case 33:
#line 404 "bison_parser.y"
                                                            {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[-3].sval);
			(yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
		}
#line 3171 "bison_parser.cpp"
    break;

  case 34:
#line 418 "bison_parser.y"
                                                                     {
			(yyval.import_stmt) = new ImportStatement((yyvsp[-4].import_type_t));
			(yyval.import_stmt)->filePath = (yyvsp[-2].sval);
			(yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
		}
#line 3182 "bison_parser.cpp"
    break;

  case 35:
#line 424 "bison_parser.y"
                                                             {
			(yyval.import_stmt) = new ImportStatement((yyvsp[0].import_type_t));
			(yyval.import_stmt)->filePath = (yyvsp[-1].sval);
			(yyval.import_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.import_stmt)->tableName = (yyvsp[-3].table_name).name;
		}
#line 3193 "bison_parser.cpp"
    break;

  case 36:
#line 433 "bison_parser.y"
                           {
			if (strcasecmp((yyvsp[0].sval), "csv") == 0) {
				(yyval.import_type_t) = kImportCSV;
			} else if (strcasecmp((yyvsp[0].sval), "tbl") == 0) {
				(yyval.import_type_t) = kImportTbl;
			} else if (strcasecmp((yyvsp[0].sval), "binary") == 0 || strcasecmp((yyvsp[0].sval), "bin") == 0) {
				(yyval.import_type_t) = kImportBinary;
			} else {
				free((yyvsp[0].sval));
				yyerror(&yyloc, result, scanner, "File type is unknown.");
				YYERROR;
			}
			free((yyvsp[0].sval));
		}
#line 3212 "bison_parser.cpp"
    break;

  case 37:
#line 450 "bison_parser.y"
                               { (yyval.sval) = strdup((yyvsp[0].expr)->name); delete (yyvsp[0].expr); }
#line 3218 "bison_parser.cpp"
    break;

  case 38:
#line 454 "bison_parser.y"
                                      {
			(yyval.import_type_t) = (yyvsp[0].import_type_t);
		}
#line 3226 "bison_parser.cpp"
    break;

  case 39:
#line 457 "bison_parser.y"
                             { (yyval.import_type_t) = kImportAuto; }
#line 3232 "bison_parser.cpp"
    break;

  case 40:
#line 466 "bison_parser.y"
                                                           {
			(yyval.export_stmt) = new ExportStatement((yyvsp[0].import_type_t));
			(yyval.export_stmt)->filePath = (yyvsp[-1].sval);
			(yyval.export_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.export_stmt)->tableName = (yyvsp[-3].table_name).name;
		}
#line 3243 "bison_parser.cpp"
    break;

  case 41:
#line 480 "bison_parser.y"
                            {
			(yyval.show_stmt) = new ShowStatement(kShowTables);
		}
#line 3251 "bison_parser.cpp"
    break;

  case 42:
#line 483 "bison_parser.y"
                                        {
			(yyval.show_stmt) = new ShowStatement(kShowColumns);
			(yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.show_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 3261 "bison_parser.cpp"
    break;

  case 43:
#line 488 "bison_parser.y"
                                    {
			(yyval.show_stmt) = new ShowStatement(kShowColumns);
			(yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.show_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 3271 "bison_parser.cpp"
    break;

  case 44:
#line 493 "bison_parser.y"
                              {
		(yyval.show_stmt) = new ShowStatement(kShowDatabases);
	}
#line 3279 "bison_parser.cpp"
    break;

  case 45:
#line 505 "bison_parser.y"
                                                                                      {
			(yyval.create_stmt) = new CreateStatement(kCreateTableFromTbl);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-5].bval);
			(yyval.create_stmt)->schema = (yyvsp[-4].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-4].table_name).name;
			if (strcasecmp((yyvsp[-2].sval), "tbl") != 0) {
				free((yyvsp[-2].sval));
				yyerror(&yyloc, result, scanner, "File type is unknown.");
			 	YYERROR;
			}
			free((yyvsp[-2].sval));
			(yyval.create_stmt)->filePath = (yyvsp[0].sval);
		}
#line 3297 "bison_parser.cpp"
    break;

  case 46:
#line 518 "bison_parser.y"
                                                                                    {
			(yyval.create_stmt) = new CreateStatement(kCreateTable);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
			(yyval.create_stmt)->columns = (yyvsp[-1].column_vec);
		}
#line 3309 "bison_parser.cpp"
    break;

  case 47:
#line 525 "bison_parser.y"
                                                                           {
			(yyval.create_stmt) = new CreateStatement(kCreateTable);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-3].bval);
			(yyval.create_stmt)->schema = (yyvsp[-2].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-2].table_name).name;
			(yyval.create_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 3321 "bison_parser.cpp"
    break;

  case 48:
#line 532 "bison_parser.y"
                                                                                          {
			(yyval.create_stmt) = new CreateStatement(kCreateView);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
			(yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
			(yyval.create_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 3334 "bison_parser.cpp"
    break;

  case 49:
#line 540 "bison_parser.y"
                                            {
		(yyval.create_stmt) = new CreateStatement(kCreateDatabase);
		(yyval.create_stmt)->schema = (yyvsp[0].sval);
		}
#line 3343 "bison_parser.cpp"
    break;

  case 50:
#line 547 "bison_parser.y"
                              { (yyval.bval) = true; }
#line 3349 "bison_parser.cpp"
    break;

  case 51:
#line 548 "bison_parser.y"
                            { (yyval.bval) = false; }
#line 3355 "bison_parser.cpp"
    break;

  case 52:
#line 552 "bison_parser.y"
                           { (yyval.column_vec) = new std::vector<ColumnDefinition*>(); (yyval.column_vec)->push_back((yyvsp[0].column_t)); }
#line 3361 "bison_parser.cpp"
    break;

  case 53:
#line 553 "bison_parser.y"
                                                    { (yyvsp[-2].column_vec)->push_back((yyvsp[0].column_t)); (yyval.column_vec) = (yyvsp[-2].column_vec); }
#line 3367 "bison_parser.cpp"
    break;

  case 54:
#line 557 "bison_parser.y"
                                                           {(yyval.column_t) = new ColumnDefinition((yyvsp[-2].sval), (yyvsp[-1].column_type_t), (yyvsp[0].bval));}
#line 3373 "bison_parser.cpp"
    break;

  case 55:
#line 558 "bison_parser.y"
                                                              {
			(yyval.column_t) = new ColumnDefinition((yyvsp[-3].sval), DataType::UNKNOWN, false);
			(yyval.column_t)->iskey=true;
			(yyval.column_t)->isuniquekey=(yyvsp[-5].bval);
			(yyval.column_t)->keyColumns=(yyvsp[-1].str_vec);
			/*printf("keyname=%s\n",$3);*/
		}
#line 3385 "bison_parser.cpp"
    break;

  case 56:
#line 565 "bison_parser.y"
                                                     {
		    char *name=new char[10];
			memset(name,0,10);
			(yyval.column_t) = new ColumnDefinition(name, DataType::UNKNOWN, false);
			(yyval.column_t)->iskey=true;
			(yyval.column_t)->isprivakey=(yyvsp[-4].bval);
			(yyval.column_t)->keyColumns=(yyvsp[-1].str_vec);
			printf("isprivakey=%d\n",(yyvsp[-4].bval));
		}
#line 3399 "bison_parser.cpp"
    break;

  case 57:
#line 577 "bison_parser.y"
                    { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3405 "bison_parser.cpp"
    break;

  case 58:
#line 578 "bison_parser.y"
                        { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3411 "bison_parser.cpp"
    break;

  case 59:
#line 579 "bison_parser.y"
                     { (yyval.column_type_t) = ColumnType{DataType::LONG}; }
#line 3417 "bison_parser.cpp"
    break;

  case 60:
#line 580 "bison_parser.y"
                      { (yyval.column_type_t) = ColumnType{DataType::FLOAT}; }
#line 3423 "bison_parser.cpp"
    break;

  case 61:
#line 581 "bison_parser.y"
                       { (yyval.column_type_t) = ColumnType{DataType::DOUBLE}; }
#line 3429 "bison_parser.cpp"
    break;

  case 62:
#line 582 "bison_parser.y"
                                       { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3435 "bison_parser.cpp"
    break;

  case 63:
#line 583 "bison_parser.y"
                                    { (yyval.column_type_t) = ColumnType{DataType::CHAR, (yyvsp[-1].ival)}; }
#line 3441 "bison_parser.cpp"
    break;

  case 64:
#line 584 "bison_parser.y"
                     { (yyval.column_type_t) = ColumnType{DataType::TEXT}; }
#line 3447 "bison_parser.cpp"
    break;

  case 65:
#line 585 "bison_parser.y"
                         { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3453 "bison_parser.cpp"
    break;

  case 66:
#line 589 "bison_parser.y"
                     { (yyval.bval) = true; }
#line 3459 "bison_parser.cpp"
    break;

  case 67:
#line 590 "bison_parser.y"
                         { (yyval.bval) = false; }
#line 3465 "bison_parser.cpp"
    break;

  case 68:
#line 591 "bison_parser.y"
                            { (yyval.bval) = false; }
#line 3471 "bison_parser.cpp"
    break;

  case 69:
#line 595 "bison_parser.y"
               {(yyval.bval) = true;}
#line 3477 "bison_parser.cpp"
    break;

  case 70:
#line 596 "bison_parser.y"
                            { (yyval.bval) = false; }
#line 3483 "bison_parser.cpp"
    break;

  case 71:
#line 599 "bison_parser.y"
                {(yyval.bval) = true;}
#line 3489 "bison_parser.cpp"
    break;

  case 72:
#line 602 "bison_parser.y"
                   { (yyval.str_vec) = new std::vector<char*>(); (yyval.str_vec)->push_back((yyvsp[0].sval)); }
#line 3495 "bison_parser.cpp"
    break;

  case 73:
#line 603 "bison_parser.y"
                                           { (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval)); (yyval.str_vec) = (yyvsp[-2].str_vec); }
#line 3501 "bison_parser.cpp"
    break;

  case 74:
#line 613 "bison_parser.y"
                                                 {
			(yyval.drop_stmt) = new DropStatement(kDropTable);
			(yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
			(yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 3512 "bison_parser.cpp"
    break;

  case 75:
#line 619 "bison_parser.y"
                                                {
			(yyval.drop_stmt) = new DropStatement(kDropView);
			(yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
			(yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 3523 "bison_parser.cpp"
    break;

  case 76:
#line 625 "bison_parser.y"
                                              {
			(yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
			(yyval.drop_stmt)->ifExists = false;
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 3533 "bison_parser.cpp"
    break;

  case 77:
#line 630 "bison_parser.y"
                                           {
			(yyval.drop_stmt) = new DropStatement(kDropDatabase);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
	}
#line 3542 "bison_parser.cpp"
    break;

  case 78:
#line 637 "bison_parser.y"
                            { (yyval.bval) = true; }
#line 3548 "bison_parser.cpp"
    break;

  case 79:
#line 638 "bison_parser.y"
                            { (yyval.bval) = false; }
#line 3554 "bison_parser.cpp"
    break;

  case 80:
#line 647 "bison_parser.y"
                                                 {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
			(yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
			(yyval.delete_stmt)->expr = (yyvsp[0].expr);
		}
#line 3565 "bison_parser.cpp"
    break;

  case 81:
#line 656 "bison_parser.y"
                                    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
		}
#line 3575 "bison_parser.cpp"
    break;

  case 82:
#line 669 "bison_parser.y"
                                                                                   {
			(yyval.insert_stmt) = new InsertStatement(kInsertValues);
			(yyval.insert_stmt)->schema = (yyvsp[-5].table_name).schema;
			(yyval.insert_stmt)->tableName = (yyvsp[-5].table_name).name;
			(yyval.insert_stmt)->columns = (yyvsp[-4].str_vec);
			(yyval.insert_stmt)->values = (yyvsp[-1].expr_vec);
		}
#line 3587 "bison_parser.cpp"
    break;

  case 83:
#line 676 "bison_parser.y"
                                                                       {
			(yyval.insert_stmt) = new InsertStatement(kInsertSelect);
			(yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
			(yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
			(yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
			(yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 3599 "bison_parser.cpp"
    break;

  case 84:
#line 687 "bison_parser.y"
                                        { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 3605 "bison_parser.cpp"
    break;

  case 85:
#line 688 "bison_parser.y"
                            { (yyval.str_vec) = nullptr; }
#line 3611 "bison_parser.cpp"
    break;

  case 86:
#line 698 "bison_parser.y"
                                                                             {
		(yyval.update_stmt) = new UpdateStatement();
		(yyval.update_stmt)->table = (yyvsp[-3].table);
		(yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
		(yyval.update_stmt)->where = (yyvsp[0].expr);
	}
#line 3622 "bison_parser.cpp"
    break;

  case 87:
#line 707 "bison_parser.y"
                              { (yyval.update_vec) = new std::vector<UpdateClause*>(); (yyval.update_vec)->push_back((yyvsp[0].update_t)); }
#line 3628 "bison_parser.cpp"
    break;

  case 88:
#line 708 "bison_parser.y"
                                                          { (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t)); (yyval.update_vec) = (yyvsp[-2].update_vec); }
#line 3634 "bison_parser.cpp"
    break;

  case 89:
#line 712 "bison_parser.y"
                                    {
			(yyval.update_t) = new UpdateClause();
			(yyval.update_t)->column = (yyvsp[-2].sval);
			(yyval.update_t)->value = (yyvsp[0].expr);
		}
#line 3644 "bison_parser.cpp"
    break;

  case 90:
#line 724 "bison_parser.y"
                                                  {
			(yyval.select_stmt) = (yyvsp[0].select_stmt);
			(yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
		}
#line 3653 "bison_parser.cpp"
    break;

  case 91:
#line 728 "bison_parser.y"
                                                {
			(yyval.select_stmt) = (yyvsp[0].select_stmt);
			(yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
		}
#line 3662 "bison_parser.cpp"
    break;

  case 92:
#line 732 "bison_parser.y"
                                                                                                               {
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			if ((yyval.select_stmt)->setOperations == nullptr) {
				(yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
			}
			(yyval.select_stmt)->setOperations->push_back((yyvsp[-3].set_operator_t));
			(yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->setOperations->back()->resultOrder = (yyvsp[-1].order_vec);
			(yyval.select_stmt)->setOperations->back()->resultLimit = (yyvsp[0].limit);
			(yyval.select_stmt)->withDescriptions = (yyvsp[-5].with_description_vec);
		}
#line 3678 "bison_parser.cpp"
    break;

  case 95:
#line 750 "bison_parser.y"
                              { (yyval.select_stmt) = (yyvsp[0].select_stmt); }
#line 3684 "bison_parser.cpp"
    break;

  case 96:
#line 751 "bison_parser.y"
                                                                       {
		(yyval.select_stmt) = (yyvsp[-2].select_stmt);
		if ((yyval.select_stmt)->setOperations == nullptr) {
			(yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
		}
		(yyval.select_stmt)->setOperations->push_back((yyvsp[-1].set_operator_t));
		(yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[0].select_stmt);
	}
#line 3697 "bison_parser.cpp"
    break;

  case 97:
#line 762 "bison_parser.y"
                                        { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3703 "bison_parser.cpp"
    break;

  case 98:
#line 763 "bison_parser.y"
                                          { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3709 "bison_parser.cpp"
    break;

  case 99:
#line 767 "bison_parser.y"
                                                  {
			(yyval.select_stmt) = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != nullptr) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 3724 "bison_parser.cpp"
    break;

  case 100:
#line 777 "bison_parser.y"
                                                                                           {
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			if ((yyval.select_stmt)->setOperations == nullptr) {
				(yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
			}
			(yyval.select_stmt)->setOperations->push_back((yyvsp[-3].set_operator_t));
			(yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->setOperations->back()->resultOrder = (yyvsp[-1].order_vec);
			(yyval.select_stmt)->setOperations->back()->resultLimit = (yyvsp[0].limit);
		}
#line 3739 "bison_parser.cpp"
    break;

  case 101:
#line 790 "bison_parser.y"
                                 {
		(yyval.set_operator_t) = (yyvsp[-1].set_operator_t);
		(yyval.set_operator_t)->isAll = (yyvsp[0].bval);
		}
#line 3748 "bison_parser.cpp"
    break;

  case 102:
#line 797 "bison_parser.y"
                      {
		(yyval.set_operator_t) = new SetOperation();
		(yyval.set_operator_t)->setType = SetType::kSetUnion;
		}
#line 3757 "bison_parser.cpp"
    break;

  case 103:
#line 801 "bison_parser.y"
                          {
		(yyval.set_operator_t) = new SetOperation();
		(yyval.set_operator_t)->setType = SetType::kSetIntersect;
	}
#line 3766 "bison_parser.cpp"
    break;

  case 104:
#line 805 "bison_parser.y"
                       {
		(yyval.set_operator_t) = new SetOperation();
		(yyval.set_operator_t)->setType = SetType::kSetExcept;
	}
#line 3775 "bison_parser.cpp"
    break;

  case 105:
#line 812 "bison_parser.y"
                    {
			(yyval.bval) = true;
		}
#line 3783 "bison_parser.cpp"
    break;

  case 106:
#line 815 "bison_parser.y"
                            {
		(yyval.bval) = false;
	}
#line 3791 "bison_parser.cpp"
    break;

  case 107:
#line 821 "bison_parser.y"
                                                                                            {
			(yyval.select_stmt) = new SelectStatement();
			(yyval.select_stmt)->limit = (yyvsp[-5].limit);
			(yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
			(yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
			(yyval.select_stmt)->fromTable = (yyvsp[-2].table);
			(yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
			(yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
		}
#line 3805 "bison_parser.cpp"
    break;

  case 108:
#line 833 "bison_parser.y"
                         { (yyval.bval) = true; }
#line 3811 "bison_parser.cpp"
    break;

  case 109:
#line 834 "bison_parser.y"
                            { (yyval.bval) = false; }
#line 3817 "bison_parser.cpp"
    break;

  case 111:
#line 842 "bison_parser.y"
                     { (yyval.table) = (yyvsp[0].table); }
#line 3823 "bison_parser.cpp"
    break;

  case 112:
#line 843 "bison_parser.y"
                     { (yyval.table) = nullptr; }
#line 3829 "bison_parser.cpp"
    break;

  case 113:
#line 847 "bison_parser.y"
                               { (yyval.table) = (yyvsp[0].table); }
#line 3835 "bison_parser.cpp"
    break;

  case 114:
#line 852 "bison_parser.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 3841 "bison_parser.cpp"
    break;

  case 115:
#line 853 "bison_parser.y"
                            { (yyval.expr) = nullptr; }
#line 3847 "bison_parser.cpp"
    break;

  case 116:
#line 857 "bison_parser.y"
                                              {
			(yyval.group_t) = new GroupByDescription();
			(yyval.group_t)->columns = (yyvsp[-1].expr_vec);
			(yyval.group_t)->having = (yyvsp[0].expr);
		}
#line 3857 "bison_parser.cpp"
    break;

  case 117:
#line 862 "bison_parser.y"
                            { (yyval.group_t) = nullptr; }
#line 3863 "bison_parser.cpp"
    break;

  case 118:
#line 866 "bison_parser.y"
                            { (yyval.expr) = (yyvsp[0].expr); }
#line 3869 "bison_parser.cpp"
    break;

  case 119:
#line 867 "bison_parser.y"
                            { (yyval.expr) = nullptr; }
#line 3875 "bison_parser.cpp"
    break;

  case 120:
#line 871 "bison_parser.y"
                                    { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 3881 "bison_parser.cpp"
    break;

  case 121:
#line 872 "bison_parser.y"
                            { (yyval.order_vec) = nullptr; }
#line 3887 "bison_parser.cpp"
    break;

  case 122:
#line 876 "bison_parser.y"
                           { (yyval.order_vec) = new std::vector<OrderDescription*>(); (yyval.order_vec)->push_back((yyvsp[0].order)); }
#line 3893 "bison_parser.cpp"
    break;

  case 123:
#line 877 "bison_parser.y"
                                          { (yyvsp[-2].order_vec)->push_back((yyvsp[0].order)); (yyval.order_vec) = (yyvsp[-2].order_vec); }
#line 3899 "bison_parser.cpp"
    break;

  case 124:
#line 881 "bison_parser.y"
                                    { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 3905 "bison_parser.cpp"
    break;

  case 125:
#line 885 "bison_parser.y"
                    { (yyval.order_type) = kOrderAsc; }
#line 3911 "bison_parser.cpp"
    break;

  case 126:
#line 886 "bison_parser.y"
                     { (yyval.order_type) = kOrderDesc; }
#line 3917 "bison_parser.cpp"
    break;

  case 127:
#line 887 "bison_parser.y"
                            { (yyval.order_type) = kOrderAsc; }
#line 3923 "bison_parser.cpp"
    break;

  case 128:
#line 893 "bison_parser.y"
                                { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 3929 "bison_parser.cpp"
    break;

  case 129:
#line 894 "bison_parser.y"
                            { (yyval.limit) = nullptr; }
#line 3935 "bison_parser.cpp"
    break;

  case 130:
#line 898 "bison_parser.y"
                           { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 3941 "bison_parser.cpp"
    break;

  case 131:
#line 899 "bison_parser.y"
                            { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 3947 "bison_parser.cpp"
    break;

  case 132:
#line 900 "bison_parser.y"
                                       { (yyval.limit) = new LimitDescription((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3953 "bison_parser.cpp"
    break;

  case 133:
#line 901 "bison_parser.y"
                          { (yyval.limit) = new LimitDescription(nullptr, nullptr); }
#line 3959 "bison_parser.cpp"
    break;

  case 134:
#line 902 "bison_parser.y"
                                      { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 3965 "bison_parser.cpp"
    break;

  case 135:
#line 903 "bison_parser.y"
                            { (yyval.limit) = nullptr; }
#line 3971 "bison_parser.cpp"
    break;

  case 136:
#line 910 "bison_parser.y"
                           { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3977 "bison_parser.cpp"
    break;

  case 137:
#line 911 "bison_parser.y"
                                         { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3983 "bison_parser.cpp"
    break;

  case 138:
#line 915 "bison_parser.y"
                             { (yyval.expr_vec) = (yyvsp[0].expr_vec); }
#line 3989 "bison_parser.cpp"
    break;

  case 139:
#line 916 "bison_parser.y"
                            { (yyval.expr_vec) = nullptr; }
#line 3995 "bison_parser.cpp"
    break;

  case 140:
#line 920 "bison_parser.y"
                        { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 4001 "bison_parser.cpp"
    break;

  case 141:
#line 921 "bison_parser.y"
                                         { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 4007 "bison_parser.cpp"
    break;

  case 142:
#line 925 "bison_parser.y"
                               {
			(yyval.expr) = (yyvsp[-1].expr);
			if ((yyvsp[0].alias_t)) {
				(yyval.expr)->alias = strdup((yyvsp[0].alias_t)->name);
				delete (yyvsp[0].alias_t);
			}
		}
#line 4019 "bison_parser.cpp"
    break;

  case 148:
#line 943 "bison_parser.y"
                             { (yyval.expr) = (yyvsp[-1].expr); }
#line 4025 "bison_parser.cpp"
    break;

  case 158:
#line 953 "bison_parser.y"
                                        { (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt)); }
#line 4031 "bison_parser.cpp"
    break;

  case 161:
#line 962 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 4037 "bison_parser.cpp"
    break;

  case 162:
#line 963 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 4043 "bison_parser.cpp"
    break;

  case 163:
#line 964 "bison_parser.y"
                               { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 4049 "bison_parser.cpp"
    break;

  case 164:
#line 965 "bison_parser.y"
                                { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 4055 "bison_parser.cpp"
    break;

  case 165:
#line 966 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 4061 "bison_parser.cpp"
    break;

  case 167:
#line 971 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 4067 "bison_parser.cpp"
    break;

  case 168:
#line 972 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 4073 "bison_parser.cpp"
    break;

  case 169:
#line 973 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 4079 "bison_parser.cpp"
    break;

  case 170:
#line 974 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 4085 "bison_parser.cpp"
    break;

  case 171:
#line 975 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 4091 "bison_parser.cpp"
    break;

  case 172:
#line 976 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 4097 "bison_parser.cpp"
    break;

  case 173:
#line 977 "bison_parser.y"
                                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 4103 "bison_parser.cpp"
    break;

  case 174:
#line 978 "bison_parser.y"
                                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 4109 "bison_parser.cpp"
    break;

  case 175:
#line 979 "bison_parser.y"
                                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 4115 "bison_parser.cpp"
    break;

  case 176:
#line 980 "bison_parser.y"
                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 4121 "bison_parser.cpp"
    break;

  case 177:
#line 984 "bison_parser.y"
                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 4127 "bison_parser.cpp"
    break;

  case 178:
#line 985 "bison_parser.y"
                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 4133 "bison_parser.cpp"
    break;

  case 179:
#line 989 "bison_parser.y"
                                                                { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 4139 "bison_parser.cpp"
    break;

  case 180:
#line 990 "bison_parser.y"
                                                                { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 4145 "bison_parser.cpp"
    break;

  case 181:
#line 991 "bison_parser.y"
                                                                { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 4151 "bison_parser.cpp"
    break;

  case 182:
#line 992 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 4157 "bison_parser.cpp"
    break;

  case 183:
#line 998 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 4163 "bison_parser.cpp"
    break;

  case 184:
#line 999 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4169 "bison_parser.cpp"
    break;

  case 185:
#line 1000 "bison_parser.y"
                                                                { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 4175 "bison_parser.cpp"
    break;

  case 186:
#line 1001 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4181 "bison_parser.cpp"
    break;

  case 187:
#line 1005 "bison_parser.y"
                                                 { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4187 "bison_parser.cpp"
    break;

  case 188:
#line 1006 "bison_parser.y"
                                                 { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4193 "bison_parser.cpp"
    break;

  case 189:
#line 1010 "bison_parser.y"
                                               { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 4199 "bison_parser.cpp"
    break;

  case 190:
#line 1011 "bison_parser.y"
                                                   { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 4205 "bison_parser.cpp"
    break;

  case 191:
#line 1015 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4211 "bison_parser.cpp"
    break;

  case 192:
#line 1016 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4217 "bison_parser.cpp"
    break;

  case 193:
#line 1017 "bison_parser.y"
                                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 4223 "bison_parser.cpp"
    break;

  case 194:
#line 1018 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 4229 "bison_parser.cpp"
    break;

  case 195:
#line 1019 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 4235 "bison_parser.cpp"
    break;

  case 196:
#line 1020 "bison_parser.y"
                                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 4241 "bison_parser.cpp"
    break;

  case 197:
#line 1021 "bison_parser.y"
                                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 4247 "bison_parser.cpp"
    break;

  case 198:
#line 1025 "bison_parser.y"
                                  { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 4253 "bison_parser.cpp"
    break;

  case 199:
#line 1026 "bison_parser.y"
                                                         { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 4259 "bison_parser.cpp"
    break;

  case 200:
#line 1030 "bison_parser.y"
                                                     { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 4265 "bison_parser.cpp"
    break;

  case 201:
#line 1034 "bison_parser.y"
                                            { (yyval.expr) = Expr::makeCast((yyvsp[-3].expr), (yyvsp[-1].column_type_t)); }
#line 4271 "bison_parser.cpp"
    break;

  case 202:
#line 1038 "bison_parser.y"
               { (yyval.datetime_field) = kDatetimeSecond; }
#line 4277 "bison_parser.cpp"
    break;

  case 203:
#line 1039 "bison_parser.y"
               { (yyval.datetime_field) = kDatetimeMinute; }
#line 4283 "bison_parser.cpp"
    break;

  case 204:
#line 1040 "bison_parser.y"
             { (yyval.datetime_field) = kDatetimeHour; }
#line 4289 "bison_parser.cpp"
    break;

  case 205:
#line 1041 "bison_parser.y"
            { (yyval.datetime_field) = kDatetimeDay; }
#line 4295 "bison_parser.cpp"
    break;

  case 206:
#line 1042 "bison_parser.y"
              { (yyval.datetime_field) = kDatetimeMonth; }
#line 4301 "bison_parser.cpp"
    break;

  case 207:
#line 1043 "bison_parser.y"
             { (yyval.datetime_field) = kDatetimeYear; }
#line 4307 "bison_parser.cpp"
    break;

  case 208:
#line 1047 "bison_parser.y"
                                        { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 4313 "bison_parser.cpp"
    break;

  case 209:
#line 1051 "bison_parser.y"
                                            { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 4319 "bison_parser.cpp"
    break;

  case 210:
#line 1055 "bison_parser.y"
                                                    { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4325 "bison_parser.cpp"
    break;

  case 211:
#line 1059 "bison_parser.y"
                           { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 4331 "bison_parser.cpp"
    break;

  case 212:
#line 1060 "bison_parser.y"
                                          { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 4337 "bison_parser.cpp"
    break;

  case 213:
#line 1061 "bison_parser.y"
                    { (yyval.expr) = Expr::makeStar(); }
#line 4343 "bison_parser.cpp"
    break;

  case 214:
#line 1062 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 4349 "bison_parser.cpp"
    break;

  case 220:
#line 1074 "bison_parser.y"
                       { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 4355 "bison_parser.cpp"
    break;

  case 221:
#line 1078 "bison_parser.y"
                     { (yyval.expr) = Expr::makeLiteral(true); }
#line 4361 "bison_parser.cpp"
    break;

  case 222:
#line 1079 "bison_parser.y"
                      { (yyval.expr) = Expr::makeLiteral(false); }
#line 4367 "bison_parser.cpp"
    break;

  case 223:
#line 1083 "bison_parser.y"
                         { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 4373 "bison_parser.cpp"
    break;

  case 225:
#line 1088 "bison_parser.y"
                       { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 4379 "bison_parser.cpp"
    break;

  case 226:
#line 1092 "bison_parser.y"
                     { (yyval.expr) = Expr::makeNullLiteral(); }
#line 4385 "bison_parser.cpp"
    break;

  case 227:
#line 1096 "bison_parser.y"
                    {
			(yyval.expr) = Expr::makeParameter(yylloc.total_column);
			(yyval.expr)->ival2 = yyloc.param_list.size();
			yyloc.param_list.push_back((yyval.expr));
		}
#line 4395 "bison_parser.cpp"
    break;

  case 229:
#line 1109 "bison_parser.y"
                                                         {
			(yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
			auto tbl = new TableRef(kTableCrossProduct);
			tbl->list = (yyvsp[-2].table_vec);
			(yyval.table) = tbl;
		}
#line 4406 "bison_parser.cpp"
    break;

  case 233:
#line 1125 "bison_parser.y"
                                                         {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].alias_t);
			(yyval.table) = tbl;
		}
#line 4417 "bison_parser.cpp"
    break;

  case 234:
#line 1134 "bison_parser.y"
                                 { (yyval.table_vec) = new std::vector<TableRef*>(); (yyval.table_vec)->push_back((yyvsp[0].table)); }
#line 4423 "bison_parser.cpp"
    break;

  case 235:
#line 1135 "bison_parser.y"
                                                         { (yyvsp[-2].table_vec)->push_back((yyvsp[0].table)); (yyval.table_vec) = (yyvsp[-2].table_vec); }
#line 4429 "bison_parser.cpp"
    break;

  case 236:
#line 1140 "bison_parser.y"
                                           {
			auto tbl = new TableRef(kTableName);
			tbl->schema = (yyvsp[-1].table_name).schema;
			tbl->name = (yyvsp[-1].table_name).name;
			tbl->alias = (yyvsp[0].alias_t);
			(yyval.table) = tbl;
		}
#line 4441 "bison_parser.cpp"
    break;

  case 237:
#line 1151 "bison_parser.y"
                           {
			(yyval.table) = new TableRef(kTableName);
			(yyval.table)->schema = (yyvsp[0].table_name).schema;
			(yyval.table)->name = (yyvsp[0].table_name).name;
		}
#line 4451 "bison_parser.cpp"
    break;

  case 238:
#line 1160 "bison_parser.y"
                                          { (yyval.table_name).schema = nullptr; (yyval.table_name).name = (yyvsp[0].sval);}
#line 4457 "bison_parser.cpp"
    break;

  case 239:
#line 1161 "bison_parser.y"
                                          { (yyval.table_name).schema = (yyvsp[-2].sval); (yyval.table_name).name = (yyvsp[0].sval); }
#line 4463 "bison_parser.cpp"
    break;

  case 241:
#line 1167 "bison_parser.y"
                                                      { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 4469 "bison_parser.cpp"
    break;

  case 243:
#line 1173 "bison_parser.y"
                            { (yyval.alias_t) = nullptr; }
#line 4475 "bison_parser.cpp"
    break;

  case 244:
#line 1178 "bison_parser.y"
                              { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 4481 "bison_parser.cpp"
    break;

  case 245:
#line 1179 "bison_parser.y"
                           { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 4487 "bison_parser.cpp"
    break;

  case 247:
#line 1185 "bison_parser.y"
                            { (yyval.alias_t) = nullptr; }
#line 4493 "bison_parser.cpp"
    break;

  case 249:
#line 1195 "bison_parser.y"
                            { (yyval.with_description_vec) = nullptr; }
#line 4499 "bison_parser.cpp"
    break;

  case 250:
#line 1199 "bison_parser.y"
                                           { (yyval.with_description_vec) = (yyvsp[0].with_description_vec); }
#line 4505 "bison_parser.cpp"
    break;

  case 251:
#line 1203 "bison_parser.y"
                                 {
			(yyval.with_description_vec) = new std::vector<WithDescription*>();
			(yyval.with_description_vec)->push_back((yyvsp[0].with_description_t));
		}
#line 4514 "bison_parser.cpp"
    break;

  case 252:
#line 1207 "bison_parser.y"
                                                           {
			(yyvsp[-2].with_description_vec)->push_back((yyvsp[0].with_description_t));
                        (yyval.with_description_vec) = (yyvsp[-2].with_description_vec);
		}
#line 4523 "bison_parser.cpp"
    break;

  case 253:
#line 1214 "bison_parser.y"
                                                {
			(yyval.with_description_t) = new WithDescription();
			(yyval.with_description_t)->alias = (yyvsp[-2].sval);
			(yyval.with_description_t)->select = (yyvsp[0].select_stmt);
		}
#line 4533 "bison_parser.cpp"
    break;

  case 254:
#line 1228 "bison_parser.y"
                {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = kJoinNatural;
			(yyval.table)->join->left = (yyvsp[-3].table);
			(yyval.table)->join->right = (yyvsp[0].table);
		}
#line 4545 "bison_parser.cpp"
    break;

  case 255:
#line 1236 "bison_parser.y"
                {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-4].uval);
			(yyval.table)->join->left = (yyvsp[-5].table);
			(yyval.table)->join->right = (yyvsp[-2].table);
			(yyval.table)->join->condition = (yyvsp[0].expr);
		}
#line 4558 "bison_parser.cpp"
    break;

  case 256:
#line 1246 "bison_parser.y"
                {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-6].uval);
			(yyval.table)->join->left = (yyvsp[-7].table);
			(yyval.table)->join->right = (yyvsp[-4].table);
			auto left_col = Expr::makeColumnRef(strdup((yyvsp[-1].expr)->name));
			if ((yyvsp[-1].expr)->alias != nullptr) left_col->alias = strdup((yyvsp[-1].expr)->alias);
			if ((yyvsp[-7].table)->getName() != nullptr) left_col->table = strdup((yyvsp[-7].table)->getName());
			auto right_col = Expr::makeColumnRef(strdup((yyvsp[-1].expr)->name));
			if ((yyvsp[-1].expr)->alias != nullptr) right_col->alias = strdup((yyvsp[-1].expr)->alias);
			if ((yyvsp[-4].table)->getName() != nullptr) right_col->table = strdup((yyvsp[-4].table)->getName());
			(yyval.table)->join->condition = Expr::makeOpBinary(left_col, kOpEquals, right_col);
			delete (yyvsp[-1].expr);
		}
#line 4578 "bison_parser.cpp"
    break;

  case 257:
#line 1264 "bison_parser.y"
                                { (yyval.uval) = kJoinInner; }
#line 4584 "bison_parser.cpp"
    break;

  case 258:
#line 1265 "bison_parser.y"
                                { (yyval.uval) = kJoinLeft; }
#line 4590 "bison_parser.cpp"
    break;

  case 259:
#line 1266 "bison_parser.y"
                                { (yyval.uval) = kJoinLeft; }
#line 4596 "bison_parser.cpp"
    break;

  case 260:
#line 1267 "bison_parser.y"
                                { (yyval.uval) = kJoinRight; }
#line 4602 "bison_parser.cpp"
    break;

  case 261:
#line 1268 "bison_parser.y"
                                { (yyval.uval) = kJoinRight; }
#line 4608 "bison_parser.cpp"
    break;

  case 262:
#line 1269 "bison_parser.y"
                                { (yyval.uval) = kJoinFull; }
#line 4614 "bison_parser.cpp"
    break;

  case 263:
#line 1270 "bison_parser.y"
                                { (yyval.uval) = kJoinFull; }
#line 4620 "bison_parser.cpp"
    break;

  case 264:
#line 1271 "bison_parser.y"
                                { (yyval.uval) = kJoinFull; }
#line 4626 "bison_parser.cpp"
    break;

  case 265:
#line 1272 "bison_parser.y"
                                { (yyval.uval) = kJoinCross; }
#line 4632 "bison_parser.cpp"
    break;

  case 266:
#line 1273 "bison_parser.y"
                                        { (yyval.uval) = kJoinInner; }
#line 4638 "bison_parser.cpp"
    break;

  case 270:
#line 1293 "bison_parser.y"
                           { (yyval.str_vec) = new std::vector<char*>(); (yyval.str_vec)->push_back((yyvsp[0].sval)); }
#line 4644 "bison_parser.cpp"
    break;

  case 271:
#line 1294 "bison_parser.y"
                                               { (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval)); (yyval.str_vec) = (yyvsp[-2].str_vec); }
#line 4650 "bison_parser.cpp"
    break;


#line 4654 "bison_parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1297 "bison_parser.y"

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */
