//
//  coda.hpp
//  48-coda
//
//  Created by Luigi Miazzo on 20/02/22.
//

#ifndef coda_hpp
#define coda_hpp

#include <stdio.h>

struct nodo {
    char* nome;
    nodo* next;
};
typedef nodo* lista;
 
struct coda {
    lista tail;
    lista head;
};
 
void init ();
bool enqueue(char *);
bool first(char * &);
bool dequeue();
void deinit();
void print();

#endif /* coda_hpp */
