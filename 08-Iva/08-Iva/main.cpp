//
//  main.cpp
//  08-Iva
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    float imponibile = 0, iva = 0;
    
    cout << "Imponibile: ";
    cin >> imponibile;
    cout << "Iva: ";
    cin >> iva;
    
    cout << "Risultato: " << imponibile * (iva + 100) / 100.0 << endl;
    
    return 0;
}
