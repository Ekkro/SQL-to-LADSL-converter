#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <strings.h>
using namespace std;


bool has(vector<string> v, string s);

    /* ..................................................... */
    /* .....................YACC......string.................... */
    /* ..................................................... */

    typedef struct {
        string expr;
        string type;
    } par;

    /* ..................................................... */

    /* .....................GRAPH.......................... */
    /* ..................................................... */

class Graph {
    public:
    /* ..................................................... */
    /* ... */
    string root;

    /* .....JOIN......

           structure to save the joins
            key => foreign key
            Values => (table1 ,table2 )
         */

    vector<vector<string>  > join;

    /* ..... GROUPBY .....

           structure to save the groupby
            (Table ,attribute )
         */
    vector<pair <string,string> > groupby;

    /* .....TABLES.....

           structure to save the tables
            key => name of the table
            Values =>
                |key => name of the filter
                |Values => filter type  [ type = 0 it is a measure   ]
                                        [ type = 1 it is a dimension ]
         */
    map<string,map<string,string> > tables;

    /* ......FILTER.....

           structure to save the filters
            key => name of the attribute
            Values => filter set
         */
    map<string, vector<string> > filter;

    /* ......SELECT......

           structure to save the selects
           set attributes
         */
    vector< pair<string,string> > select;

    /* ..................................................... */

        Graph clone(vector<string> v);

        void newRoot(string newRoot);

            /* calculates the number of attributes of table */
            /* arguments : name of a table */
            /* returns : the number of attributes */
        int num_attributes(string str);

            /* add a filter */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* arguments : filter type */
        void add_filter(string Table,string filter, int type);

            /* remove a filter from a table */
            /* arguments : name of a table */
            /* arguments : filter name */
        void remove_filter(string Table,string filter);

            /* to serach for a filter in table */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* return : found the filter in the table
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int search_filter_in_table(string table, string filter);


            /* tables that have the filter */
            /* arguments : filter name */
            /* return : set of tables */
        vector<string> search_filter(string filter);

            /* look for a table */
            /* arguments : name of the table */
            /* return : if you found it or not
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int search_table(string table);

            /* add a table */
            /* arguments : name of a table */
            /* arguments : filter name */
        void add_table(string Table, string filter, string type);

            /* remove a table */
            /* arguments : name of a table */
        void remove_table(string Table);

        void add_join(string fk,string table1, string table2);

        void remove_join(string fk);


            /* add a filter to the group by */
            /* arguments : name of a table */
            /* arguments : filter name */
        void add_groupby(string Table,string filter);

            /* remove a filter to the group by */
            /* arguments : name of a table */
            /* arguments : filter name */
        void remove_groupby(string Table,string filter);

            /* add a filter to map filters */
            /* arguments : filter name */
            /* arguments : expression */
        void add_map_filter(string Filter, string expression);

            /* remove a filter to map filters */
            /* arguments : name of a table */
        void remove_map_Table_filter(string Table);

            /* remove a filter to map filters */
            /* arguments : name of a table */
            /* arguments : filter name */
        void remove_map_filter(string Table,string Filter);

            /* adds a table to the Selects */
            /* arguments : name of a table */
        void add_select(string sel, string alias);

            /* remove a table to the Selects */
            /* arguments : name of a table */
/*        void remove_select(string sel);*/

            /* whether it is measured or not */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* return : if you found it or not
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int is_measured(string Table, string filter);

            /* whether it is dimension or not */
            /* arguments : name of a table */
            /* arguments : filter name */
            /* return : if you found it or not
                        [ 1 -> found himself ]
                        [ 0 -> if not found  ]
             */
        int is_dimension(string Table, string filter);

            /* add a table */
            /* arguments : name of a table */
            /* arguments : filter name */
/*
        void add_table(string Table, string name){
            Graph[Table].insert(filter,str);
        }
*/

            /* test if two attributes are from the same table */
            /* arguments : name of the first attribute */
            /* arguments : name of the second attribute */
            /* return : whether they are from the same table or not
                        [ 1 -> if they are ]
                        [ 0 -> if no       ]
             */
        int isThe_same_Table(string attribute1, string attribute2);


        int isThe_same_Table_array(vector<string> v);


};

    /* ..................................................... */
    /* .....................LTREE.......................... */
    /* ..................................................... */

class Ltree {

    public:
    /* ............................................... */
    /* .....ltree.........

            structure to represent the logical tree
    */

    vector<string> ltree;

    /* ............................................... */
    //vector<pair<string,string>> ltree; possivelmente será necessário alterar o codigo para esta ltree


        Ltree();

        Ltree(string s);

            /*
               calculates the parent
                arguments : childs index
                retuens : return parrent
            */
        string Parent(int indice);


            /*
                left child
                arguments : fathers index
                retuens : return son of the left
            */
        string left_child(int indice);


            /*
                left child index
                arguments : fathers index
                retuens : return the left child index
            */
        int ind_left_child(int indice);

            /*
                rigth child
                arguments : fathers index
                retuens : return son of the rigth
            */
        string right_child(int indice);

            /*
                rigth child index
                arguments : fathers index
                retuens : return the rigth child index
            */
        int ind_right_child(int indice);


        vector<string> childs_aux(vector<string> v1, vector<string> v2);

            /*
                computes the list of all children
                arguments : fathers index
                retuens : returns the list of all children
            */
        vector<string> childs(int ind);

        void erasechilds(int ind);

            /*
                adds a filter to the tree
                arguments : filter
                arguments : index
            */
        void add(string value ,int indice );

            /*
                computes the index of a filter
                arguments : filter
                return : index
            */
        int indice(string value);

            /*
                change the position of one filter,
                by the position of the other
                arguments : index1
                arguments : index2
            */
        void swap(int indice1,int indice2 );


            /*
                calculates the father, common to both,closer
                arguments : index1
                arguments : index2
                return : father
            */
        string common_ancestor( int indice1, int indice2 );

            /*
                merge the current vector with another
                arguments : vector
            */
        void merge(vector<string> vec);

            /*
                separates into two trees (AUX)
                arguments : vector
                arguments : index1
                arguments : index2
            */
        vector<string> split_aux(vector<string> res, int indice1, int indice2);

            /*
                separates into two trees
                arguments : index1
                arguments : index2
            */
        vector<string> split(int indice1, int indice2);


        void insere(vector<string>::iterator it_ind, string s);
            /*
                add a tree to the current tree
                arguments : vector
                arguments : current tree index
                arguments : vector index
            */
        void add_tree(vector<string> v, int ind, int n=0);

            /*
                search for the closest node that is an or
                arguments : parent index
                arguments : favourite child
            */
        void search_nextOR_aux(int parent, int favourite_child);

        /*
            search for the closest node that is an or
            arguments : parent index
            arguments : favourite child
        */
    int ind_Parent(int indice);

        /*
            all the parents of given node
            arguments : child index
            return : vector with all parents
        */
    vector<int> parents(int i);


    string all_same_table_aux(int indice);

    bool all_same_table(int indice);

    bool dependencies(int indice);

    void search_nextOR(Graph g ,int ind);

    string relacao_entre(vector<string> v, int s);

    void funcao(Graph g, int x=0);

    int push_aux(int ind);

    void pushLT(int ind);

    void rewrite(int ind);
};



    /* ..................................................... */
    /* .....................DECLARATIONS.......................... */
    /* ..................................................... */

Ltree create_tree(string term, string type);

Ltree join_trees(Ltree l1, Ltree l2, string type);


void dot_all(int ind);

string getTable(string attribute);

vector<int> subvector (vector<int> v1, vector<int> v2);

string relacao_entre(vector<string> v, string s);

string relacao_entre_arrays(vector<string> v, vector<string> s);

void graphWork();

void graphWorkAux(int x);

void joinAtr(string start);

void joinAtrD(string s, vector<string> v);

void joinFilters(string start);

void joinFiltersM(vector<string> v);

void joinFiltersD(vector<string> v);

void joinGroupby(string start);

void joinGroupbyAux(string gb);

void removeTable(string start);

string giveMeStart(string root);

void next();

void trabalha(int ind);

void trabalhaaux(int ind, int count);

void cleanexp();

void addexp(string exp);

void aux(string exp);

void merge(vector<string> v);

void resolveS(int indice, string type);

void resolve(int indice);

void returnf();



string a = "A";
Graph mainGraph;
Graph g;
Ltree l;
vector<Ltree> trees;
int itr = 0;
vector<par> types;
int itr2 = 0;
