//
//  main.cpp
//  33-calcolatrice
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>
#include <cstdlib>

using namespace std;

void displayRes(float);

int main(int argc, const char * argv[]) {
    
    if(argc != 4){
        cout << "Wrong number of parameters!" << endl;
        return 0;
    }
    
    float n1 = atof(argv[1]);
    float n2 = atof(argv[3]);
    char op = argv[2][0];
    
    switch(op){
        case '+':
            displayRes(n1 + n2);
            break;
        case '-':
            displayRes(n1 - n2);
            break;
        case '*':
        case 'x':
            displayRes(n1 * n2);
            break;
        case '/':
            if(n2 == 0){
                cout << "Invalid parameter!";
                break;
            }
            displayRes(n1 / n2);
            break;
        case '%':
            displayRes((int)n1 % (int)n2);
            break;
        default:
            cout << "Unknown operator!";
            break;
    }
    
    return 0;
}

void displayRes(float n){
    cout << "Result: " << n << endl;
}
