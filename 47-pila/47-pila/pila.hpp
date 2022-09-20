//
//  pila.hpp
//  47-pila
//
//  Created by Luigi Miazzo on 20/02/22.
//

#ifndef pila_hpp
#define pila_hpp

#include <stdio.h>
 
struct nodo {
    int value;
    nodo* next;
};
typedef nodo* lista;
 
void init();
bool push(int);
bool top(int &);
bool pop();
void deinit();

#endif /* pila_hpp */
