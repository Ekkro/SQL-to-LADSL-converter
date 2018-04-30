#include <stdio.h>                                                                                                                      
#include <strings.h>
#include <glib.h>

/* -----GLIB----- */
#define insertDecs(...) g_hash_table_insert(hDecs,__VA_ARGS__)
#define lookupDecs(...) g_hash_table_lookup(hDecs,__VA_ARGS__)
#define removeDecs(...) g_hash_table_remove(hDecs,__VA_ARGS__)

#define insertFuns(...) g_hash_table_insert(hFuns,__VA_ARGS__)
#define lookupFuns(...) g_hash_table_lookup(hFuns,__VA_ARGS__)
#define removeFuns(...) g_hash_table_remove(hFuns,__VA_ARGS__)

/* -------------- */

typedef struct node{
  char* string;
  struct node * next;
}Node;

typedef struct  select{
  int sizeSelects;
  struct select* selects[10];
  HashData* alias;
  Node return_values;
  Node orderby;
  int sizetables;
  Node tables[1];
}Select;

FILE* out;
int flag = 0;
char* tables;

typedef struct hashData{
    char type;
    int pt;
    int len;
    GSList *dim;
} *HashData;

/* -----declarations.c----- */
void add_rename(char* rename, Select select);

void add_Literalfilter(char* filter,char* table, Select select);

void add_filter(char* atributo1, char* atributo2, char* op, char* table, Select select);

//void join (int flag, char* atributo1, char* atributo2);

HashData newHashData(char type, int pt, GSList *dim);

int converToIndex(GString *name, GSList *indexL);

int calcLen(GSList *dim);

void hdPrint(HashData hd);


/* ------------------------ */
