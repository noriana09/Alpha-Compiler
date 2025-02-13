#include "symtable.h"
#define HASH_MULTIPLIER 65599
#define SIZE 509

static unsigned int SymTable_hash(const char *name){
	size_t ui;
	unsigned int uiHash=0U;
	for (ui=0U; name[ui]!='\0'; ui++)			
        uiHash=uiHash*HASH_MULTIPLIER+name[ui];
	return uiHash;
}

HashTable SymTable_new(void){
    HashTable oSymTable;
    int i;
    oSymTable=malloc(sizeof(struct HashTable)*SIZE);      /*array 509 thesewn apo pointer se listes*/
    assert(oSymTable);
    for(i=0;i<SIZE;i++) {
        oSymTable[i].head=NULL;        /*arxikopoiw to head kathe array bucket se null*/
    }
    return oSymTable;
}

SymbolTableEntry* SymTable_Insert(HashTable oSymTable, char* name, int active, enum SymbolType type, int scope, int line){
    Node newnode, p, last;
    int count=0, flag=0, i;
    unsigned int position,result;

    assert(name);
    assert(oSymTable);
    result=SymTable_hash(name);
    position=result%SIZE;           /*pairnw to mod509 gia na exw apotelesma sto range 0-509*/
    p=oSymTable[position].head;
    last=oSymTable[position].head;
    
    if(type==GLOBAL || type==LOCAL || type==FORMAL) {       /*variable type*/
        Variable* var=(Variable*)malloc(sizeof(Variable)); 
        if(!var){
            free(p);
            return NULL;
        }
        var->name=name;
        var->scope=scope;
        var->line=line;
            newnode=malloc(sizeof(struct SymbolTableEntry));       /*an den vrhka to key tote ftiaxnw neo node gia na eisagw ta nea stoixeia*/
            newnode->temp=malloc(sizeof(char));       /*xreiazomai ena temp gia na valw mesa to antigrafo tou name*/
            assert(newnode);
            assert(newnode->temp);
            newnode->value.varVal=var;
            newnode->type=type;
            newnode->isActive=active;
            count = strlen(name);           /*antigrafw ena ena ta char tou string sto temp*/
            for (i=0; i<count; i++) {        /*metraw to mhkos tou name epeidh an ekana strcpy sketo to name tha antegrafe mono to prwto char tou. emeis theloume OLO to string*/
                strcpy(newnode->temp, name);
            }
            newnode->value.varVal->name=newnode->temp;     /*o logos pou evala to temp san pedio tou struct htan gia na mporesw na to kanw free epeita sth sunarthsh FREE mesw tou osymtable*/
            if (oSymTable[position].head==NULL){      /*an to list einai adeio vazw to head na deixnei sto prwto node pou molis mphke*/
                oSymTable[position].head=newnode;
                oSymTable[position].length=1;           /*h lista periexei ena mono stoixeio*/
            }
            else{
                oSymTable->length++;            /*auksanw to mhkos*/
                while (last->next){      /*alliws proxoraw th lista mexri to telos ths*/
                    last=last->next;
                }
                last->next=newnode;       /*kai vazw to pedio next tou teleutaiou komvou ths listas na deixnei sto nenwode*/
            }
            return newnode;         /*epistrefw 1 afou mphke kainourgio node*/
        }
    else {      /*function type*/
        Function* func=(Function*)malloc(sizeof(Function)); 
        if (!func) {
            free(p); 
            return NULL;
        }
        func->name=name;
        func->scope=scope;
        func->line=line;
            newnode=malloc(sizeof(struct SymbolTableEntry));       /*an den vrhka to key tote ftiaxnw neo node gia na eisagw ta nea stoixeia*/
            newnode->temp=malloc(sizeof(char));       /*xreiazomai ena temp gia na valw mesa to antigrafo tou name*/
            assert(newnode);
            assert(newnode->temp);
            newnode->value.funcVal=func;
            newnode->type=type;
            newnode->isActive=active;
            count = strlen(name);           /*antigrafw ena ena ta char tou string sto temp*/
            for (i = 0; i < count; i++) {        /*metraw to mhkos tou name epeidh an ekana strcpy sketo to name tha antegrafe mono to prwto char tou. emeis theloume OLO to string*/
                strcpy(newnode->temp, name);
            }
            newnode->value.funcVal->name=newnode->temp;     /*o logos pou evala to temp san pedio tou struct htan gia na mporesw na to kanw free epeita sth sunarthsh FREE mesw tou osymtable*/
            if (oSymTable[position].head==NULL){      /*an to list einai adeio vazw to head na deixnei sto prwto node pou molis mphke*/
                oSymTable[position].head=newnode;
                oSymTable[position].length=1;           /*h lista periexei ena mono stoixeio*/
            }
            else{
                oSymTable->length++;            /*auksanw to mhkos*/
                while (last-> next){      /*alliws proxoraw th lista mexri to telos ths*/
                    last=last->next;
                }
                last->next=newnode;       /*kai vazw to pedio next tou teleutaiou komvou ths listas na deixnei sto nenwode*/
            }
            return newnode;         /*epistrefw 1 afou mphke kainourgio node*/
        }
}

SymbolTableEntry* SymTable_Lookup(HashTable oSymTable, const char *name, enum SymbolType type, int scope){
    Node tmp;
    int flag=0;
    unsigned int position,result;
    assert(name);
    assert(oSymTable);
    result=SymTable_hash(name);
    position=result%SIZE;    
    tmp=oSymTable[position].head;
    if(type==GLOBAL || type==LOCAL || type==FORMAL) {
        while(tmp) {        /*diatrexw olh th lista mexri na vrw to key*/
            if(strcmp(tmp->value.varVal->name,name)==0 && tmp->value.varVal->scope==scope) {
                return tmp;
            }   
            tmp=tmp->next;
        }
    }
    else {
        while(tmp) {        /*diatrexw olh th lista mexri na vrw to key*/
            if(strcmp(tmp->value.funcVal->name,name)==0 && tmp->value.funcVal->scope==scope) {
                return tmp;
            }   
            tmp=tmp->next;
        }
    }
    return NULL;
}

void SymTable_Print(HashTable oSymTable, int max_scope) {
    int i,j;
    Node tmp;
    for(j=0;j<=max_scope;j++){
        printf("\n------------- scope #%d -------------\n",j);
        for (i=0; i<SIZE; i++) {
            if (oSymTable[i].head != NULL) { //an einai adeio den tupwnw
                tmp=oSymTable[i].head;
                while (tmp!=NULL) {
                    if(tmp->type==USERFUNC || tmp->type==LIBFUNC){
                        if(tmp->value.varVal->scope==j) {      /*tupwnw oses metavlhtes den exoun ginei hide*/
                            if(tmp->type==GLOBAL) printf("\"%s\" [global variable]  (line %d) (scope %d)\n",tmp->value.varVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                            else if(tmp->type==LOCAL) printf("\"%s\" [local variable]  (line %d) (scope %d)\n",tmp->value.varVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                            else if(tmp->type==FORMAL) printf("\"%s\" [formal argument]  (line %d) (scope %d)\n",tmp->value.varVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                            else if(tmp->type==USERFUNC) printf("\"%s\" [user function]  (line %d) (scope %d)\n",tmp->value.funcVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                            else if(tmp->type==LIBFUNC) printf("\"%s\" [library function]  (line %d) (scope %d)\n",tmp->value.funcVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                        }
                    }
                    else{
                        if(tmp->value.funcVal->scope==j) {      /*tupwnw oses metavlhtes den exoun ginei hide*/
                            if(tmp->type==GLOBAL) printf("\"%s\" [global variable]  (line %d) (scope %d)\n",tmp->value.varVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                            else if(tmp->type==LOCAL) printf("\"%s\" [local variable]  (line %d) (scope %d)\n",tmp->value.varVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                            else if(tmp->type==FORMAL) printf("\"%s\" [formal argument]  (line %d) (scope %d)\n",tmp->value.varVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                            else if(tmp->type==USERFUNC) printf("\"%s\" [user function]  (line %d) (scope %d)\n",tmp->value.funcVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                            else if(tmp->type==LIBFUNC) printf("\"%s\" [library function]  (line %d) (scope %d)\n",tmp->value.funcVal->name, tmp->value.varVal->line,tmp->value.varVal->scope);
                        }
                    }
                    tmp=tmp->next;
                }
            }
        }
    }
}

int SymTable_Hide(HashTable oSymTable, int scope){
    int i;
    Node tmp;
    for(i=0;i<SIZE; i++){
        tmp=oSymTable[i].head;
        while(tmp!=NULL){
            if(tmp->value.varVal->scope==scope){        /*apenergopoieitai to pedio isActive*/
                tmp->isActive=0;
            }
            tmp=tmp->next;
        }
    }
    return 0;
}