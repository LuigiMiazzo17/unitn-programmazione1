//
//  main.cpp
//  11-ValoreAssoluto!IfElse
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a = 3;
    int b = 4;
    
    int c = ((a>=b)*(a-b) - (a<b)*(a-b));
    
    cout << c << endl;
    
    return 0;
}
