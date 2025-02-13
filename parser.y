%{
#include "scanner.h"
#define YYDEBUG 1
void yyerror(char* yaccProvidedMessage);
extern int yylineno;
extern struct expr* lvalue_expr(Node sym);
extern char* yytext;
extern FILE* yyin;
int a=0;
int apot_not=0;
int apotimisi_not=0;
int scope=0;
int cont=0;
int cont1=0;
int cont2=0;
int apotimisi_and=0;
int apotimisi_or=0;
int tmpAnd1=0;
int mikrotero=0;
int tmpMikr=0;
int tmpAnd2=0;
int yylex();
char* newtempname();
int LoopCounter=0;
int flag=0;
int f=0;
int isInFunc=0;
int StartJump=-1; // gia ta jumps stis edoles if
int EndJump=-1;  //  ---//---
HashTable p;
struct forloop;
void Quad_Print();
void resettemp();
struct stmt_t* merge(struct stmt_t* l1,struct stmt_t* l2);
struct expr* Insert(struct expr* x);
void pushLoop(int label, struct LabelStack**top);
void pushIf(int label, struct IfStack**top);
int popLoop(struct LabelStack**top);
int popIf(struct IfStack**top);
void pushLabel(struct LabelStack**top,int label);
void pushOffset(int offset);
int pop_and_top();
int pop(struct LabelStack**top);
void patchlist(int list,int label);
void emit (enum iopcode op,struct expr* arg1,struct expr* arg2, struct expr* result, unsigned label, unsigned line);
void check_arith (struct expr* e, const char* context);
unsigned nextquadlabel();
Node newtemp();
struct stmt_t* makelist(int quadno);
void backpatch(struct stmt_t *list, int quadno);
struct expr* newexpr(enum expr_t t);
struct expr* newexpr_conststring(char *s);
struct expr* newexpr_constnum (double i);
struct expr* newexpr_constbool (unsigned int b);
struct expr* newexpr_constnil();
struct expr* emit_iftableitem(struct expr* e);
char* newtempfuncname();
void exitscopespace(void);
void resetformalargoffset(void);
void resetfunctionoffset(void);
void enterscopespace(void);
void inccurrsopeoffset(void);
void printstack();
enum scopespace_t currscopespace(void);
unsigned currscopeoffset(void);
void restorecurrscopeoffset(unsigned n);
struct expr* member_item(struct expr* lv, char* name);
struct expr* make_call(struct expr* lv, struct expr* reversed_elist);
void patchlabel(unsigned quadNo, unsigned label);
void pushB(struct stmt_t* breakList, struct stmt_t* continueList);
int popB();
void pushC(struct stmt_t* breakList, struct stmt_t* continueList);
int popC();
int popAND();
void pushAND(int quadNo);
%}



%start program
%union{
    int intVal;
    char* stringVal;
    float floatVal;
    struct forloop* forVal;
    struct expr* exprVal;
    struct call* call;
    struct SymbolTableEntry *tptr;
    struct Lc_stack_t* loop;
}

%type <exprVal>  indexed indexedelem expr assignexpr elist call lvalue member const term primary stmt objectdef returnstmt
%type <stringVal> funcname idlist block 
%type <tptr> funcprefix funcargs funcdef 
%type <intVal> funcbody ifprefix elseprefix ifstmt whilestart whilecond M N
%type<call>methodcall callsuffix normcall
%type <forVal> forprefix 

%token <intVal> NUMBER 
%token <stringVal> ID IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND NOT OR LOC TRUE FALSE  NIL ASSIGNMENT PLUS MINUS MUL DIV MOD EQUAL_TO NOT_EQUAL_TO PLUS_PLUS MINUS_MINUS GREATER_THAN LESS_THAN GREATER_THAN_OR_EQUAL LESS_THAN_OR_EQUAL STRING LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET LEFT_PARENTHESIS RIGHT_PARENTHESIS SEMICOLON COMMA COLON DOUBLE_COLON DOT DOUBLE_DOT 
%right ASSIGNMENT
%left OR
%left AND
%nonassoc GREATER_THAN GREATER_THAN_OR_EQUAL LESS_THAN LESS_THAN_OR_EQUAL EQUAL_TO NOT_EQUAL_TO 
%left PLUS MINUS
%left MUL DIV MOD 
%right NOT PLUS_PLUS MINUS_MINUS UMINUS
%left DOT DOUBLE_DOT
%left LEFT_BRACKET RIGHT_BRACKET
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS

%%

program:  new_stmt;


new_stmt:  new_stmt stmt 
        |
        ;


stmt: expr SEMICOLON {
    if($1->type==boolexpr_e){
        $1->sym=newtemp();
        if (apotimisi_and==1){
            patchlabel(tmpAnd2,nextquadlabel()+1);
            apotimisi_and=0;
        }
        backpatch($1->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,$1,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch($1->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,$1,nextquadlabel(),yylineno);
    }
}
    | ifstmt
    | whilestmt 
    | forstmt
    | returnstmt 
    | break 
    | continue
    | block              
    | funcdef                 
    | SEMICOLON  {resettemp();}
    ;


expr: expr PLUS expr {
        $$=newexpr(arithexpr_e);
        $$->sym=newtemp();
        $$=lvalue_expr($$->sym);
        emit(add,$1,$3,$$,nextquadlabel(),yylineno);
    }
    | expr MINUS expr {
        $$=newexpr(arithexpr_e);
        $$->sym=newtemp();
        $$=lvalue_expr($$->sym);
        emit(sub,$1,$3,$$,nextquadlabel(),yylineno);
    }
    | expr MUL expr {
        $$=newexpr(arithexpr_e);
        $$->sym=newtemp();
        $$=lvalue_expr($$->sym);
        emit(mul,$1,$3,$$,nextquadlabel(),yylineno);
    }
    | expr DIV expr {
        $$=newexpr(arithexpr_e);
        $$->sym=newtemp();
        $$=lvalue_expr($$->sym);
        emit(divv,$1,$3,$$,nextquadlabel(),yylineno);
    }
    | expr MOD expr {
        $$=newexpr(arithexpr_e);
        $$->sym=newtemp();
        $$=lvalue_expr($$->sym);
        emit(mod,$1,$3,$$,nextquadlabel(),yylineno);
    }
    | expr GREATER_THAN expr{
        $$ = newexpr(boolexpr_e);
        $$->truelist = makelist(nextquadlabel());
        $$->falselist = makelist(nextquadlabel()+1);
        emit(if_greater,$1,$3,NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+1,yylineno);
    }
    | expr GREATER_THAN_OR_EQUAL expr{
        $$ = newexpr(boolexpr_e);
        $$->truelist = makelist(nextquadlabel());
        $$->falselist = makelist(nextquadlabel()+1);
        emit(if_greatereq,$1,$3,NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    | expr LESS_THAN expr{
        $$ = newexpr(boolexpr_e);
        $$->truelist = makelist(nextquadlabel());
        $$->falselist = makelist(nextquadlabel()+1);
        emit(if_less,$1,$3,NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        tmpMikr=$$->falselist->quadNo;
        mikrotero=1;
    }
    | expr LESS_THAN_OR_EQUAL expr{
        $$ = newexpr(boolexpr_e);
        $$->truelist = makelist(nextquadlabel());
        $$->falselist = makelist(nextquadlabel()+1);
        emit(if_lesseq,$1,$3,NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    | expr EQUAL_TO {
        if($1->type==boolexpr_e && apotimisi_not==1){
            $1->sym=newtemp();
            backpatch($1->truelist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(1),NULL,$1,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
            backpatch($1->falselist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(0),NULL,$1,nextquadlabel(),yylineno);
        }
    }expr {
        if($4->type==boolexpr_e && apotimisi_not==1){
            $1->sym=newtemp();
            backpatch($4->truelist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(1),NULL,$4,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
            backpatch($4->falselist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(0),NULL,$4,nextquadlabel(),yylineno);
        }
        $$ = newexpr(boolexpr_e);
        $$->truelist = makelist(nextquadlabel());
        $$->falselist = makelist(nextquadlabel()+1);
        emit(if_eq,$1,$4,NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    | expr NOT_EQUAL_TO {
            if($1->type==boolexpr_e && apotimisi_not==1){
                $1->sym=newtemp();
                backpatch($1->truelist,nextquadlabel()+1);
                emit(assign,newexpr_constbool(1),NULL,$1,nextquadlabel(),yylineno);
                emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
                backpatch($1->falselist,nextquadlabel()+1);
                emit(assign,newexpr_constbool(0),NULL,$1,nextquadlabel(),yylineno);
            }
        }
        expr{
        if($4->type==boolexpr_e && apotimisi_not==1){
            $4->sym=newtemp();
            backpatch($4->truelist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(1),NULL,$4,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
            backpatch($4->falselist,nextquadlabel()+1);
            emit(assign,newexpr_constbool(0),NULL,$4,nextquadlabel(),yylineno);
        }
        $$ = newexpr(boolexpr_e);
        $$->truelist = makelist(nextquadlabel());
        $$->falselist = makelist(nextquadlabel()+1);
        emit(if_noteq,$1,$4,NULL,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    |expr AND {
        apotimisi_and=1;
        if($1->type!=boolexpr_e){
            $1->truelist = makelist(nextquadlabel());
            $1->falselist = makelist(nextquadlabel()+1);
            emit(if_eq,$1,newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
            //backpatch($1->falselist, nextquadlabel()+3);
            tmpAnd1=$1->falselist->quadNo; 
        }
    } M expr{
        $$=newexpr(boolexpr_e);                       /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!AND*/
        backpatch($1->truelist,$4+1); // true s1
        if($5->type!=boolexpr_e){
            $5->truelist = makelist(nextquadlabel());
            $5->falselist = makelist(nextquadlabel()+1);
            emit(if_eq,$5,newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        }
        $$->truelist=$5->truelist;
        $$->falselist=merge($1->falselist,$5->falselist);
        tmpAnd2=$5->truelist->quadNo;
    }
    |expr OR {
        apotimisi_or=1;
        if($1->type!=boolexpr_e){
            $1->truelist = makelist(nextquadlabel());
            $1->falselist = makelist(nextquadlabel()+1);
            emit(if_eq,$1,newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        }
    } M expr{
        $$=newexpr(boolexpr_e);                       /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!AND*/
        backpatch($1->falselist,$4+1); // true s1
        if($5->type!=boolexpr_e){
            $5->truelist = makelist(nextquadlabel());
            $5->falselist = makelist(nextquadlabel()+1);
            emit(if_eq,$5,newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        }
        $$->truelist=merge($1->truelist,$5->truelist);
        $$->falselist=$5->falselist;
        backpatch($1->truelist,nextquadlabel()+1);
    }
    | term {$$=$1;}
    | assignexpr {$$=$1;}
    ;

term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS { $$=$2; }
    | MINUS expr %prec UMINUS { 
        check_arith($2,"unary minus");
        $$=newexpr(arithexpr_e);
        $$->sym=newtemp();
        emit(uminus,$2,NULL,$$,nextquadlabel(),yylineno);
    }
    | NOT expr {                        /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!NOT*/
        apot_not=1;
        $$=newexpr(boolexpr_e);
        apotimisi_not=1;
        $$->sym=$2->sym;
        if($2->type==boolexpr_e){
            $$->truelist=$2->falselist;
            $$->falselist=$2->truelist;
        }
        else{
            $$->truelist=makelist(nextquadlabel()+1);
            $$->falselist=makelist(nextquadlabel());
            emit(if_eq,$2,newexpr_constbool(1),NULL,nextquadlabel(),yylineno);
            emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        } 
    }
    | PLUS_PLUS lvalue {
        check_arith($2,"++lvalue");
        if($2->type==tableitem_e){
            $$=emit_iftableitem($2);
            emit(add,$$,newexpr_constnum(1),$$,nextquadlabel(),yylineno);
        }
        else{
            emit(add,$2,newexpr_constnum(1),$2,nextquadlabel(),yylineno);
            $$=newexpr(arithexpr_e);
            $$->sym=newtemp();
            emit(assign,$2,NULL,$$,nextquadlabel(),yylineno);
        }
    }
    | lvalue PLUS_PLUS {
        check_arith($1,"lvalue++");
        $$=newexpr(var_e);
        $$->sym=newtemp();
        if($1->type==tableitem_e){
            struct expr* val=emit_iftableitem($1);
            emit(assign,val,NULL,$$,nextquadlabel(),yylineno);
            emit(add,val,newexpr_constnum(1),val,nextquadlabel(),yylineno);
            emit(tablesetelem, $1,$1->index,val,nextquadlabel(),yylineno);
        }
        else{
            emit(assign,$1,NULL,$$,nextquadlabel(),yylineno);
            emit(add,$1,newexpr_constnum(1),$1,nextquadlabel(),yylineno);
        }
    }
    | MINUS_MINUS lvalue {
        check_arith($2,"--lvalue");
        if($2->type==tableitem_e){
            $$=emit_iftableitem($2);
            emit(sub,$$,newexpr_constnum(1),$$,nextquadlabel(),yylineno);
        }
        else{
            emit(sub,$2,newexpr_constnum(1),$2,nextquadlabel(),yylineno);
            $$=newexpr(arithexpr_e);
            $$->sym=newtemp();
            emit(assign,$2,NULL,$$,nextquadlabel(),yylineno);
        }
    }
    | lvalue MINUS_MINUS {
        check_arith($1,"lvalue--");
        $$=newexpr(var_e);
        $$->sym=newtemp();
        if($1->type==tableitem_e){
            struct expr* val=emit_iftableitem($1);
            emit(assign,val,NULL,$$,nextquadlabel(),yylineno);
            emit(sub,val,newexpr_constnum(1),val,nextquadlabel(),yylineno);
            emit(tablesetelem, $1,$1->index,val,nextquadlabel(),yylineno);
        }
        else{
            emit(assign,$1,NULL,$$,nextquadlabel(),yylineno);
            emit(sub,$1,newexpr_constnum(1),$1,nextquadlabel(),yylineno);
        }
    }
    | primary { $$=$1; }
    ;


assignexpr: lvalue ASSIGNMENT expr {
    if($3->type==boolexpr_e){
        $3->sym=newtemp();
        backpatch($3->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,$3,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch($3->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,$3,nextquadlabel(),yylineno);
    }
    if($1->type==tableitem_e){
        emit(tablesetelem,$1->index,$3,$1,nextquadlabel(),yylineno);
        $$=emit_iftableitem($1);
        $$->type=assignexpr_e;
    }
    else{   
        emit(assign,$3,NULL,$1,nextquadlabel(),yylineno);
        $$=newexpr(assignexpr_e);
        $$->sym=newtemp();
        emit(assign,$1,NULL,$$,nextquadlabel(),yylineno);
    }
};


primary: lvalue {$$=emit_iftableitem($1);}
        | call
        | objectdef {$$=$1;}
        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {
            $$=newexpr(programfunc_e);
            $$->sym=$2;
        }
        | const {$$=$1;}
        ;


lvalue: 
ID{  
        Node sym;
        int i;
        sym=SymTable_Lookup(p,$1,GLOBAL,scope);
        if(sym==NULL){
            sym=SymTable_Insert(p,$1,1,GLOBAL,scope,yylineno); 
            sym->space=currscopespace();
            sym->offset=currscopeoffset();
            inccurrsopeoffset();
        }
        $$=lvalue_expr(sym);
        $$->sym->name=$1;
}
| LOC ID { 
            Node sym;
            if(SymTable_Lookup(p,$2,LIBFUNC,-1)!=NULL){
                printf("Error: Collision with %s library function. Cannot declare local %s.\n",$2,$2);
                break;
            }
            sym=SymTable_Lookup(p,$2,LOCAL,scope);
            if(sym==NULL){      
                sym=SymTable_Insert(p,$2,1,LOCAL,scope,yylineno);
                sym->space=currscopespace();
                sym->offset=currscopeoffset();
                inccurrsopeoffset();
            }
            $$=lvalue_expr(sym);
            $$->sym->name=$2;
}	
| DOUBLE_COLON ID {
            if(SymTable_Lookup(p,$2,GLOBAL,0)==NULL){ 
                printf("Error: No global variable %s exists.\n",$2);
            }
        } 
|member
;


member: lvalue DOT ID {
    $$=member_item($1,$3);
}
| lvalue LEFT_BRACKET expr RIGHT_BRACKET {
    if($3->type==boolexpr_e){
        $3->sym=newtemp();
        backpatch($3->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,$3,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch($3->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,$3,nextquadlabel(),yylineno);
    }
    $1=emit_iftableitem($1);
    $$=newexpr(tableitem_e);
    $$->sym=$1->sym;
    $$->index=$3;
}
| call DOT ID 
| call LEFT_BRACKET expr RIGHT_BRACKET {
    emit(tablegetelem,$1,$3,$1,nextquadlabel(),yylineno);
}
;


call: call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {$$=make_call($1,$3);}
| lvalue callsuffix {
    struct expr*temp=$2->elist;
    if(temp!=NULL){
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        $1=emit_iftableitem($1);
        if($2->method){
            temp->next=$1;
            $1=emit_iftableitem(member_item($1,$2->name));
        }
        $$=make_call($1,$2->elist);
    }
}
| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS  LEFT_PARENTHESIS elist RIGHT_PARENTHESIS{
        struct expr* temp=newexpr(programfunc_e);
        temp->sym=$2;
        $$=make_call(temp,$5);
    }
    ;


callsuffix: normcall
        | methodcall
        ;


normcall:  LEFT_PARENTHESIS elist RIGHT_PARENTHESIS{
    struct call* c=(struct call*)malloc(sizeof(struct call));
    memset(c,0,sizeof(struct call));
    $$=c;
    $$->elist=$2;
    $$->method=0;
    $$->name=NULL;
};



methodcall:  DOUBLE_DOT ID  LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
    struct call* c=(struct call*)malloc(sizeof(struct call));
    memset(c,0,sizeof(struct call));
    $$=c;
    $$->elist=$4;
    $$->method=1;
    $$->name=strdup($2);
};


elist: expr {
    if($1->type==boolexpr_e){
        $1->sym=newtemp();
        backpatch($1->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,$1,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch($1->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,$1,nextquadlabel(),yylineno);
    }
}
| elist COMMA expr {
    if($3->type==boolexpr_e){
        $3->sym=newtemp();
        backpatch($3->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,$3,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch($3->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,$3,nextquadlabel(),yylineno);
    }
    struct expr*tmp=$1;
    while(tmp->next != NULL){
        tmp=tmp->next;
    }
    tmp->next=$3;
}
| {$$=newexpr_constnil();}
;


objectdef: LEFT_BRACKET elist RIGHT_BRACKET {
    int i=0;
    struct expr*t= newexpr(newtable_e);
    t->sym=newtemp();
    emit(tablecreate,t,NULL,NULL,nextquadlabel(),yylineno);
    struct expr*tmp=$2;
    if(tmp->type!=nil_e){
        while(tmp!=NULL){
            emit(tablesetelem,newexpr_constnum(i++),tmp,t,nextquadlabel(),yylineno);
            tmp=tmp->next;
        }
    }
    $$=t;
}
| LEFT_BRACKET indexed RIGHT_BRACKET {
    int i=0;
    struct expr*t= newexpr(newtable_e);
    t->sym=newtemp();
    emit(tablecreate,t,NULL,NULL,nextquadlabel(),yylineno);
    struct expr*tmp=$2;
    if(tmp->type!=nil_e){
        while(tmp!=NULL){
            emit(tablesetelem,tmp->index,tmp->value,t,nextquadlabel(),yylineno);
            tmp=tmp->next;
        }
    }
    $$=t;
}
;


indexed: indexedelem 
| indexed COMMA indexedelem {
            struct expr*tmp=$1;
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next=$3;
            $$=$1;
}; 

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE{
    if($2->type==boolexpr_e){
        $2->sym=newtemp();
        backpatch($2->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,$2,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch($2->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,$2,nextquadlabel(),yylineno);
    }
    $$=newexpr(tableitem_e);
    $$->index=$2;
    $$->value=$4;
};


funcdef: funcprefix funcargs funcbody {
    exitscopespace();
    $1->value.funcVal->args=$3;
    int quadNo=pop(&topLabel);
    patchlabel(quadNo,nextquadlabel()+2);
    int offset=pop_and_top();
    restorecurrscopeoffset(offset);
    $$=$1;
    emit(funcend,NULL,NULL,lvalue_expr($1),nextquadlabel(),yylineno);
};


funcname : ID { $$=$1; }
| { $$ = newtempfuncname(); };      


funcprefix : FUNCTION funcname {
    if(SymTable_Lookup(p,$2,LIBFUNC,-1)!=NULL) {
        printf("Error: User function %s, collision with %s library function.\n",$2,$2);
    }
    else if(SymTable_Lookup(p,$2,USERFUNC,scope)!=NULL) {
        printf("Error: %s already defined.\n", $2);
    }
    else {
        $$=SymTable_Insert(p,$2,1,USERFUNC,scope,yylineno);
        $$->value.funcVal->iaddress=nextquadlabel();
        pushLabel(&topLabel,nextquadlabel());
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        emit(funcstart,NULL,NULL,lvalue_expr($$),nextquadlabel(),yylineno);
        pushOffset(currscopeoffset());
        enterscopespace();
        resetformalargoffset();
    }
    int tmp_scope=scope;
    scope++;
    if(scope>max_scope) max_scope=scope;
};


funcargs : LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS {
    if(flag!=1) {
        if(SymTable_Lookup(p,$2,FORMAL,scope)==0){
            SymTable_Insert(p,$2,1,FORMAL,tmp_scope,yylineno);
            tmp_scope++;
        }
    }
    enterscopespace();
    resetfunctionoffset();
};


funcbody : block {
    SymTable_Hide(p,scope); 
    scope--; 
    tmp_scope--;
    $$=currscopeoffset();
    exitscopespace();
};


block: LEFT_BRACE new_stmt RIGHT_BRACE ;


const: NUMBER { $$=newexpr_constnum($1); }
|STRING { $$=newexpr_conststring($1); }
|NIL { $$=newexpr_constnil(); }
|TRUE { $$=newexpr_constbool(1); }
|FALSE { $$=newexpr_constbool(0); };


idlist: 
ID{   
        flag=0;
        if(SymTable_Lookup(p,$1,LIBFUNC,-1)!=NULL){
            printf("Error: Collision with %s library function. Cannot be used as formal.\n",$1);
            break;
        }
        if(SymTable_Lookup(p,$1,FORMAL,scope)==NULL){
            SymTable_Insert(p,$1,1,FORMAL,scope,yylineno);
        }
} 
| idlist COMMA ID {  
        flag=0;
        if(SymTable_Lookup(p,$3,LIBFUNC,-1)!=NULL){
            printf("Error: Collision with %s library function. Cannot be used as formal.\n",$3);
            break;
        }
        if(SymTable_Lookup(p,$3,FORMAL,scope)==NULL){
            SymTable_Insert(p,$3,1,FORMAL,scope,yylineno);
        }    
        else printf("Error: Variable %s already defined at line %d.\n",$3,yylineno);
}
| {flag=1;}
;

ifprefix: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS{
    struct expr* tmp1=newexpr_constbool(1);
    struct expr* tmp2=newexpr(var_e);
    struct expr* tmp3=newexpr_constbool(0);
    $$=nextquadlabel();
    if($3->type==boolexpr_e){
        pushIf(nextquadlabel()-2,&topIf1);
        tmp2->sym=newtemp();
        emit(assign,tmp1,NULL,tmp2,nextquadlabel(),yylineno);
        int pop=popIf(&topIf1);
        patchlabel(pop,nextquadlabel());
        patchlabel(pop+1,nextquadlabel()+2);
        emit(jump,NULL,NULL,0,nextquadlabel()+3,yylineno);
        emit(assign,tmp3,NULL,tmp2,nextquadlabel(),yylineno);
        emit(if_eq, tmp2, tmp1,NULL,nextquadlabel()+3,yylineno);  
        pushIf(nextquadlabel(),&topIf2);
        emit(jump,NULL,NULL,0,nextquadlabel(),yylineno);
    }
    else{
        emit(if_eq,$3,tmp1,NULL,nextquadlabel()+3,yylineno);  
        pushIf(nextquadlabel(),&topIf2);
        emit(jump,NULL,NULL,0,nextquadlabel(),yylineno);
    }
}


elseprefix: ELSE{ 
    $$=nextquadlabel();
    emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno); // an den isxuei to if paei sto else
    pushIf(nextquadlabel(),&topIf3);
}

ifstmt: ifprefix stmt{ 
    int pop=popIf(&topIf2);
    patchlabel(pop,nextquadlabel()+1);
}
| ifprefix stmt elseprefix stmt{ 
    int pop=popIf(&topIf2);
    int pop1=popIf(&topIf3);
    patchlabel($3,nextquadlabel()+1);
    patchlabel(pop,pop1+1);
}
;


whilestart: WHILE{
    $$=nextquadlabel();
    pushLoop(nextquadlabel()+1,&topWhile1);
}

whilecond: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {
    $$=nextquadlabel();
    struct expr* tmp1=newexpr_constbool(1);
    struct expr* tmp2=newexpr(var_e);
    struct expr* tmp3=newexpr_constbool(0);

    if($2->type==boolexpr_e){
        pushLoop(nextquadlabel()-2,&topWhile);
        tmp2->sym=newtemp();
        emit(assign,tmp1,NULL,tmp2,nextquadlabel(),yylineno);
        int pop=popLoop(&topWhile);
        patchlabel(pop,nextquadlabel());
        patchlabel(pop+1,nextquadlabel()+2);
        emit(jump,NULL,NULL,0,nextquadlabel()+3,yylineno);
        emit(assign,tmp3,NULL,tmp2,nextquadlabel(),yylineno);
        if(apotimisi_and==1 && apot_not==0){
            patchlabel(tmpAnd1,nextquadlabel());
            apotimisi_and=0;
        }
        pushLoop(nextquadlabel(),&topWhile2);
        emit(if_eq,tmp2,tmp1,NULL,nextquadlabel()+3,yylineno);
        pushLoop(nextquadlabel(),&topWhile3);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
    }
    else {
        emit(if_eq,$2,tmp1,NULL,nextquadlabel(),yylineno);
        pushLoop(nextquadlabel(),&topWhile3);
        emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
        pushLoop(nextquadlabel()+1,&topWhile2);
    }
}

whilestmt: whilestart whilecond stmt{
    int pop1,pop2,pop3;
    pop1=popLoop(&topWhile1);
    pop2=popLoop(&topWhile2);
    pop3=popLoop(&topWhile3);
    if(apotimisi_or==1 && apot_not==0)patchlabel(pop1,3);
    else patchlabel(pop1,pop2);
    int c=popC();
    if (c!=-1){
        patchlabel(c,pop1);
    }
    emit(jump,NULL,NULL,newexpr_constnum($1),pop1,yylineno);
    patchlabel($2,pop2);
    patchlabel(pop3,nextquadlabel()+1);
    int b=popB();
    if(b!=-1) {
        patchlabel(b,nextquadlabel()+1);
    }
};

N: { 
    $$=nextquadlabel();
    emit(jump,NULL,NULL,NULL,0,yylineno); 
    };


M: { $$=nextquadlabel(); };

forprefix: FOR LEFT_PARENTHESIS elist SEMICOLON M expr SEMICOLON {
    struct stmt_t* c=(struct stmt_t*)malloc(sizeof(struct stmt_t));
    struct expr* tmp1=newexpr_constbool(1);
    struct expr* tmp2=newexpr(var_e);
    struct expr* tmp3=newexpr_constbool(0);
    if($6->type==boolexpr_e){
        pushLoop(nextquadlabel()-2,&topFor);
        tmp2->sym=newtemp();
        emit(assign,tmp1,NULL,tmp2,nextquadlabel(),yylineno);
        int pop=popLoop(&topFor);
        patchlabel(pop,nextquadlabel());
        patchlabel(pop+1,nextquadlabel()+2);
        emit(jump,NULL,NULL,0,nextquadlabel()+3,yylineno);
        emit(assign,tmp3,NULL,tmp2,nextquadlabel(),yylineno);
        if(mikrotero==1 ){
            patchlabel(tmpMikr,nextquadlabel());
            apotimisi_and=0;
        }
        pushLoop(nextquadlabel(),&topFor2);
        emit(if_eq,tmp2,tmp1,NULL,nextquadlabel()+3,yylineno);
    }
    else{
        pushLoop(nextquadlabel(),&topFor2);
        emit(if_eq,$6,tmp1,NULL,nextquadlabel(),yylineno);
    }
    struct forloop* f= (struct forloop*) malloc(sizeof(struct forloop)); 
    $$=f;
    $$->test=$5;
    $$->enter=nextquadlabel();
};

forstmt: forprefix N elist RIGHT_PARENTHESIS N stmt N{
   patchlabel($1->enter,$5+1);
   patchlabel($2,nextquadlabel()+1);
   patchlabel($5,$1->test+1);
   patchlabel($7,$2+2);
   int c=popC();
    if (c!=-1){
        patchlabel(c,$2+2);
    }
   patchlabel(popLoop(&topFor2),$5+2);
   int b=popB();
   if(b!=-1) patchlabel(b,nextquadlabel()+1);
}

break: BREAK SEMICOLON {
    struct stmt_t* b=(struct stmt_t*)malloc(sizeof(struct stmt_t));
    b->quadNo=nextquadlabel();
    pushB(b,NULL);
    emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
}

continue: CONTINUE SEMICOLON{
    struct stmt_t* c=(struct stmt_t*)malloc(sizeof(struct stmt_t));
    c->quadNo=nextquadlabel();
    pushC(c,NULL);
    emit(jump,NULL,NULL,NULL,nextquadlabel(),yylineno);
}

returnstmt: RETURN SEMICOLON {
    if(isInFunc==0)printf("Return outside function.\n");
    else{
        isInFunc=0;
        struct expr* tmp=newexpr_constnil();
        emit(ret,NULL,NULL,tmp,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+2,yylineno);
    }
}
| RETURN expr SEMICOLON {
    if(isInFunc==0)printf("Return outside function.\n");
    else{
    isInFunc=0;
    if($2->type==boolexpr_e){
        $2->sym=newtemp();
        backpatch($2->truelist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(1),NULL,$2,nextquadlabel(),yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+3,yylineno);
        backpatch($2->falselist,nextquadlabel()+1);
        emit(assign,newexpr_constbool(0),NULL,$2,nextquadlabel(),yylineno);
    }
    emit(ret,NULL,NULL,$2,nextquadlabel(),yylineno);
    $$=$2;
    emit(jump,NULL,NULL,NULL,nextquadlabel()+2,yylineno);
    }
}
;      




%%
void Quad_Print(){
    FILE *fptr = fopen("quads.txt", "a");
    if(fptr == NULL){
		printf("Error could not open file\n");
    }
    fprintf(fptr,"\n%-6s %-15s %-10s %-10s %-10s %-10s\n", "quad#", "opcode", "result", "arg1", "arg2","label");
    for(int i=0;i<currQuad;i++){
        if (quads[i].op == 0) {
            if (quads[i].arg1->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d\n", i+1, "assign", quads[i].result->sym->name, (int)quads[i].arg1->numConst);
            }
            else if(quads[i].arg1->type==boolexpr_e){
                if(quads[i].arg1->boolConst=='1'){ 
                    fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign",quads[i].result->sym->name , "'true'");
                }
                else if(quads[i].arg1->boolConst=='0'){
                    fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign",quads[i].result->sym->name , "'false'");
                }  
                else  fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign",quads[i].result->sym->name , quads[i].arg1->sym->name);     
            }
            else if(quads[i].arg1->type==nil_e){  
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, "nil");
            }
            else if(quads[i].arg1->type==conststring_e) { 
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, quads[i].arg1->strConst);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg1->boolConst==1) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, "'true'");
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg1->boolConst==0) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, "'false'");
            }
            else if (quads[i].arg1->type==var_e) { 
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, quads[i].arg1->sym->name);
            }
            else if (quads[i].arg1->type==newtable_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, quads[i].arg1->sym->name);
            }
            else if (quads[i].arg1->type==assignexpr_e) { 
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "assign", quads[i].result->sym->name, quads[i].arg1->sym->name);
            }
            
        } 
        else if (quads[i].op == 1) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "add", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "add", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "add", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==2) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "sub", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "sub", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "sub", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==3) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "mul", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "mul", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mul", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==4) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "div", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "div", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "div", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==5) {
            if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "mod", quads[i].result->sym->name, (int)quads[i].arg1->numConst, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, (int)quads[i].arg2->numConst);
            }
            else if (quads[i].arg1->type == constnum_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "mod", quads[i].result->sym->name, (int)quads[i].arg1->numConst, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == var_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
            else if (quads[i].arg1->type == arithexpr_e && quads[i].arg2->type == arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "mod", quads[i].result->sym->name, quads[i].arg1->sym->name, quads[i].arg2->sym->name);
            }
        }
        else if(quads[i].op==6) {
            if(quads[i].arg1->type==constbool_e)return;
            else if(quads[i].arg1->type==conststring_e)return;
            else if(quads[i].arg1->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d\n", i+1, "uminus", quads[i].result->sym->name,(int)quads[i].arg1->numConst);
            }
            else if(quads[i].arg1->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s\n", i+1, "uminus", quads[i].result->sym->name,quads[i].arg1->sym->name);
            }
        }
        else if (quads[i].op == 10) { // ==
           if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e){
            if(quads[i].arg2->boolConst==1)fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,"'true'",(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,quads[i].arg2->strConst,(int)quads[i].label);
            }
             else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_eq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is bool*/
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constbool_e){
                char*arg1,*arg2;
                if(quads[i].arg1->boolConst==1){
                    arg1="'true'";
                } 
                else arg1="'false'";
                if(quads[i].arg2->boolConst==1){
                    arg2="'true'";
                } 
                else arg2="'false'";
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",arg1,arg2,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constnum_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq","'true'",(int)quads[i].arg2->numConst,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq","'false'",(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==arithexpr_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==conststring_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->strConst,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==boolexpr_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==programfunc_e) {
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is variable*/
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_eq", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_eq", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is assign*/
            else if(quads[i].arg1->type==assignexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==assignexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is string*/
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->strConst,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->value.funcVal->name,"'true'",(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq",quads[i].arg1->sym->value.funcVal->name,"'false'",(int)quads[i].label);
            }
        }
        else if (quads[i].op == 11) { // !=
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,quads[i].arg2->strConst,(int)quads[i].label);
            }
             else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_noteq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is bool*/
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constbool_e){
                char*arg1,*arg2;
                if(quads[i].arg1->boolConst==1){
                    arg1="'true'";
                } 
                else arg1="'false'";
                if(quads[i].arg2->boolConst==1){
                    arg2="'true'";
                } 
                else arg2="'false'";
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",arg1,arg2,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constnum_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq","'true'",(int)quads[i].arg2->numConst,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq","'false'",(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==arithexpr_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==conststring_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'true'",quads[i].arg2->strConst,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'false'",quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==programfunc_e) {
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'true'",quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq","'false'",quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            /*arg1 is variable*/
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_noteq", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_noteq", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==1){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,"'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e && quads[i].arg2->boolConst==0){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==boolexpr_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'true'",quads[i].arg2->sym->name,(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_eq","'false'",quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is string*/
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) printf("%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,"'true'",(int)quads[i].label);
                else fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,"'false'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,quads[i].arg2->strConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_noteq",quads[i].arg1->strConst,quads[i].arg2->sym->value.funcVal->name,(int)quads[i].label);
            }
        }
        else if (quads[i].op == 12) { // <=
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_lesseq",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_lesseq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_lesseq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_lesseq", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_lesseq", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_lesseq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
        }
        else if (quads[i].op == 13) { // >=
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_greatereq",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_greatereq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_greatereq",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_greatereq", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_greatereq", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greatereq",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }

        }
        else if (quads[i].op == 14) { // <
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_less",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_less",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_less",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_less", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_less", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_less",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
        }
        else if (quads[i].op == 15) { // >
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10d %-10d\n", i+1, "if_greater",(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_greater",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-27s %-10d %-10s %-10d\n", i+1, "if_greater",(int)quads[i].arg1->numConst,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_greater", quads[i].arg1->sym->name, "'true'",(int)quads[i].label);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==assignexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-15d\n", i+1, "if_greater", quads[i].arg1->sym->name, quads[i].arg2->sym->name,(int)quads[i].label);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10d %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,(int)quads[i].arg2->numConst,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-27s %-10s %-10s %-10d\n", i+1, "if_greater",quads[i].arg1->sym->name,quads[i].arg2->sym->name,(int)quads[i].label);
            }
        }
        else if (quads[i].op == 16) {
            if(quads[i].arg1->type!=programfunc_e){
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "call",quads[i].arg1->sym->name); 
            }
            else fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "call",quads[i].arg1->sym->value.funcVal->name); 
        }
        else if (quads[i].op == 17) {
            if(quads[i].arg1->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10d\n", i+1, "param",(int)quads[i].arg1->numConst); 
            }
            else if(quads[i].arg1->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "param",quads[i].arg1->sym->name); 
            }
            else if(quads[i].arg1->type==conststring_e) {
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "param",quads[i].arg1->strConst); 
            }
            else if(quads[i].arg1->type==constbool_e) {
                fprintf(fptr,"%-6d %-15s %-6d\n", i+1, "param",quads[i].arg1->boolConst);
            }
            else if(quads[i].arg1->type==boolexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "param",quads[i].arg1->sym->name);
            }
        }
        else if (quads[i].op == 19) { 
            fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "getretval",quads[i].result->sym->name);
        }
        else if (quads[i].op == 18) { 
            if(quads[i].result->type==constbool_e){
                if(quads[i].result->boolConst==1) fprintf(fptr,"%-6d %-15s %s\n", i+1, "return","'true'");
                else fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "return","'false'");
            }
            else if(quads[i].result->type==constnum_e){
                fprintf(fptr,"%-6d %-15s %-10d\n", i+1, "return",(int)quads[i].result->numConst);
            }
            else if(quads[i].result->type==arithexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "return",quads[i].result->sym->name);
            }
            else if(quads[i].result->type==conststring_e){
                fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "return",quads[i].result->strConst);
            }
            else if(quads[i].result->type==var_e){
                fprintf(fptr,"%-6d %-15s %-10s \n", i+1, "return",quads[i].result->sym->name);
            }
            else if(quads[i].result->type==nil_e){
                fprintf(fptr,"%-6d %-15s\n", i+1, "return");
            }
        }
        else if(quads[i].op==20) {
            fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "funcstart", quads[i].result->sym->value.funcVal->name);
        }
        else if(quads[i].op==21) {
            fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "funcend", quads[i].result->sym->value.funcVal->name);
        }
        else if (quads[i].op == 22) {
            fprintf(fptr,"%-6d %-15s %-10s\n", i+1, "tablecreate",quads[i].arg1->sym->name);
        }
        else if (quads[i].op == 23) {
                if(quads[i].arg2->type==constbool_e) {
                    if(quads[i].arg2->boolConst==1)fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'true'");
                    else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'false'");
                }
                else if(quads[i].arg2->type==constnum_e){
                    fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,(int)quads[i].arg2->numConst);
                }
                else if(quads[i].arg2->type==arithexpr_e){
                    fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
                }
                else if(quads[i].arg2->type==conststring_e) {
                    fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->strConst);
                }
                else if(quads[i].arg2->type==var_e) {
                    fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablegetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
                }
        }
        else if (quads[i].op == 24) {
            if(quads[i].arg1->type==tableitem_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==newtable_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            /*arg1 is function*/
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1)fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,"'false'");
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==boolexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==programfunc_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->value.funcVal->name,quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is number*/
            if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,"'false'");
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==arithexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==assignexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==boolexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==conststring_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->strConst);
            }
             else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10d %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,(int)quads[i].arg1->numConst,quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is bool*/
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constbool_e){
                char*arg1,*arg2;
                if(quads[i].arg1->boolConst==1){
                    arg1="'true'";
                } 
                else arg1="'false'";
                if(quads[i].arg2->boolConst==1){
                    arg2="'true'";
                } 
                else arg2="'false'";
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,arg1,arg2);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constnum_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",(int)quads[i].arg2->numConst);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==arithexpr_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->sym->name);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==boolexpr_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->sym->name);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==conststring_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->strConst);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==var_e){
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->sym->name);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==programfunc_e) {
                if(quads[i].arg1->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'true'",quads[i].arg2->sym->value.funcVal->name);
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,"'false'",quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is variable*/
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'false'");
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==var_e && quads[i].arg2->type==programfunc_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is arithmetical expression*/
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,"'false'");
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==constnum_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==var_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==arithexpr_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->sym->name,quads[i].arg2->sym->value.funcVal->name);
            }
            /*arg1 is string*/
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constbool_e){
                if(quads[i].arg2->boolConst==1) fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,"'true'");
                else fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,"'false'");
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==boolexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==constnum_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10d\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,(int)quads[i].arg2->numConst);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==arithexpr_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==conststring_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->strConst);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==var_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==assignexpr_e) {
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==programfunc_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->value.funcVal->name);
            }
            else if(quads[i].arg1->type==conststring_e && quads[i].arg2->type==newtable_e){
                fprintf(fptr,"%-6d %-15s %-10s %-10s %-10s\n", i+1, "tablesetelem",quads[i].result->sym->name,quads[i].arg1->strConst,quads[i].arg2->sym->name);
            }
        }
        else if (quads[i].op == 25) {
            if(quads[i].label==0) fprintf(fptr,"%-6d %-49s \n", i+1, "jump"); 
            else fprintf(fptr,"%-6d %-49s %-d\n", i+1, "jump",(int)quads[i].label);
        }
    }
    fclose(fptr);
}  

void pushAND(int quadNo) {
    struct stmt_t *newStmt = (struct stmt_t *)malloc(sizeof(struct stmt_t));
    if (newStmt == NULL) {
        return;
    }
    newStmt->quadNo = quadNo;
    newStmt->next = NULL;
    if (topHeadAnd1 == NULL) {
        topHeadAnd1 = newStmt;
        butomHeadAnd1 = newStmt;
    } else {
        newStmt->next = topHeadAnd1;
        topHeadAnd1 = newStmt;
    }
}

int popAND() {
    if (topHeadAnd1 == NULL) {
        return -1;
    }
    int quadNo = topHeadAnd1->quadNo;
    struct stmt_t *temp = topHeadAnd1;
    if (topHeadAnd1 == butomHeadAnd1) {
        topHeadAnd1 = NULL;
        butomHeadAnd1 = NULL;
    } else {
        topHeadAnd1 = topHeadAnd1->next;
    }
    free(temp);
    return quadNo;
}

struct stmt_t* makelist(int quadno){
	struct stmt_t*list = (struct stmt_t*)malloc(sizeof(struct stmt_t));
	if(list==NULL)return NULL;
	list->quadNo=quadno;
	list->next=NULL;
	return list;
}

void backpatch(struct stmt_t *list, int quadno){
    struct stmt_t *tmp=list;
	while (tmp!=NULL){
    	patchlabel(tmp->quadNo, quadno);
		tmp=tmp->next;
	}
}

struct stmt_t* merge(struct stmt_t* l1,struct stmt_t* l2){
    struct stmt_t *temp = NULL;
	if (l1==NULL){
		return l2;
	}
	else 
    if (l2==NULL){
		return l1;
    }
	else {
        temp=l1;
	    while (temp->next!=NULL){
		    temp=temp->next;
	    }
	    temp->next=l2;
    }
	return l1;
}

void pushC(struct stmt_t* breakList, struct stmt_t* continueList) { // continue; 
    struct Lc_stack_t* newNode = (struct Lc_stack_t*)malloc(sizeof(struct Lc_stack_t));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->breakList = breakList;
    newNode->continueList = continueList;
    newNode->next = NULL;
    newNode->counter = 0;

    if (lcs_topC == NULL) {
        lcs_topC = newNode;
        lsc_bottomC = newNode;
    } else {
        newNode->next = lcs_topC;
        lcs_topC = newNode;
    }
}

int popC() {
    if (lcs_topC == NULL) {
        return -1;
    }
    struct Lc_stack_t* temp = lcs_topC;
    int quadNo = temp->breakList->quadNo; // Αποθήκευση του quadNo
    lcs_topC = lcs_topC->next;
    free(temp);

    if (lcs_topC == NULL) {
        lsc_bottomC = NULL;
    }

    return quadNo;
}

void pushB(struct stmt_t* breakList, struct stmt_t* continueList) { // break;
    struct Lc_stack_t* newNode = (struct Lc_stack_t*)malloc(sizeof(struct Lc_stack_t));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->breakList = breakList;
    newNode->continueList = continueList;
    newNode->next = NULL;
    newNode->counter = 0;
    if (lcs_topB == NULL) {
        lcs_topB = newNode;
        lsc_bottomB = newNode;
    } else {
        newNode->next = lcs_topB;
        lcs_topB = newNode;
    }
}

int popB() {
    if (lcs_topB == NULL) {
        return -1;
    }
    struct Lc_stack_t* temp = lcs_topB;
    lcs_topB = lcs_topB->next;
    if (lcs_topB == NULL) {
        lsc_bottomB = NULL;
    }
    return temp->breakList->quadNo;
}

void pushIf(int label,struct IfStack** top){
    struct IfStack* newnode=(struct IfStack*)malloc(sizeof(struct IfStack));
    if (newnode==NULL) return;
    newnode->label=label;
    newnode->next=*top;
    *top=newnode;
}

int popIf(struct IfStack** top){
    struct IfStack* temp;
    if (*top==NULL) return -1; 
    int pop=(*top)->label;
    temp=*top;
    *top=(*top)->next;
    free(temp);
    return pop;
}

void pushLabel(struct LabelStack**top,int label) {
    struct LabelStack* newnode=(struct LabelStack*)malloc(sizeof(struct LabelStack));
    if (newnode==NULL) return;
    newnode->label=label;
    newnode->next=*top;
    *top=newnode;
}

int pop(struct LabelStack**top) {
    if (*top==NULL) return -1; 
    int pop=(*top)->label;
    struct LabelStack* temp=*top;
    (*top)=(*top)->next;
    return pop;
}

void pushLoop(int label,struct LabelStack** top) {
    struct LabelStack* newnode=(struct LabelStack*)malloc(sizeof(struct LabelStack));
    if (newnode==NULL) return;
    newnode->label=label;
    newnode->next=*top;
    *top=newnode;
}

int popLoop(struct LabelStack** top) {
    struct LabelStack* temp;
    if (top==NULL) return -1; 
    int pop=(*top)->label;
    temp=*top;
    *top=(*top)->next;
    free(temp);
    return pop;
}


void pushOffset(int offset) {
    struct OffsetStack* newnode=(struct OffsetStack*)malloc(sizeof(struct OffsetStack));
    if (newnode==NULL) return;
    newnode->offset=offset;
    newnode->next=topOffset;
    topOffset=newnode;
}

int pop_and_top() {
    if (topOffset==NULL) return -1; 
    int pop=topOffset->offset;
    struct OffsetStack* temp=topOffset;
    topOffset=topOffset->next;  
    if(topOffset!=NULL)return topOffset->offset;
    else return -1;
}

struct expr* newexpr(enum expr_t t){
    struct expr* e=(struct expr*)malloc(sizeof(struct expr));
    memset(e,0,sizeof(struct expr));
    e->type=t;
    return e;
}

void resettemp(){
    tempcounter=0;
}

char* newtempfuncname() {
    int length_counter;
    char* new_n;
    length_counter = snprintf(NULL, 0, "%d", tempfuncounter);
    new_n = (char*)malloc((length_counter + 4) * sizeof(char)); 
    sprintf(new_n, "_f%d", tempfuncounter);
    tempfuncounter++;
    return new_n;
}

char* newtempname() {
    int length_counter;
    char* new_n;
    length_counter = snprintf(NULL, 0, "%d", tempcounter);
    new_n = (char*)malloc((length_counter + 4) * sizeof(char)); 
    sprintf(new_n, "_t%d", tempcounter);
    tempcounter++;
    return new_n;
}

Node newtemp() {
    Node n = (Node)malloc(sizeof(struct SymbolTableEntry));
    int x;
    int length_counter;
    char* new_n;
    n->name = newtempname();
    n->type = GLOBAL;
    n->offset = 0;
    n->space = programvar;
    n->scope = 0; 
    n->line = yylineno;
    SymTable_Insert(p, n->name, 1, GLOBAL, scope, yylineno);
    return n;
}

void expand(void){
    assert(total==currQuad);       
    struct quad*p=(struct quad*)malloc(NEW_SIZE);
    if(quads){
        memcpy(p,quads,CURR_SIZE);
        free(quads);
    }
    quads=p;
    total=total+EXPAND_SIZE;
}

void emit (enum iopcode op,struct expr* arg1,struct expr* arg2, struct expr* result, unsigned label, unsigned line){
    if (currQuad==total){
        expand();
    }
    struct quad*p=quads+(currQuad++);
    p->op=op;
    p->arg1=arg1;
    p->arg2=arg2;
    p->result=result;
    p->label=label;
    p->line=line;
}

unsigned nextquadlabel(){
    return currQuad;
}

void yyerror(char* yaccProvidedMessage){
    fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
}

struct expr* newexpr_conststring(char *s){
    struct expr* e=newexpr(conststring_e);
    e->strConst=strdup(s);
    return e;
}

struct expr* newexpr_constnum (double i){
    struct expr* e=newexpr(constnum_e);
    e->numConst=i;
    return e;
}

struct expr* newexpr_constbool (unsigned int b) {
   struct expr* e = newexpr(constbool_e);
   e->boolConst = !!b;
   return e;
}

struct expr* newexpr_constnil(){
	struct expr* e=newexpr(nil_e);
    e->numConst=0;
    return e;
}

struct expr* emit_iftableitem(struct expr* e){      //e=t
    if(e->type!=tableitem_e) {
        return e;
    }
    else {
        struct expr* result=newexpr(var_e);
        result->sym=newtemp();      //_t0
        emit(tablegetelem,e,e->index,result,nextquadlabel(),yylineno);   
        return result;      //epistrefei to _t0
    }
}

void patchlabel(unsigned quadNo, unsigned label){
    assert(quadNo<currQuad);
    quads[quadNo].label=label;
}

void patchlist(int list,int label){
    while(list){
        int next=quads[list].label;
        quads[list].label=label;
        list=next;
    }
}

struct expr* member_item (struct expr* lv, char* name){     //lv=t name="a"
    lv=emit_iftableitem(lv);  //tablegetelem t "a" _t0      lv=_t0
    struct expr* ti=newexpr(tableitem_e);   
    ti->sym=lv->sym;    //_t0
    ti->index=newexpr_conststring(name);    //"a"
    return ti;      //pinakas
}

struct expr* lvalue_expr(Node sym){
    assert(sym);
    struct expr* e=(struct expr*)malloc(sizeof(struct expr));
    memset(e,0,sizeof(struct expr));
    e->next=(struct expr*)0;
    e->sym=sym;
    switch(sym->type){
        case LOCAL: e->type=var_e; break;
        case FORMAL: e->type= var_e; break;
        case GLOBAL: e->type=var_e; break;
        case LIBFUNC: e->type= libraryfunc_e; break;
        case USERFUNC: e->type=programfunc_e; break;
    }
    return e;
}


void check_arith (struct expr* e, const char* context) {
if (e->type == constbool_e ||
    e->type == conststring_e ||
    e->type == nil_e ||
    e->type == newtable_e ||
    e->type == programfunc_e ||
    e->type == libraryfunc_e ||
    e->type == boolexpr_e )
    printf("Illegal expr used in %s!", context);
}
void enterscopespace(void){
    ++scopeSpaceCounter;
}

void exitscopespace(void){
    assert(scopeSpaceCounter>1);
    --scopeSpaceCounter;
}

void resetformalargoffset(void){
    formalArgOffset=0;
}

void resetfunctionoffset(void){
    functionLocalOffset=0;
}

unsigned currscopeoffset(void){
    switch(currscopespace()){
        case programvar: return programVarOffset;
        case functionlocal: return functionLocalOffset;
        case formalarg: return formalArgOffset;
        default: assert(0);
    }
}

enum scopespace_t currscopespace(void){
  if(scopeSpaceCounter==1){
    return programvar;
  }
  else {
    if(scopeSpaceCounter%2==0){
      return formalarg;
    }
    else {
      return functionlocal;
    }
  }
}

void restorecurrscopeoffset(unsigned n){
    switch (currscopespace()){
        case programvar: programVarOffset=n; break;
        case functionlocal: functionLocalOffset=n; break;
        case formalarg: formalArgOffset=n; break;
        default: assert(0);
    }
}

struct expr* make_call(struct expr* lv, struct expr* reversed_elist){
    struct expr* prev,*next,*list,*current,*func,*result;
    current=reversed_elist;
    prev=NULL;
    next=NULL;
    while (current!=NULL) {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    list=prev;
    func=emit_iftableitem(lv);
    if(reversed_elist->type!=nil_e){
        while(list){
            emit(param,list,NULL,NULL,0,0);
            list=list->next;
        }  
    }    
    emit(call,func,NULL,NULL,0,0);  
    result=newexpr(var_e);
    result->sym=newtemp();
    emit(getretval,NULL,NULL,result,0,0);
    return result;
}

void inccurrsopeoffset(void){
    switch (currscopespace()) {
        case programvar: ++programVarOffset; break;
        case functionlocal: ++functionLocalOffset; break;
        case formalarg: ++formalArgOffset; break;
        default: assert(0);
    }
}

int main(int argc, char* argv[]){
    p=SymTable_new();
    SymTable_Insert(p,"print",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"input",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"objectmemberkey",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"objecttotalmember",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"objectcopy",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"totalarguments",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"argument",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"typeof",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"strtonum",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"sqrt",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"cos",0,LIBFUNC,-1,0);
    SymTable_Insert(p,"sin",0,LIBFUNC,-1,0);
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))){
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
    } 
    else {
        yyin = stdin;
    }
    yyparse();
    SymTable_Print(p,max_scope);
    Quad_Print();
    return 0;
}
