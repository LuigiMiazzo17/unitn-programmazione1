//
//  main.cpp
//  19-swap
//
//  Created by Luigi Miazzo on 16/02/22.
//

#include <iostream>

using namespace std;

void swap(double *, double*);

int main(int argc, const char * argv[]) {
    
    double a = 3, b = 4;
    
    swap(&a, &b);
    
    cout << "a: " << a << "; b: " << b << endl;
    
    return 0;
}

void swap(double *n, double *m){
    int t = *n;
    *n = *m;
    *m = t;
    return;
}
