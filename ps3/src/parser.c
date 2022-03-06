/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include <vslc.h>

#define N0C(n,t,d) do { \
    node_init ( n = malloc(sizeof(node_t)), t, d, 0 ); \
} while ( false )
#define N1C(n,t,d,a) do { \
    node_init ( n = malloc(sizeof(node_t)), t, d, 1, a ); \
} while ( false )
#define N2C(n,t,d,a,b) do { \
    node_init ( n = malloc(sizeof(node_t)), t, d, 2, a, b ); \
} while ( false )
#define N3C(n,t,d,a,b,c) do { \
    node_init ( n = malloc(sizeof(node_t)), t, d, 3, a, b, c ); \
} while ( false )


#line 89 "y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '|'  */
  YYSYMBOL_4_ = 4,                         /* '^'  */
  YYSYMBOL_5_ = 5,                         /* '&'  */
  YYSYMBOL_6_ = 6,                         /* '+'  */
  YYSYMBOL_7_ = 7,                         /* '-'  */
  YYSYMBOL_8_ = 8,                         /* '*'  */
  YYSYMBOL_9_ = 9,                         /* '/'  */
  YYSYMBOL_UMINUS = 10,                    /* UMINUS  */
  YYSYMBOL_11_ = 11,                       /* '~'  */
  YYSYMBOL_FUNC = 12,                      /* FUNC  */
  YYSYMBOL_PRINT = 13,                     /* PRINT  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 15,                  /* CONTINUE  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_THEN = 17,                      /* THEN  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_OPENBLOCK = 21,                 /* OPENBLOCK  */
  YYSYMBOL_CLOSEBLOCK = 22,                /* CLOSEBLOCK  */
  YYSYMBOL_VAR = 23,                       /* VAR  */
  YYSYMBOL_NUMBER = 24,                    /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 25,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 26,                    /* STRING  */
  YYSYMBOL_27_ = 27,                       /* ','  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* ':'  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '<'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_global_list = 36,               /* global_list  */
  YYSYMBOL_global = 37,                    /* global  */
  YYSYMBOL_statement_list = 38,            /* statement_list  */
  YYSYMBOL_print_list = 39,                /* print_list  */
  YYSYMBOL_expression_list = 40,           /* expression_list  */
  YYSYMBOL_variable_list = 41,             /* variable_list  */
  YYSYMBOL_argument_list = 42,             /* argument_list  */
  YYSYMBOL_parameter_list = 43,            /* parameter_list  */
  YYSYMBOL_declaration_list = 44,          /* declaration_list  */
  YYSYMBOL_function = 45,                  /* function  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_block = 47,                     /* block  */
  YYSYMBOL_assignment_statement = 48,      /* assignment_statement  */
  YYSYMBOL_return_statement = 49,          /* return_statement  */
  YYSYMBOL_print_statement = 50,           /* print_statement  */
  YYSYMBOL_null_statement = 51,            /* null_statement  */
  YYSYMBOL_if_statement = 52,              /* if_statement  */
  YYSYMBOL_while_statement = 53,           /* while_statement  */
  YYSYMBOL_relation = 54,                  /* relation  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_declaration = 56,               /* declaration  */
  YYSYMBOL_print_item = 57,                /* print_item  */
  YYSYMBOL_identifier = 58,                /* identifier  */
  YYSYMBOL_number = 59,                    /* number  */
  YYSYMBOL_string = 60                     /* string  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     5,     2,
      28,    29,     8,     6,    27,     7,     2,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,     2,
      32,    31,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     2,    11,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    10,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    33,    33,    36,    37,    40,    41,    44,    45,    48,
      49,    52,    53,    56,    57,    60,    61,    64,    65,    68,
      69,    72,    76,    77,    78,    79,    80,    81,    82,    85,
      87,    90,    92,    94,    96,    98,   102,   106,   110,   114,
     116,   120,   124,   126,   128,   132,   134,   136,   138,   140,
     142,   144,   146,   148,   150,   151,   152,   154,   158,   161,
     163,   166,   167,   173
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "'|'", "'^'", "'&'",
  "'+'", "'-'", "'*'", "'/'", "UMINUS", "'~'", "FUNC", "PRINT", "RETURN",
  "CONTINUE", "IF", "THEN", "ELSE", "WHILE", "DO", "OPENBLOCK",
  "CLOSEBLOCK", "VAR", "NUMBER", "IDENTIFIER", "STRING", "','", "'('",
  "')'", "':'", "'='", "'<'", "'>'", "$accept", "program", "global_list",
  "global", "statement_list", "print_list", "expression_list",
  "variable_list", "argument_list", "parameter_list", "declaration_list",
  "function", "statement", "block", "assignment_statement",
  "return_statement", "print_statement", "null_statement", "if_statement",
  "while_statement", "relation", "expression", "declaration", "print_item",
  "identifier", "number", "string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   124,    94,    38,    43,    45,    42,    47,
     258,   126,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,    44,    40,    41,
      58,    61,    60,    62
};
#endif

#define YYPACT_NINF (-23)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,   -20,   -20,    19,    -8,   -23,   -23,   -23,   -23,    -3,
       0,   -23,   -23,   -23,   -20,   -20,     0,     2,   -23,   143,
      94,   101,   -23,   101,   101,     7,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,    57,   101,   101,   -23,   -23,   101,
      11,   166,   -23,    20,   -23,   -23,   166,    36,     3,    37,
     117,     7,   -23,   -23,    25,    28,    29,    31,    40,   -23,
     -23,    38,    94,   101,   101,   101,   101,   101,   101,   101,
     101,   143,   101,   101,   101,   143,   -23,   -23,   130,   -23,
     101,   101,   101,   101,   101,   -23,   -23,   172,   108,   176,
       8,     8,   -23,   -23,    41,    43,   166,    51,   166,   166,
     166,   -23,   -23,   166,   166,   166,   166,   166,   101,   -23,
     143,   166,   -23
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     5,     6,    61,     0,
      58,    13,     1,     4,    18,     0,    17,     0,    14,     0,
       0,     0,    38,     0,     0,     0,    21,    28,    22,    23,
      24,    27,    25,    26,     0,     0,     0,    62,    63,     0,
      37,    59,     9,    56,    55,    60,    36,     0,     0,     0,
       0,     0,     7,    19,     0,     0,     0,     0,     0,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    30,     8,     0,    20,
       0,     0,     0,     0,     0,    54,    10,    45,    46,    47,
      48,    49,    50,    51,    15,     0,    11,    39,    42,    43,
      44,    41,    29,    32,    33,    34,    35,    31,     0,    57,
       0,    12,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,   -23,   -23,    69,    24,   -23,   -23,    62,   -23,   -23,
     -23,   -23,   -17,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
      54,    16,   -22,    30,    -1,   -23,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    50,    40,    94,    10,    95,    17,
      51,     6,    52,    27,    28,    29,    30,    31,    32,    33,
      47,    41,     7,    42,    43,    44,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       9,    11,    26,    53,     1,     8,    63,    64,    65,    66,
      67,    68,    69,    11,    18,     2,    68,    69,    34,    12,
      20,    21,    22,    23,    34,    14,    24,    15,    25,    79,
       2,    19,     8,    77,    72,    73,    74,    46,    62,    48,
      48,    63,    64,    65,    66,    67,    68,    69,    70,    34,
      34,    59,    60,    71,    97,    61,    80,    75,   101,    81,
      82,    77,    83,    54,    55,    56,    57,    85,   108,   110,
      34,    84,   109,    13,    34,    78,    16,    34,    49,    87,
      88,    89,    90,    91,    92,    93,    96,    58,    98,    99,
     100,     0,    86,   112,     0,     0,   103,   104,   105,   106,
     107,    35,     0,     0,     0,    36,     0,     0,    35,    34,
       0,     0,    36,    65,    66,    67,    68,    69,    37,     8,
      38,     0,    39,     0,   111,    37,     8,     0,     0,    39,
      20,    21,    22,    23,     0,     0,    24,     0,    25,    76,
       0,     0,     8,    20,    21,    22,    23,     0,     0,    24,
       0,    25,   102,     0,     0,     8,    20,    21,    22,    23,
       0,     0,    24,     0,    25,     0,     0,     0,     8,    63,
      64,    65,    66,    67,    68,    69,    64,    65,    66,    67,
      68,    69,    66,    67,    68,    69
};

static const yytype_int8 yycheck[] =
{
       1,     2,    19,    25,    12,    25,     3,     4,     5,     6,
       7,     8,     9,    14,    15,    23,     8,     9,    19,     0,
      13,    14,    15,    16,    25,    28,    19,    27,    21,    51,
      23,    29,    25,    50,    31,    32,    33,    21,    27,    23,
      24,     3,     4,     5,     6,     7,     8,     9,    28,    50,
      51,    35,    36,    17,    71,    39,    31,    20,    75,    31,
      31,    78,    31,     6,     7,     8,     9,    29,    27,    18,
      71,    31,    29,     4,    75,    51,    14,    78,    24,    63,
      64,    65,    66,    67,    68,    69,    70,    30,    72,    73,
      74,    -1,    62,   110,    -1,    -1,    80,    81,    82,    83,
      84,     7,    -1,    -1,    -1,    11,    -1,    -1,     7,   110,
      -1,    -1,    11,     5,     6,     7,     8,     9,    24,    25,
      26,    -1,    28,    -1,   108,    24,    25,    -1,    -1,    28,
      13,    14,    15,    16,    -1,    -1,    19,    -1,    21,    22,
      -1,    -1,    25,    13,    14,    15,    16,    -1,    -1,    19,
      -1,    21,    22,    -1,    -1,    25,    13,    14,    15,    16,
      -1,    -1,    19,    -1,    21,    -1,    -1,    -1,    25,     3,
       4,     5,     6,     7,     8,     9,     4,     5,     6,     7,
       8,     9,     6,     7,     8,     9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    23,    35,    36,    37,    45,    56,    25,    58,
      41,    58,     0,    37,    28,    27,    41,    43,    58,    29,
      13,    14,    15,    16,    19,    21,    46,    47,    48,    49,
      50,    51,    52,    53,    58,     7,    11,    24,    26,    28,
      39,    55,    57,    58,    59,    60,    55,    54,    55,    54,
      38,    44,    46,    56,     6,     7,     8,     9,    30,    55,
      55,    55,    27,     3,     4,     5,     6,     7,     8,     9,
      28,    17,    31,    32,    33,    20,    22,    46,    38,    56,
      31,    31,    31,    31,    31,    29,    57,    55,    55,    55,
      55,    55,    55,    55,    40,    42,    55,    46,    55,    55,
      55,    46,    22,    55,    55,    55,    55,    55,    27,    29,
      18,    55,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    40,    41,    41,    42,    42,    43,    43,    44,
      44,    45,    46,    46,    46,    46,    46,    46,    46,    47,
      47,    48,    48,    48,    48,    48,    49,    50,    51,    52,
      52,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    57,
      57,    58,    59,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     3,     1,     3,     1,     0,     1,     0,     1,
       2,     6,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     4,     4,     4,     4,     4,     2,     2,     1,     4,
       6,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     1,     4,     2,     1,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  YY_STACK_PRINT (yyss, yyssp);

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: global_list  */
#line 33 "src/parser.y"
                  { N1C ( root, PROGRAM, NULL, yyvsp[0] ); }
#line 1234 "y.tab.c"
    break;

  case 3: /* global_list: global  */
#line 36 "src/parser.y"
             { N1C ( yyval, GLOBAL_LIST, NULL, yyvsp[0] ); }
#line 1240 "y.tab.c"
    break;

  case 4: /* global_list: global_list global  */
#line 37 "src/parser.y"
                         { N2C ( yyval, GLOBAL_LIST, NULL, yyvsp[-1], yyvsp[0] ); }
#line 1246 "y.tab.c"
    break;

  case 5: /* global: function  */
#line 40 "src/parser.y"
               { N1C ( yyval, GLOBAL, NULL, yyvsp[0] ); }
#line 1252 "y.tab.c"
    break;

  case 6: /* global: declaration  */
#line 41 "src/parser.y"
                  { N1C ( yyval, GLOBAL, NULL, yyvsp[0] ); }
#line 1258 "y.tab.c"
    break;

  case 7: /* statement_list: statement  */
#line 44 "src/parser.y"
                { N1C ( yyval, STATEMENT_LIST, NULL, yyvsp[0] ); }
#line 1264 "y.tab.c"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 45 "src/parser.y"
                               { N2C ( yyval, STATEMENT_LIST, NULL, yyvsp[-1], yyvsp[0] ); }
#line 1270 "y.tab.c"
    break;

  case 9: /* print_list: print_item  */
#line 48 "src/parser.y"
                 { N1C ( yyval, PRINT_LIST, NULL, yyvsp[0] ); }
#line 1276 "y.tab.c"
    break;

  case 10: /* print_list: print_list ',' print_item  */
#line 49 "src/parser.y"
                                { N2C ( yyval, PRINT_LIST, NULL, yyvsp[-2], yyvsp[0] ); }
#line 1282 "y.tab.c"
    break;

  case 11: /* expression_list: expression  */
#line 52 "src/parser.y"
                 { N1C ( yyval, EXPRESSION_LIST, NULL, yyvsp[0] ); }
#line 1288 "y.tab.c"
    break;

  case 12: /* expression_list: expression_list ',' expression  */
#line 53 "src/parser.y"
                                     { N2C(yyval, EXPRESSION_LIST, NULL, yyvsp[-2], yyvsp[0]); }
#line 1294 "y.tab.c"
    break;

  case 13: /* variable_list: identifier  */
#line 56 "src/parser.y"
                 { N1C ( yyval, VARIABLE_LIST, NULL, yyvsp[0] ); }
#line 1300 "y.tab.c"
    break;

  case 14: /* variable_list: variable_list ',' identifier  */
#line 57 "src/parser.y"
                                   { N2C ( yyval, VARIABLE_LIST, NULL, yyvsp[-2], yyvsp[0] ); }
#line 1306 "y.tab.c"
    break;

  case 15: /* argument_list: expression_list  */
#line 60 "src/parser.y"
                      { N1C ( yyval, ARGUMENT_LIST, NULL, yyvsp[0] ); }
#line 1312 "y.tab.c"
    break;

  case 16: /* argument_list: %empty  */
#line 61 "src/parser.y"
                    { yyval = NULL; }
#line 1318 "y.tab.c"
    break;

  case 17: /* parameter_list: variable_list  */
#line 64 "src/parser.y"
                    { N1C ( yyval, PARAMETER_LIST, NULL, yyvsp[0] ); }
#line 1324 "y.tab.c"
    break;

  case 18: /* parameter_list: %empty  */
#line 65 "src/parser.y"
                    { yyval = NULL; }
#line 1330 "y.tab.c"
    break;

  case 19: /* declaration_list: declaration  */
#line 68 "src/parser.y"
                  { N1C ( yyval, DECLARATION_LIST, NULL, yyvsp[0] ); }
#line 1336 "y.tab.c"
    break;

  case 20: /* declaration_list: declaration_list declaration  */
#line 69 "src/parser.y"
                                   { N2C (yyval, DECLARATION_LIST, NULL, yyvsp[-1], yyvsp[0]); }
#line 1342 "y.tab.c"
    break;

  case 21: /* function: FUNC identifier '(' parameter_list ')' statement  */
#line 73 "src/parser.y"
        { N3C ( yyval, FUNCTION, NULL, yyvsp[-4], yyvsp[-2], yyvsp[0] ); }
#line 1348 "y.tab.c"
    break;

  case 22: /* statement: assignment_statement  */
#line 76 "src/parser.y"
                           { N1C ( yyval, STATEMENT, NULL, yyvsp[0] ); }
#line 1354 "y.tab.c"
    break;

  case 23: /* statement: return_statement  */
#line 77 "src/parser.y"
                       { N1C ( yyval, STATEMENT, NULL, yyvsp[0] ); }
#line 1360 "y.tab.c"
    break;

  case 24: /* statement: print_statement  */
#line 78 "src/parser.y"
                      { N1C ( yyval, STATEMENT, NULL, yyvsp[0] ); }
#line 1366 "y.tab.c"
    break;

  case 25: /* statement: if_statement  */
#line 79 "src/parser.y"
                   { N1C ( yyval, STATEMENT, NULL, yyvsp[0] ); }
#line 1372 "y.tab.c"
    break;

  case 26: /* statement: while_statement  */
#line 80 "src/parser.y"
                      { N1C ( yyval, STATEMENT, NULL, yyvsp[0] ); }
#line 1378 "y.tab.c"
    break;

  case 27: /* statement: null_statement  */
#line 81 "src/parser.y"
                     { N1C ( yyval, STATEMENT, NULL, yyvsp[0] ); }
#line 1384 "y.tab.c"
    break;

  case 28: /* statement: block  */
#line 82 "src/parser.y"
            { N1C ( yyval, STATEMENT, NULL, yyvsp[0] ); }
#line 1390 "y.tab.c"
    break;

  case 29: /* block: OPENBLOCK declaration_list statement_list CLOSEBLOCK  */
#line 86 "src/parser.y"
        { N2C (yyval, BLOCK, NULL, yyvsp[-2], yyvsp[-1]); }
#line 1396 "y.tab.c"
    break;

  case 30: /* block: OPENBLOCK statement_list CLOSEBLOCK  */
#line 87 "src/parser.y"
                                          { N1C (yyval, BLOCK, NULL, yyvsp[-1] ); }
#line 1402 "y.tab.c"
    break;

  case 31: /* assignment_statement: identifier ':' '=' expression  */
#line 91 "src/parser.y"
        { N2C ( yyval, ASSIGNMENT_STATEMENT, NULL, yyvsp[-3], yyvsp[0] ); }
#line 1408 "y.tab.c"
    break;

  case 32: /* assignment_statement: identifier '+' '=' expression  */
#line 93 "src/parser.y"
        { N2C ( yyval, ADD_STATEMENT, NULL, yyvsp[-3], yyvsp[0] ); }
#line 1414 "y.tab.c"
    break;

  case 33: /* assignment_statement: identifier '-' '=' expression  */
#line 95 "src/parser.y"
        { N2C ( yyval, SUBTRACT_STATEMENT, NULL, yyvsp[-3], yyvsp[0] ); }
#line 1420 "y.tab.c"
    break;

  case 34: /* assignment_statement: identifier '*' '=' expression  */
#line 97 "src/parser.y"
        { N2C ( yyval, MULTIPLY_STATEMENT, NULL, yyvsp[-3], yyvsp[0] ); }
#line 1426 "y.tab.c"
    break;

  case 35: /* assignment_statement: identifier '/' '=' expression  */
#line 99 "src/parser.y"
        { N2C ( yyval, DIVIDE_STATEMENT, NULL, yyvsp[-3], yyvsp[0] ); }
#line 1432 "y.tab.c"
    break;

  case 36: /* return_statement: RETURN expression  */
#line 103 "src/parser.y"
        { N1C ( yyval, RETURN_STATEMENT, NULL, yyvsp[0] ); }
#line 1438 "y.tab.c"
    break;

  case 37: /* print_statement: PRINT print_list  */
#line 107 "src/parser.y"
        { N1C ( yyval, PRINT_STATEMENT, NULL, yyvsp[0] ); }
#line 1444 "y.tab.c"
    break;

  case 38: /* null_statement: CONTINUE  */
#line 111 "src/parser.y"
        { N0C ( yyval, NULL_STATEMENT, NULL ); }
#line 1450 "y.tab.c"
    break;

  case 39: /* if_statement: IF relation THEN statement  */
#line 115 "src/parser.y"
        { N2C ( yyval, IF_STATEMENT, NULL, yyvsp[-2], yyvsp[0] ); }
#line 1456 "y.tab.c"
    break;

  case 40: /* if_statement: IF relation THEN statement ELSE statement  */
#line 117 "src/parser.y"
        { N3C ( yyval, IF_STATEMENT, NULL, yyvsp[-4], yyvsp[-2], yyvsp[0] ); }
#line 1462 "y.tab.c"
    break;

  case 41: /* while_statement: WHILE relation DO statement  */
#line 121 "src/parser.y"
        { N2C ( yyval, WHILE_STATEMENT, NULL, yyvsp[-2], yyvsp[0] ); }
#line 1468 "y.tab.c"
    break;

  case 42: /* relation: expression '=' expression  */
#line 125 "src/parser.y"
        { N2C ( yyval, RELATION, strdup("="), yyvsp[-2], yyvsp[0] ); }
#line 1474 "y.tab.c"
    break;

  case 43: /* relation: expression '<' expression  */
#line 127 "src/parser.y"
        { N2C ( yyval, RELATION, strdup("<"), yyvsp[-2], yyvsp[0] ); }
#line 1480 "y.tab.c"
    break;

  case 44: /* relation: expression '>' expression  */
#line 129 "src/parser.y"
        { N2C ( yyval, RELATION, strdup(">"), yyvsp[-2], yyvsp[0] ); }
#line 1486 "y.tab.c"
    break;

  case 45: /* expression: expression '|' expression  */
#line 133 "src/parser.y"
        { N2C ( yyval, EXPRESSION, strdup("|"), yyvsp[-2], yyvsp[0] ); }
#line 1492 "y.tab.c"
    break;

  case 46: /* expression: expression '^' expression  */
#line 135 "src/parser.y"
        { N2C ( yyval, EXPRESSION, strdup("^"), yyvsp[-2], yyvsp[0] ); }
#line 1498 "y.tab.c"
    break;

  case 47: /* expression: expression '&' expression  */
#line 137 "src/parser.y"
        { N2C ( yyval, EXPRESSION, strdup("&"), yyvsp[-2], yyvsp[0] ); }
#line 1504 "y.tab.c"
    break;

  case 48: /* expression: expression '+' expression  */
#line 139 "src/parser.y"
        { N2C ( yyval, EXPRESSION, strdup("+"), yyvsp[-2], yyvsp[0] ); }
#line 1510 "y.tab.c"
    break;

  case 49: /* expression: expression '-' expression  */
#line 141 "src/parser.y"
        { N2C ( yyval, EXPRESSION, strdup("-"), yyvsp[-2], yyvsp[0] ); }
#line 1516 "y.tab.c"
    break;

  case 50: /* expression: expression '*' expression  */
#line 143 "src/parser.y"
        { N2C ( yyval, EXPRESSION, strdup("*"), yyvsp[-2], yyvsp[0] ); }
#line 1522 "y.tab.c"
    break;

  case 51: /* expression: expression '/' expression  */
#line 145 "src/parser.y"
        { N2C ( yyval, EXPRESSION, strdup("/"), yyvsp[-2], yyvsp[0] ); }
#line 1528 "y.tab.c"
    break;

  case 52: /* expression: '-' expression  */
#line 147 "src/parser.y"
        { N1C ( yyval, EXPRESSION, strdup("-"), yyvsp[0] ); }
#line 1534 "y.tab.c"
    break;

  case 53: /* expression: '~' expression  */
#line 149 "src/parser.y"
        { N1C ( yyval, EXPRESSION, strdup("~"), yyvsp[0] ); }
#line 1540 "y.tab.c"
    break;

  case 54: /* expression: '(' expression ')'  */
#line 150 "src/parser.y"
                         { yyval = yyvsp[-1]; }
#line 1546 "y.tab.c"
    break;

  case 55: /* expression: number  */
#line 151 "src/parser.y"
             { N1C ( yyval, EXPRESSION, NULL, yyvsp[0] ); }
#line 1552 "y.tab.c"
    break;

  case 56: /* expression: identifier  */
#line 153 "src/parser.y"
        { N1C ( yyval, EXPRESSION, NULL, yyvsp[0] ); }
#line 1558 "y.tab.c"
    break;

  case 57: /* expression: identifier '(' argument_list ')'  */
#line 155 "src/parser.y"
        { N2C ( yyval, EXPRESSION, NULL, yyvsp[-3], yyvsp[-1] ); }
#line 1564 "y.tab.c"
    break;

  case 58: /* declaration: VAR variable_list  */
#line 158 "src/parser.y"
                        { N1C ( yyval, DECLARATION, NULL, yyvsp[0] ); }
#line 1570 "y.tab.c"
    break;

  case 59: /* print_item: expression  */
#line 162 "src/parser.y"
        { N1C ( yyval, PRINT_ITEM, NULL, yyvsp[0] ); }
#line 1576 "y.tab.c"
    break;

  case 60: /* print_item: string  */
#line 164 "src/parser.y"
        { N1C ( yyval, PRINT_ITEM, NULL, yyvsp[0] ); }
#line 1582 "y.tab.c"
    break;

  case 61: /* identifier: IDENTIFIER  */
#line 166 "src/parser.y"
                       { N0C(yyval, IDENTIFIER_DATA, strdup(yytext) ); }
#line 1588 "y.tab.c"
    break;

  case 62: /* number: NUMBER  */
#line 168 "src/parser.y"
      {
        int64_t *value = malloc ( sizeof(int64_t) );
        *value = strtol ( yytext, NULL, 10 );
        N0C(yyval, NUMBER_DATA, value );
      }
#line 1598 "y.tab.c"
    break;

  case 63: /* string: STRING  */
#line 173 "src/parser.y"
               { N0C(yyval, STRING_DATA, strdup(yytext) ); }
#line 1604 "y.tab.c"
    break;


#line 1608 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 174 "src/parser.y"


int
yyerror ( const char *error )
{
    fprintf ( stderr, "%s on line %d\n", error, yylineno );
    exit ( EXIT_FAILURE );
}
