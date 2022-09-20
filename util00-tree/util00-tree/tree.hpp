//
//  tree.hpp
//  util00-tree
//
//  Created by Luigi Miazzo on 21/02/22.
//

#ifndef tree_hpp
#define tree_hpp

struct tree;
struct node;

struct node{
    int value;
    node * left;
    node * right;
    
    bool isLeaf();
    void insert(int);
    void deleteNode();
    bool find(int);
    void printNode(int);
    void printSortedNode();
    void search(int);
    void getElements(int[], int&);
    int countElements();
    static node* nodeBst(int[], int, int);
};

struct tree{
    node * root;
    
    static tree createNewTree();
    bool isEmpty();
    void insert(int);
    void deleteTree();
    bool find(int);
    void printTree();
    void printSortedTree();
    void search(int);
    int * getElements(int&);
    int countElements();
    static tree bst(int[], int);
    void bst();
};

void bubbleSort(int[], int);

/*definition of funtions
 
node:
 
 int value
    valore del nodo
 node * left/right
    puntatori ai nodi successivi, se == nullptr allora il nodo successivo non esiste
 
 bool isLeaf()
    ritorna vero se il nodo non ha figli, altrimenti falso
 
 void insert(int)
    inserisce il valore passato per paramentro nel sottoalbero del nodo
 
 void deleteNode
    cancella il sottoalbero
 
 bool find(int)
    ritorna vero se il valore passato per argomento è presente nel sottoalbero, altrimenti ritorna falso
 
 void printNode(int)
    stampa a video il sottoalbero in forma grafica
 
 void printSortedNode
    stampa a video gli elementi del sottoalbero in maniera ordinata
 
 void find(int)
    ricerca nel sottoalbero il valore passato per paramentro
 
 void getElements(int[], int&)
    inserisce nel array passato per paramentro gli elementi del sottoalbero, e
    inserisce nel paramentro passato per riferimento quanti elementi sono stati aggiunti
 
 void countElements
    ritorna la quantita di elementi contenuta nel sottoalbero
 
 static node* nodeBst(int[], int, int)
    ritorna un nuovo sottoalbero che fa parte di un albero bilanciato
 
 
tree:
 
 node * root
    radice dell'albero puntato, se == nullptr allora l'albero è vuoto
 
 static tree createNewTree
    ritorna un nuovo albero inizializzato
 
 bool isEmpty();
    ritorna vero se l'albero è vuoto, altrimenti falso
 
 void insert(int);
    inserisce nell'albero il valore passato per parametro
 
 void deleteTree();
    cancella l'albero
 
 bool find(int);
    ritorna vero se il valore passato per argomento è presente nel'albero, altrimenti ritorna falso
 
 void printTree();
    stampa a video l'albero in forma grafica
 
 void printSortedTree();
    stampa a video gli elementi dell'albero in maniera ordinata
 
 void find(int);
    ricerca nell'albero il valore passato per paramentro
 
 int * getElements(int&);
    ritorna un array dinamico con contenuti gli elementi dell'albero, e
    inserisce nel parametro passato per riferimento il numero di elementi
 
 int countElements();
    ritorna la quantita di elementi contenuta nell'albero
 
 static tree bst(int[], int);
    ritorna un nuovo albero bilaciato da un array passato per parametro
    di lunghezza passata per paramentro
 
 void bst();
 
 */

#endif /* tree_hpp */
