//
//  main.cpp
//  03-TermometriAmericani
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    bool scelta = false;
    cout << "0-Da Celsius a Fahrenheit" << endl << "1-Da Fahrenheit a Celsius" << endl << "Scelta: ";
    cin >> scelta;
    
    cout << "Temperatura da convertire: ";
    float t = 0;
    cin >> t;
    
    cout << "Temperatura convertita: ";
    
    if(!scelta)
        cout << (t * 1.8) + 32;
    
    else
        cout << (t - 32) / 1.8;
    
    cout << endl;
    return 0;
}
