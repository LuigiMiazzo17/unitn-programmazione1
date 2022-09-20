//
//  coda.hpp
//  49-invertiPilaConCoda
//
//  Created by Luigi Miazzo on 20/02/22.
//

#ifndef coda_hpp
#define coda_hpp

struct nodoCoda {
    int value;
    nodoCoda* next;
};
typedef nodoCoda* listaCoda;
 
struct coda {
    listaCoda tail;
    listaCoda head;
};
 
void coda_init();
bool coda_enqueue(int);
bool coda_first(int &);
bool coda_dequeue();
void coda_deinit();
void coda_print();

#endif /* coda_hpp */
