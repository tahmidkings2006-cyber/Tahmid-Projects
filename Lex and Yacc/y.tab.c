/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20210109

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "calc.y"

#include "calc.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/************************************************************************
* Defines a yacc grammar for a simple calculator using infix
* notation.  WHen executed, the calculator enters a loop in
* which it prints the prompt >>, reads a toplevel expression
* terminated by a newline, and prints its value.  Operators
* include +, -, *, and = (assignment). Note that all
* expressions return values, even assignment.  Parentheses
* can be used to override operator precedence and
* associativity rules. Based on zcalc by ruiz@capsl.udel.edu
************************************************************************/

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 26 "calc.y"
typedef union {
  double dval;
  struct symtab *symp;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 52 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NAME 257
#define NUMBER 258
#define EQ 259
#define AND 260
#define OR 261
#define NOT 262
#define IF 263
#define UMINUS 264
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
static const YYINT yylen[] = {                            2,
    0,    3,    1,    1,    1,    1,    1,    3,    3,    3,
    3,    3,    3,    2,    3,    3,    3,    3,    3,    2,
    4,
};
static const YYINT yydefred[] = {                         1,
    0,    7,    6,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    4,    5,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    2,    0,    0,    0,    0,   11,
   10,   12,   13,   15,    0,    0,    0,    0,
};
static const YYINT yydgoto[] = {                          1,
   19,   20,
};
static const YYINT yysindex[] = {                         0,
  136,    0,    0,  170,  170,  170,  170, -256,  170,  170,
  170,  170,    0,    0,  170,  170,  170,  170, -253,   -7,
  -38,  -38, -253,  -38,  170,  -38,  -38,  -38,  -38, -253,
  -31,  -38,  -38,  170,    0, -253, -253,  -38, -253,    0,
    0,    0,    0,    0, -253, -253, -253, -253,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    0,  -10,    0,    0,    0,    0,    0,    0,   -2,
    0,    0,    0,    0,    0,   24,   32,    0,   58,    0,
    0,    0,    0,    0,   66,   92,  100,  128,
};
static const YYINT yygindex[] = {                         0,
  430,    0,
};
#define YYTABLESIZE 468
static const YYINT yytable[] = {                         20,
   25,   16,   35,   11,   10,   34,    9,   14,   12,   44,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   17,    8,   18,    0,    0,    0,    0,    0,   20,
   20,   20,   20,   18,   20,    0,   20,   14,   14,   14,
   14,   19,   14,    0,   14,    0,    0,    0,    0,   20,
   20,   20,    0,    0,    0,    0,    0,   14,   14,   14,
    0,    0,    0,   18,   18,   18,   18,    8,   18,    0,
   18,   19,   19,   19,   19,   16,   19,    0,   19,    0,
    0,    0,    0,   18,   18,   18,    0,   15,    0,    0,
    0,   19,   19,   19,    0,    0,    0,    8,    8,    8,
    8,   17,    8,    0,    8,   16,   16,   16,   16,    9,
   16,    0,   16,    0,    0,   20,    0,    8,    8,    8,
    0,    0,    0,   14,    0,   16,   16,   16,    0,    0,
    0,   17,   17,   17,   17,    0,   17,   21,   17,    9,
    9,    9,    9,    0,    9,    0,    9,    0,    0,   18,
    0,   17,   17,   17,    0,    0,    0,   19,    0,    9,
    9,    9,    0,    0,    0,    0,    0,   21,   21,   21,
   21,    0,   21,    0,   21,   16,    0,   11,   10,    0,
    9,   14,   12,    8,    0,    0,    0,   21,   21,   21,
    0,   16,    0,    0,    0,   17,    8,   18,   13,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   16,
    0,   11,   10,    0,    9,    0,   12,   17,    2,    3,
   34,    4,    5,    6,    7,    9,    0,   34,    0,   17,
    8,   18,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   20,   20,    0,   20,
   20,   20,   20,   21,   14,   14,    0,   14,   14,   14,
   14,   15,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   18,   18,    0,   18,   18,   18,   18,    0,   19,   19,
    0,   19,   19,   19,   19,   15,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    8,    8,    0,    8,    8,    8,
    8,    0,   16,   16,    0,   16,   16,   16,   16,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   17,   17,
    0,   17,   17,   17,   17,    0,    9,    9,    0,    9,
    9,    9,    9,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   21,   21,    0,   21,   21,   21,
   21,    0,    2,    3,    0,    4,    5,    6,    7,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,    3,    0,    4,
    5,    6,    7,   21,   22,   23,   24,    0,   26,   27,
   28,   29,    0,    0,   30,   31,   32,   33,    0,    0,
   36,   37,    0,   38,   39,   40,   41,   42,   43,    0,
    0,   45,   46,   47,    0,    0,    0,   48,
};
static const YYINT yycheck[] = {                         10,
  257,   40,   10,   42,   43,  259,   45,   10,   47,   41,
   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   40,
   41,   42,   43,   10,   45,   -1,   47,   40,   41,   42,
   43,   10,   45,   -1,   47,   -1,   -1,   -1,   -1,   60,
   61,   62,   -1,   -1,   -1,   -1,   -1,   60,   61,   62,
   -1,   -1,   -1,   40,   41,   42,   43,   10,   45,   -1,
   47,   40,   41,   42,   43,   10,   45,   -1,   47,   -1,
   -1,   -1,   -1,   60,   61,   62,   -1,  126,   -1,   -1,
   -1,   60,   61,   62,   -1,   -1,   -1,   40,   41,   42,
   43,   10,   45,   -1,   47,   40,   41,   42,   43,   10,
   45,   -1,   47,   -1,   -1,  126,   -1,   60,   61,   62,
   -1,   -1,   -1,  126,   -1,   60,   61,   62,   -1,   -1,
   -1,   40,   41,   42,   43,   -1,   45,   10,   47,   40,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,  126,
   -1,   60,   61,   62,   -1,   -1,   -1,  126,   -1,   60,
   61,   62,   -1,   -1,   -1,   -1,   -1,   40,   41,   42,
   43,   -1,   45,   -1,   47,   40,   -1,   42,   43,   -1,
   45,   46,   47,  126,   -1,   -1,   -1,   60,   61,   62,
   -1,  126,   -1,   -1,   -1,   60,   61,   62,   63,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   42,   43,   -1,   45,   -1,   47,  126,  257,  258,
  259,  260,  261,  262,  263,  126,   -1,  259,   -1,   60,
   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,   -1,  260,
  261,  262,  263,  126,  257,  258,   -1,  260,  261,  262,
  263,  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,   -1,  260,  261,  262,  263,   -1,  257,  258,
   -1,  260,  261,  262,  263,  126,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,   -1,  260,  261,  262,
  263,   -1,  257,  258,   -1,  260,  261,  262,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,
   -1,  260,  261,  262,  263,   -1,  257,  258,   -1,  260,
  261,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,   -1,  260,  261,  262,
  263,   -1,  257,  258,   -1,  260,  261,  262,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,   -1,  260,
  261,  262,  263,    4,    5,    6,    7,   -1,    9,   10,
   11,   12,   -1,   -1,   15,   16,   17,   18,   -1,   -1,
   21,   22,   -1,   24,   25,   26,   27,   28,   29,   -1,
   -1,   32,   33,   34,   -1,   -1,   -1,   38,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 264
#define YYUNDFTOKEN 269
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'","'.'","'/'",0,0,0,0,0,0,0,0,0,
0,0,0,"'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'~'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"NAME","NUMBER","EQ","AND","OR","NOT","IF","UMINUS",0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : session",
"session :",
"session : session toplevel '\\n'",
"toplevel : expr",
"toplevel : '?'",
"toplevel : '.'",
"expr : NUMBER",
"expr : NAME",
"expr : '=' NAME expr",
"expr : expr EQ expr",
"expr : '+' expr expr",
"expr : '-' expr expr",
"expr : '*' expr expr",
"expr : '/' expr expr",
"expr : '~' expr",
"expr : '(' expr ')'",
"expr : '<' expr expr",
"expr : '>' expr expr",
"expr : AND expr expr",
"expr : OR expr expr",
"expr : NOT expr",
"expr : IF expr expr expr",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 101 "calc.y"


struct symtab *
symlook(s)
char *s;
{
   char *p;
   struct symtab *sp;

   /* given the name of a symbol, scan the symbol table and
      either return the entry with matching name or add it
      to the next free cell in the symbol table. */

   for(sp = symtab; sp < &symtab[SYMBOLTABLESIZE]; sp++) {

     /* If the symbol table entry has a name and its equal
	to the one we are looking for, return this entry */
     if (sp->name && !strcmp(sp->name, s))
       return sp;

     /* If the name is empty then this entry is free, so the
	symbol must not be in the table and we can add it here
        and return this entry. */
     if (!sp->name) {
       sp->name = strdup(s);
       return sp;
       }
   }

   /* We searched the entire symbol table and neither found
      the symbol or an unused entry.  So the table must be
      full.  Sigh. */
   yyerror("The symbol table is full, sorry...\n");
   exit(1);
}



void printHelp() 
{ /* print calculator help and return */
  printf("Enter an expression in infix notation followed by a newline.\n");
  printf("Operators include +, -, * and =.  Defined functions include\n");
  printf("sqrt, exp and log.  You can assign a variable using the =\n");
  printf("operator. Type . to exit.  Syntax errors will terminate the\n");
  printf("program, so be careful.\n");
}


/* If error prints error and Do not accept to signify bad syntax in
   program */

void yyerror(char *msg)	/* yacc error function */
{
  printf("%s \n" , msg);  
}

int main()
{ /* print herald and call parser */
  printf("331 Calculator\n(type ? for help and . to exit)\n\n>> ");
  yyparse();
}
#line 379 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 3:
#line 79 "calc.y"
	{ printf("%g\n\n>> ", yystack.l_mark[0].dval); }
break;
case 4:
#line 80 "calc.y"
	{ printHelp(); printf("\n>> "); }
break;
case 5:
#line 81 "calc.y"
	{ printf("Exiting 331 calc\n"); exit(1); }
break;
case 6:
#line 84 "calc.y"
	{ yyval.dval = yystack.l_mark[0].dval; }
break;
case 7:
#line 85 "calc.y"
	{ yyval.dval = yystack.l_mark[0].symp->value; }
break;
case 8:
#line 86 "calc.y"
	{ yystack.l_mark[-1].symp->value = yystack.l_mark[0].dval; yyval.dval = yystack.l_mark[0].dval; }
break;
case 9:
#line 87 "calc.y"
	{ yyval.dval = yystack.l_mark[-2].dval == yystack.l_mark[0].dval; }
break;
case 10:
#line 88 "calc.y"
	{ yyval.dval = yystack.l_mark[-1].dval + yystack.l_mark[0].dval; }
break;
case 11:
#line 89 "calc.y"
	{ yyval.dval = yystack.l_mark[-1].dval - yystack.l_mark[0].dval; }
break;
case 12:
#line 90 "calc.y"
	{ yyval.dval = yystack.l_mark[-1].dval * yystack.l_mark[0].dval; }
break;
case 13:
#line 91 "calc.y"
	{ yyval.dval = yystack.l_mark[-1].dval / yystack.l_mark[0].dval; }
break;
case 14:
#line 92 "calc.y"
	{ yyval.dval = -yystack.l_mark[0].dval; }
break;
case 15:
#line 93 "calc.y"
	{ yyval.dval = yystack.l_mark[-1].dval; }
break;
case 16:
#line 94 "calc.y"
	{ yyval.dval = yystack.l_mark[-1].dval < yystack.l_mark[0].dval; }
break;
case 17:
#line 95 "calc.y"
	{ yyval.dval = yystack.l_mark[-1].dval > yystack.l_mark[0].dval; }
break;
case 18:
#line 96 "calc.y"
	{ yyval.dval = yystack.l_mark[-1].dval && yystack.l_mark[0].dval; }
break;
case 19:
#line 97 "calc.y"
	{ yyval.dval = yystack.l_mark[-1].dval || yystack.l_mark[0].dval; }
break;
case 20:
#line 98 "calc.y"
	{ yyval.dval = !yystack.l_mark[0].dval; }
break;
case 21:
#line 99 "calc.y"
	{ yyval.dval = yystack.l_mark[-2].dval ? yystack.l_mark[-1].dval : yystack.l_mark[0].dval; }
break;
#line 654 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
