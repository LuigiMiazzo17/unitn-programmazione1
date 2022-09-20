//
//  main.cpp
//  26-sommaCifreRicorsiva
//
//  Created by Luigi Miazzo on 17/02/22.
//

#include <iostream>

using namespace std;

uint sommaCifre(uint);

int main(int argc, const char * argv[]) {
    
    cout << sommaCifre(14591) << endl;
    
    return 0;
}

uint sommaCifre(uint n){
    
    if(n < 10)
        return n;
    
    return n % 10 + sommaCifre(n / 10);
}
