//
//  main.cpp
//  18-InvertiNumero
//
//  Created by Luigi Miazzo on 16/02/22.
//

#include <iostream>
#include <math.h>

using namespace std;

long invertiNumero(int);

int main(int argc, const char * argv[]) {
    
    cout << "Numero: ";
    int n;
    cin >> n;
    
    cout << "Numero invertito: " << invertiNumero(n) << endl;
    
    return 0;
}


long invertiNumero(int n){
    long iN = 0;
    int max = 0;
    
    for (int i = 0; i < 16; i++){
        int value = ((int)(n / pow(10, i)) % 10);
        
        if (value != 0){
            max = i;
        }
        
        iN += value * pow(10, 16-i);
    }
    
    iN = iN / pow(10, 16-max);
    
    return iN;
}
