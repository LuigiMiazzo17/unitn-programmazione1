//
//  emailVerifier.cpp
//  45-checkValidEmail
//
//  Created by Luigi Miazzo on 19/02/22.
//

#include "emailVerifier.hpp"

int strlen(const char[]);
void strCpy(char[], const char[], int, int);
int strFindAt(const char [], int);
bool haveLegalCharaters(const char[]);

bool isValidEmail(const char str[]){
    int len = strlen(str);
    
    int atAt = strFindAt(str, len);
    
    if(atAt == -1)
        return false;
    
    char usr[256];
    char domain[256];
    
    strCpy(usr, str, 0, atAt);
    strCpy(domain, str, atAt + 1, len);
    
    if(strlen(usr) < 1)
        return false;
    if(strlen(domain) < 1)
        return false;
    
    if(usr[0] == '.' || usr[strlen(usr) - 1] == '.')
        return false;
    if(domain[0] == '.' || domain[strlen(domain) - 1] == '.')
        return false;
    if(!haveLegalCharaters(usr))
        return false;
    if(!haveLegalCharaters(domain))
        return false;
    
    return true;
}

bool haveLegalCharaters(const char str[]){
    int len = strlen(str);
    
    for(int i = 0; i < len; i++)
        if(!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == '_'))
            return false;
    return true;
}

void strCpy(char res[], const char str[], int from, int to){
    for(int i = from; i < to; i++)
        res[i - from] = str[i];
    res[to - from] = '\0';
    return;
}

int strFindAt(const char str[], int len){
    int counter = -1;
    
    bool found = false;
    for(int i = 0; i < len; i++)
        if(str[i] == '@'){
            if(!found){
                counter = i;
                found = true;
            }
            else
                return -1;
        }
    
    return counter;
}

int strlen(const char str[]){
    int counter = 0;
    while(str[counter++] != '\0');
    return counter - 1;
}
