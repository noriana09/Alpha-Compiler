#include "symtable.h"
#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(struct quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(struct quad)+CURR_SIZE)

//global vars

struct quad* quads=(struct quad*)0;
unsigned total=0;
unsigned int currQuad=0;
unsigned programVarOffset=0;
unsigned functionLocalOffset=0;
unsigned formalArgOffset=0;
unsigned scopeSpaceCounter=1;   //kata thn eisodo se formal +1, kata thn eksodo apo sunarthsh -2
int max_scope=0;
int tmp_scope;
int tempcounter=0;
int tempfuncounter=0;

struct LabelStack { 
  int label; 
  struct LabelStack* next;
};

struct LabelStack* top=NULL;
struct LabelStack* topLabel=NULL;
struct LabelStack* topWhile=NULL;
struct LabelStack* topWhile1=NULL;
struct LabelStack* topWhile2=NULL;
struct LabelStack* topWhile3=NULL;
struct LabelStack* topFor=NULL;
struct LabelStack* topFor1=NULL;
struct LabelStack* topFor2=NULL;
struct LabelStack* topFor3=NULL;

struct IfStack{
  int label;
  struct IfStack* next;
};
struct IfStack* topIf1=NULL;
struct IfStack* topIf2=NULL;
struct IfStack* topIf3=NULL;

struct OffsetStack { 
  int offset; 
  struct OffsetStack* next;
};
struct OffsetStack* topOffset=NULL;

struct forloop {
  int test;
  int enter;
};

enum iopcode {
  assign, add, sub, mul, divv, mod, uminus, and, or, not,
  if_eq, if_noteq, if_lesseq, if_greatereq, if_less, if_greater,
  call, param, ret, getretval, funcstart, funcend, tablecreate, 
  tablegetelem, tablesetelem,jump
};

enum expr_t {
  var_e, tableitem_e, programfunc_e, libraryfunc_e, arithexpr_e,
  boolexpr_e, assignexpr_e, newtable_e, constnum_e, constbool_e, 
  conststring_e, nil_e
};

struct call {
  struct expr* elist;
  unsigned char method;
  char* name;
};

//eidikes entoles

struct stmt_t {
  int quadNo;
  struct stmt_t *next;
};
struct stmt_t* topHeadAnd1=NULL;
struct stmt_t* butomHeadAnd1=NULL;
struct stmt_t* topHeadAnd2=NULL;
struct stmt_t* butomHeadAnd2=NULL;

struct Lc_stack_t {
  struct stmt_t* breakList;
  struct stmt_t* continueList;
  struct Lc_stack_t* next;
  unsigned counter;
} ;
struct Lc_stack_t*lcs_topB=NULL;
struct Lc_stack_t*lsc_bottomB=NULL; 
struct Lc_stack_t*lcs_topC=NULL;
struct Lc_stack_t*lsc_bottomC=NULL;

struct expr {
  enum iopcode op;
  enum expr_t type;
  SymbolTableEntry* sym;
  struct expr* index;
  struct expr* value;
  struct stmt_t* truelist;
  struct stmt_t* falselist;
  double numConst;
  char* strConst;
  unsigned char boolConst;
  struct expr* next;
};

struct quad {
  enum iopcode op;
  struct expr* result;
  struct expr* arg1;
  struct expr* arg2;
  unsigned label;
  unsigned line;
};
