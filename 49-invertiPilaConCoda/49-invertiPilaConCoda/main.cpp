//
//  main.cpp
//  49-invertiPilaConCoda
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>
#include "pila.hpp"
#include "coda.hpp"

using namespace std;

void invertiElementi();

int main(int argc, const char * argv[]) {
    pila_init();
    coda_init();
    
    for(int i = 0; i < 8; i++)
        pila_push(i);
    
    pila_print();
    
    invertiElementi();
    
    pila_print();
    
    pila_deinit();
    coda_deinit();
    return 0;
}

void invertiElementi(){
    int buff;
    
    while(pila_top(buff)){
        coda_enqueue(buff);
        pila_pop();
    }
    pila_deinit();
    pila_init();
    
    while(coda_first(buff)){
        pila_push(buff);
        coda_dequeue();
    }
}
