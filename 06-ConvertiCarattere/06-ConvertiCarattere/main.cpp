//
//  main.cpp
//  06-ConvertiCarattere
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Carattere: ";
    char c;
    cin >> c;
    
    if(c >= 65 && c <= 90)
        c = c + 32;
    else if(c >= 0x61 && c <= 0x7a)
        c = c - 32;
    else{
        cout << "Ma Shei Shtupidou?" << endl;
        return -1;
    }
    
    cout << "Ecco: " << c << endl;
    
    return 0;
}
