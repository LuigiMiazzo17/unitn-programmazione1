//
//  pila.hpp
//  50-PalindromaCodaPila
//
//  Created by Luigi Miazzo on 20/02/22.
//

#ifndef pila_hpp
#define pila_hpp

struct nodoPila {
   int value;
   nodoPila* next;
};

typedef nodoPila* listaPila;

void pila_init();
bool pila_push(int);
bool pila_top(int &);
bool pila_pop();
void pila_deinit();
void pila_print();

#endif /* pila_hpp */
