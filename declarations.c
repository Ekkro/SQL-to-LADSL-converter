 #include <stdio.h>                                                                                                                      
 #include <strings.h>
 #include "SQLtoLADSL.h"


void add_rename(char* rename, Select select){
  Node aux = new Node;
  aux->string = rename;
  aux->next = select->alias;
  select->alias=aux;
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

int calcLen(GSList *dim){
    int len = 1;
    if(dim == NULL) return 0;
    for(GSList *it = dim; it; it=it->next){
        len *= (int)it->data;
    }

    return len;
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
