//
//  main.cpp
//  25-rappBinRicorsiva
//
//  Created by Luigi Miazzo on 17/02/22.
//

#include <iostream>
#include <math.h>

using namespace std;

void binRep(int);

int main(int argc, const char * argv[]) {
    
    binRep(177);
    cout << endl;
    
    return 0;
}

void binRep(int n){
    
    if(n > 1)
        binRep(n / 2);
    
    cout << n % 2;
}
