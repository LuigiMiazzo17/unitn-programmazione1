//
//  main.cpp
//  02-DistanziamentoSociale
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

const float _PI = 3.1415;

int main(int argc, const char * argv[]) {
    cout << "Raggio: ";
    float r = 0;
    cin >> r;
    cout << "Ecco a te la circonferenza: " << _PI * r * 2 << endl;
    cout << "Ecco a te l'area: " << _PI * r * r << endl;
    return 0;
}
