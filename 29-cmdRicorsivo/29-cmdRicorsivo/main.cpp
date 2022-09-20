//
//  main.cpp
//  29-cmdRicorsivo
//
//  Created by Luigi Miazzo on 17/02/22.
//

#include <iostream>

using namespace std;

int rMCD(int, int);

int main(int argc, const char * argv[]) {
    
    cout << rMCD(6421, 5392) << endl;
    
    return 0;
}

int rMCD(int m, int n){
    if(m <= n)
        return n;
    return rMCD(n, m % n);
}
