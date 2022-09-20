//
//  charArrFunctions.cpp
//  util03-charArrFunctions
//
//  Created by Luigi Miazzo on 22/02/22.
//

#include "charArrFunctions.hpp"

int stringLen(const char * str){
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}

int strFind(char * str, char c){
    int len = stringLen(str);
    for(int i = 0; i < len; i++)
        if(str[i] == c)
            return i;
    return -1;
}

bool subStr(char * str, const char * text, int strLen, int from, int to){
    int textLen = stringLen(text);
    if(to <= 0){
        if(strLen <= textLen + 1)
            to = strLen - 2;
        else
            to = textLen - 1;
    }
    if(from < 0 || from > textLen || to - from + 1 > strLen)
        return false;

    for(int i = from; i <= to; i++)
        str[i - from] = text[i];
    
    str[to + 1] = '\0';
    
    return true;
}

bool stringCpy(char * str, const char * text, int strLen){
    int textLen = stringLen(text);
    if(strLen - 1 < textLen)
        return false;
    for(int i = 0; i < textLen; i++)
        str[i] = text[i];
    
    str[textLen] = '\0';
    return true;
}
