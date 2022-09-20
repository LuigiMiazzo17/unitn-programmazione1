//
//  main.cpp
//  50-PalindromaCodaPila
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>
#include "pila.hpp"
#include "coda.hpp"

using namespace std;

bool isPalindroma(const char[]);
void invertiElementi();

int main(int argc, const char * argv[]) {
    
    pila_init();
    coda_init();
    
    char str[100] = "abcdadcba";
    int i = 0;
    
    while(str[i] != '\0')
        pila_push(str[i++]);
    
    i = 0;
    while(str[i] != '\0')
        coda_enqueue(str[i++]);
    
    if(isPalindroma(str))
        cout << "OK!" << endl;
    else
        cout << "No!" << endl;
    
    pila_deinit();
    coda_deinit();
    
    return 0;
}

bool isPalindroma(const char str[]){
    
    int buffPila;
    int buffCoda;
    while(pila_top(buffPila)){
        coda_first(buffCoda);
        if(buffPila != buffCoda)
            return false;
        pila_pop();
        coda_dequeue();
    }
    
    return true;
}
