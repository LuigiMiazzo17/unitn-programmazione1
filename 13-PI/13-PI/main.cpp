//
//  main.cpp
//  13-PI
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Iterazioni: ";
    int it = 0;
    cin >> it;
    
    double res = 0;
    for(int i = 1; i < it; i++){
        res += (1.0)/(i*i);
    }
    
    double pi = sqrt(6*res);
    
    cout << "Pi: " << pi << endl;
    
    return 0;
}
