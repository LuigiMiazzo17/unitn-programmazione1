//
//  estrai.cpp
//  43-estraiLettereMaiuscoleR
//
//  Created by Luigi Miazzo on 19/02/22.
//

#include "estrai.hpp"

void estrai(char res[], const char str[], int len, int pos, int counter){
    if(pos == len)
        return;
    if(str[pos] >= 'A' && str[pos] <= 'Z')
        res[counter++] = str[pos];
    estrai(res, str, len, pos + 1, counter);
    return;
}
