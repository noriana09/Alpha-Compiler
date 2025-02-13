#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>

/*ULOPOIHSH ME KSEXWRISTES ALUSIDES - LISTES ANA BUCKET*/

typedef struct Variable {
    const char* name;
    unsigned int scope;
    unsigned int line;
} Variable;

typedef struct Function {
    const char* name;
    unsigned int scope;
    unsigned int line;
    unsigned int args;
    unsigned int iaddress;

} Function;

enum SymbolType{
    GLOBAL,LOCAL,FORMAL,USERFUNC,LIBFUNC
};

enum scopespace_t {
  programvar,functionlocal,formalarg
};

typedef struct SymbolTableEntry{
    int isActive;
    union{
        Variable* varVal;
        Function* funcVal;
    }value;
    enum SymbolType type;
    char* temp;
    char* name;
    enum scopespace_t space;
    unsigned offset;
    unsigned scope;
    unsigned line;             
    struct SymbolTableEntry *next;
}SymbolTableEntry;

struct HashTable{
    struct SymbolTableEntry* head;      /*o Symbol Table einai mia kenh domh pou se auth to to arxeio tha einai ena oloklhro hashtable*/
    unsigned int length;      /*mia metavlhth length gia na mporw na auksanw kai na meiwnw ton arithmo twn nodes eukola*/
};                          /*giauto periexei enan pointer ton opoion ustera tha valoume na deixnei ston prwto komvo ths kathe listas tou kathe keliou tou table*/

typedef struct SymbolTableEntry* Node;       /*sunonymo tou node gia eukolia*/

typedef struct HashTable *HashTable;

HashTable SymTable_new(void);

SymbolTableEntry* SymTable_Insert(HashTable oSymTable, char* name, int active, enum SymbolType type, int scope, int line);

SymbolTableEntry* SymTable_Lookup(HashTable oSymTable, const char *name, enum SymbolType type, int scope);

void SymTable_Print(HashTable oSymTable,int max_scope);

int SymTable_Hide(HashTable oSymTable, int scope);