//
//  main.cpp
//  12-Fibonacci
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

int fibonacci(int);

int main(int argc, const char * argv[]) {
    
    cout << "hmmm" << endl;
    
    for(int i = 0; i < 20; i++){
        cout << fibonacci(i) << endl;
    }
    return 0;
}

int fibonacci(int n){
    if(n == 1 || n == 0){
        return n;
    }
    
    return fibonacci(n-1) + fibonacci(n-2);
}
