#include <stdio.h>                                                                                                                      
#include <strings.h>
#include <glib.h>

/* For each select structure */
number_selects = 10;
number_tables = 1;

/* -----GLIB----- */
#define insertDecs(...) g_hash_table_insert(hDecs,__VA_ARGS__)
#define lookupDecs(...) g_hash_table_lookup(hDecs,__VA_ARGS__)
#define removeDecs(...) g_hash_table_remove(hDecs,__VA_ARGS__)

#define insertFuns(...) g_hash_table_insert(hFuns,__VA_ARGS__)
#define lookupFuns(...) g_hash_table_lookup(hFuns,__VA_ARGS__)
#define removeFuns(...) g_hash_table_remove(hFuns,__VA_ARGS__)

/* -------------- */

typedef struct node{
  GString* string;
  struct node * next;
}Node;

typedef struct filter{
    GString* filter;
    struct filter* next;
}Filter;


typedef struct table{
    GString* Name;
    Node GroupBy;
    Filter Filters;
}Table

typedef struct  select{
  int sizeSelects;
  struct select* selects[number_selects];
  GHashTable* alias;
  Node return_values;
  Node orderby;
  int sizetables;
  Table tables[number_tables];
}Select;

FILE* out;
int flag = 0;
GString* tables;

typedef struct _GHashTable GHashTable;

typedef struct hashData{
    char type;
    int pt;
    int len;
    GSList *dim;
} *HashData;

/* -----declarations.c----- */
void add_rename(GString* rename, Select select);

void add_Literalfilter(GString* filter,GString* table, Select select);

void add_filter(GString* atributo1, GString* atributo2, GString* op, GString* table, Select select);

//void join (int flag, GString* atributo1, GString* atributo2);

HashData newHashData(char type, int pt, GSList *dim);

int converToIndex(GString *name, GSList *indexL);

int calcLen(GSList *dim);

void hdPrint(HashData hd);


/* ------------------------ */
