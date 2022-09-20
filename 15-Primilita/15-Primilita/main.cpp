//
//  main.cpp
//  15-Primilita
//
//  Created by Luigi Miazzo on 13/02/22.
//

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int);

int main(int argc, const char * argv[]) {
    
    cout << "Limite superiore: ";
    int n = 0;
    cin >> n;
    cout << endl << "Numeri primi: 2, ";
    
    for(int i = 3; i <= n; i += 2)
         if(isPrime(i))
             cout << i << ", ";
    
    cout << endl;
    
    return 0;
}

bool isPrime(int n){
    
    double sqrtN = sqrt(n);
    
    if(n % 2 == 0)
        return false;
    
    for(int i = 3; i <= sqrtN; i += 2)
        if(n % i == 0)
            return false;
    
    return true;
}
