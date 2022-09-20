//
//  main.cpp
//  10-scambioSenzaVarTemp
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a,b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    cout << "Prima dello scambio " << endl << "a: " << a << "; b: " << b << endl;
    
    a = a + b;
    b = a - b;
    a = a - b;
    
    cout << "Dopo dello scambio " << endl << "a: " << a << "; b: " << b << endl;
    
    return 0;
}
