 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include "SQLtoLADSL.h"


void add_rename(GString* name, GString* rename, Select select){
    if (select->alias == NULL) {
        select->alias = g_hash_table_new (g_str_hash, g_str_equal);
    }
    g_hash_table_insert (select->alias, g_strdup ( name ), g_strdup (rename));
}

void add_select(GString* name, Select select){
    Node aux = malloc(sizeof(struct Node));
    aux->string = name;
    aux->next = select->return_values;
    select->return_values = aux;
}

void add_renameT(GString* name, GString* rename, GHashTable* Tables){
    if (Tables == NULL) {
        Tables= g_hash_table_new (g_str_hash, g_str_equal);
    }
    g_hash_table_insert (Tables, g_strdup (name), g_strdup (rename));
}

void attribute_Table(GString* attribute, GString* Table, GHashTable* Hash){
    if (Hash == NULL) {
        Hash = g_hash_table_new (g_str_hash, g_str_equal);
    }
    else{ 
        if (g_hash_table_lookup (Table,g_strdup(attribute)!= NULL) 
            printf("Attribute %s appears in more than one table\n",attribute ));
    }
    g_hash_table_insert (Hash, g_strdup (attribute), g_strdup (Table));
    
} 

GString* Table( GString* attribute ){
    GString* res = (GString*) g_hash_table_lookup (attribute_Table, g_strdup (attribute)); 
    return res;
}

void add_Literalfilter(GString* filter,GString* table, Select select){
  Node aux = new Node;
  aux->string = filter;
  aux->next = select->tables[hash(table,select->sizetables)];
  select->tables[hash(table,select->sizetables)] = aux;
}

void add_filter(GString* attribute1, GString* attribute2, GString* op, GString* table, Select select){
    Filter aux = malloc(sizeof(struct Filter));
    Gstring* filter = g_strdup (attribute1);
    filter = g_string_append (filter, g_strdup(op)); 
    filter = g_string_append (filter, g_strdup(attribute2)); 
    aux->filter = filter ;

    /* Find the table */
    for (int i = 0; i < select->sizetables; i++) {
        if(select->tables[i] == table) {
            aux->next = select->tables[i]->Filter;            
            select->tables[i]->Filter = aux;
        }
    }
}

void rewrite_filters(Table table, int size){
    for (int i = 0; i < size; i++) {
        table[i]->Filters = rewrite__filters_aux(table->Filters)
    }
}


//void print_hasTable(GHashTable table){
//}
//
//void print_Node(Node node){
//    printf("%s\n",node->string);
//    print_Node(node->next);
//}
//
//void print_filter(Filter filter){
//    
//}
//
//void print_Table(Table table){
//    printf("%s\n",table->name);
//    printf("GroupBy\n");
//    print_Node(table->GroupBy);
//    printf("Filters\n");
//    print_filter(table->Filters);
//}
//
//void print_struct(Select select){
//   print_hasTable(select->alias); 
//   print_Node(select->return_values); 
//   print_Node(select->orderby); 
//   for (int i = 0; i<sizetables; i++) {
//       print_Table(select->tables[i]);
//   }
//    for (int i =0; i<select->sizeSelects; i++) {
//        print_struct(select->selects[i]);
//    }
//}


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
void join (int flag, GString* atributo1, GString* atributo2){
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
