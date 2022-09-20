//
//  main.cpp
//  52-PalindromaRicorsiva
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>

using namespace std;

int MAX_LEN = 100;

int strLen(const char[]);
bool isPalindroma(const char[], int, int);

int main(int argc, const char * argv[]) {
    
    cout << "Stringa da verificare: ";
    char str[100];
    cin >> str;
    
    int len = strLen(str);
    
    if(isPalindroma(str, 0, len - 1))
        cout << "OK!" << endl;
    else
        cout << "NO!" << endl;
    return 0;
}

int strLen(const char str[]){
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}

bool isPalindroma(const char str[], int i, int f){
    if(i >= f)
        return true;
    if(str[i] == str[f])
        if(isPalindroma(str, i+1, f-1))
            return true;
    return false;
}
