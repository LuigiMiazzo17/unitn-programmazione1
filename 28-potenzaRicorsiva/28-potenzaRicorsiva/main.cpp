//
//  main.cpp
//  28-potenzaRicorsiva
//
//  Created by Luigi Miazzo on 17/02/22.
//

#include <iostream>

using namespace std;

int rPow(int, uint);

int main(int argc, const char * argv[]) {

    cout << rPow(10, 3) << endl;

    return 0;
}

int rPow(int b, uint e){
    if(e <= 0)
        return 1;
    
    return b * rPow(b, e-1);
}
