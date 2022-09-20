//
//  main.cpp
//  16-convertitoreBinarioDecimale
//
//  Created by Luigi Miazzo on 13/02/22.
//

#include <iostream>
#include <math.h>

using namespace std;

void convert(long*, int, bool);

int main(int argc, const char * argv[]) {
    
    cout << "Convertitore binario-decimale" << endl << "0.Binario->Decimale" << endl << "1.Decimale->Binario" << endl << "Scelta: ";
    
    bool to = false;
    cin >> to;
    
    int n = 0;
    cout << "Numero da convertire: ";
    cin >> n;
    
    long res = 0;
    convert(&res, n, to);
    
    cout << endl << "Risultato: " << res << endl;
    
    return 0;
}

void convert(long* res, int n, bool to){
    int base1 = to ? 2 : 10; //false -> to decimal
    int base2 = to ? 10 : 2; //true -> to binary
    
    for(int i = 0; i < 16; i++)
        *res += ((long)(n / pow(base1, i)) % base1) * pow(base2, i);
    
}
