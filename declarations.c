 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include "SQLtoLADSL.h"


void add_rename(char* name, char* rename, Select select){
    if (select->alias == NULL) {
        select->alias = g_hash_table_new (g_str_hash, g_str_equal);
    }
    g_hash_table_insert (select->alias, g_strdup (name), g_strdup (rename));
}

void add_select(char* name, Select select){
    Node aux = new Node;
    aux->string = name;
    aux->next = select->return_values;
    select->return_values = aux;
}

void add_renameT(char* name, char* rename, GHashTable* Tables){
    if (Tables == NULL) {
        Tables= g_hash_table_new (g_str_hash, g_str_equal);
    }
    g_hash_table_insert (Tables, g_strdup (name), g_strdup (rename));
}

void attribute_Table(char* attribute, char* Table, GHashTable* Hash){
    if (Hash == NULL) {
        Hash = g_hash_table_new (g_str_hash, g_str_equal);
    }
    else{ 
        if (g_hash_table_lookup (Table,g_strdup(attribute)!= NULL) 
            printf("Atributo %s Apareçe em mais que uma tabela\n",attribute ));
    }
    g_hash_table_insert (Hash, g_strdup (attribute), g_strdup (Table));
    
} 

char* Table( char* attribute ){
    char* res = (char*) g_hash_table_lookup (attribute_Table,attribute); 
    return res;
}

void add_Literalfilter(char* filter,char* table, Select select){
  Node aux = new Node;
  aux->string = filter;
  aux->next = select->tables[hash(table,select->sizetables)];
  select->tables[hash(table,select->sizetables)] = aux;
}

void add_filter(char* atributo1, char* atributo2, char* op, char* table, Select select){
  printf
}

int calcLen(GSList *dim){
    int len = 1;
    if(dim == NULL) return 0;
    for(GSList *it = dim; it; it=it->next){
        len *= (int)it->data;
    }

    return len;
}

HashData newHashData(char type, int pt, GSList *dim){
    int len = calcLen(dim);
    HashData hd = (HashData)malloc(sizeof(struct hashData));
    hd->type = type;
    hd->pt = pt;
    hd->len = len;
    hd->dim = dim;
    return hd;
}

int converToIndex(GString *name, GSList *indexL){
    HashData hd = lookupDecs(name->str);
    int ret = 0;
    int i=0;

    for (GSList *itIndex = indexL; itIndex; itIndex = itIndex->next){
        int par = (int)itIndex->data;
        int j=0;
        for(GSList *itDim = hd->dim; itDim && j<i; itDim = itDim->next){
            par *= (int)itDim->data;
            j++;
        }
        i++;
        ret += par;
    }
    return ret;
}


void hdPrint(HashData hd){
    printf("estrutura a inserir na hash\n");
    printf("\ttype: %c\n",hd->type);
    printf("\tpointer: %d\n",hd->pt);
    printf("\tlength: %d\n",hd->len);
    printf("\n");
}

/*
void join (int flag, char* atributo1, char* atributo2){
    switch(flag){
        case 1:
               fprintf(out, "filter( %s = %s)\n",atributo1,atributo2);
               break;
        case 2:
              fprintf(out, "filter( %s != NULL)\n",atributo1);
              break;
        case 3:
              fprintf(out, "filter( %s != NULL)\n",atributo2);
              break;
        default:
              fprintf(out, "");
      }
}
%}
