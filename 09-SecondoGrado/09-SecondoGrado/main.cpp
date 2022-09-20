//
//  main.cpp
//  09-SecondoGrado
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    float a=0, b=0, c=0;
    
    cout << "Equazioni del tipo ax^2 + bx + c = 0" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    
    if (a == 0){
        cout << "Ma Shei Shtupidou?" << endl;
        return -1;
    }
    
    float det = b*b - 4*a*c;
    
    if (det > 0){
        cout << "Radici reali distinte," << endl;
        cout << "x1: " << (-b + sqrt(det))/(2*a) << endl;
        cout << "x2: " << (-b - sqrt(det))/(2*a) << endl;
    }
    else if (det == 0){
        cout << "Radici coincidenti, " << endl;
        cout << "x1,2: " << (-b)/(2*a) << endl;
    }
    else{
        cout << "Radici complesse distinte," << endl;
        cout << "z1: " << (-b)/(2*a) << " + " << "i" << sqrt(-det)/(2*a) << endl;
        cout << "z1: " << (-b)/(2*a) << " - " << "i" << sqrt(-det)/(2*a) << endl;
    }
        
    
    return 0;
}
