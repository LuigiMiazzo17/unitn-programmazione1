//
//  main.cpp
//  23-fattorialeRicorsivo
//
//  Created by Luigi Miazzo on 17/02/22.
//

#include <iostream>

using namespace std;

int fattoriale(int);

int main(int argc, const char * argv[]) {
    
    int n = 6;
    
    cout << fattoriale(n) << endl;
    
    return 0;
}

int fattoriale(int n){
    if(n<=1)
        return 1;
    return n*fattoriale(n-1);
}
