//
//  main.cpp
//  04-DivisioneConResto
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Dividendo: ";
    int dividendo = 0, divisore = 0;
    cin >> dividendo;
    cout << "Divisore: ";
    cin >> divisore;
    
    if(divisore == 0){
        cout << "Shei shtupidou?" << endl;
        return -1;
    }
    
    cout << "Ecco il quoziente: " << dividendo / divisore << endl << "Resto: " << dividendo % divisore << endl;
    
    return 0;
}
