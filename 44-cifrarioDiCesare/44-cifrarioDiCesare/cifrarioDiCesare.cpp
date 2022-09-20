//
//  cifrarioDiCesare.cpp
//  44-cifrarioDiCesare
//
//  Created by Luigi Miazzo on 19/02/22.
//

#include "cifrarioDiCesare.h"

void cifra(char res[], const char str[], int key, int len){
    for(int i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            res[i] = ((str[i] - 'a' + key) % 26) + 'a';
        else
            res[i] = str[i];
    }
}

void decifra(char res[], const char str[], int key, int len){
    for(int i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            res[i] = ((str[i] - 71 - key) % 26) + 'a';
        else
            res[i] = str[i];
    }
}
