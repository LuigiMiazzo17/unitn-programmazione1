//
//  main.cpp
//  17-Pointers
//
//  Created by Luigi Miazzo on 15/02/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int x = 3;
    
    int *y = &x;
    
    int **z = &y;
    
    cout << "x: " << x << "; &x: " << &x << endl;
    cout << "y: " << y << "; &y: " << &y << "; *y: " << *y << endl;
    cout << "z: " << z << "; &z: " << &z << "; *z: " << *z << "; **z: " << **z << endl;
    
    return 0;
}
