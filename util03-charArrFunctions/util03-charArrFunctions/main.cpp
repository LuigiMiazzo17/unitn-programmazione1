//
//  main.cpp
//  util03-charArrFunctions
//
//  Created by Luigi Miazzo on 22/02/22.
//

#include <iostream>
#include "charArrFunctions.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    char str1[] = "Ciao test!";
    char str2[stringLen(str1) + 1];
    
    if(stringCpy(str2, str1, stringLen(str1) + 1))
        cout << str2;
    else
        cout << "Errore";
    cout << endl;
    
    return 0;
}
