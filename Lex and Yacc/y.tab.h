#define NAME 257
#define NUMBER 258
#define EQ 259
#define AND 260
#define OR 261
#define NOT 262
#define IF 263
#define UMINUS 264
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  double dval;
  struct symtab *symp;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
