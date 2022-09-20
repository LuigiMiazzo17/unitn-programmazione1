//
//  charArrFunctions.hpp
//  util03-charArrFunctions
//
//  Created by Luigi Miazzo on 22/02/22.
//

#ifndef charArrFunctions_hpp
#define charArrFunctions_hpp

int stringLen(const char*);
int strFind(char*, char);
bool subStr(char*, const char*, int, int = 0, int = 0);
bool stringCpy(char*, const char*, int);
bool stringCmp(const char*, const char*);

/*
 
 functions definition
 
 stringLen
    ritorna il numero di elementi presenti dentro la stringa di caratteri
    passata per parametro (SENZA TERMINATORE)
 
 strFind
    ritorna la prima occorrenza del carattere passato per parametro
    nella stringa passata, se non e presente il carattere ritorna -1
 
 subStr
    mette dentro la prima stringa passata per parametro una porzione della seconda stringa
    il parametro di tipo int obbligatorio indica la lunghezza della prima stringa (COMPRESO IL TERMINATORE)
    secondo e ultimo int indicano rispettivamente da quale a quale elemento
    della seconda stringa la funzione deve copiare
    di default il programma parte da 0 e arriva fino a alla fine tra
    il minimo tra prima e seconda stringa
 
 stringCpy
    copia il contenuto della seconda stringa passata per parametro dentro la prima
    il parametro di tipo int indica la lunghezza della prima stringa (COMPRESO IL TERMINATORE)
    se la prima stringa e piu lunga della seconda, la funziona copia tutto
    il contenuto della seconda e comunque aggiunge il terminatore

 stringCmp
    ritorna vero se le due stringe passate per parametro sono uguali, altrimenti falso
*/
#endif /* charArrFunctions_hpp */
