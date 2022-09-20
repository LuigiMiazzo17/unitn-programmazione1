//
//  main.cpp
//  27-stampaCaratteri
//
//  Created by Luigi Miazzo on 17/02/22.
//

#include <iostream>

using namespace std;

void stampaCaratteri(char, char);

int main(int argc, const char * argv[]) {
    
    stampaCaratteri('a', 'A');
    cout << endl;
    
    return 0;
}

void stampaCaratteri(char c1, char c2){
    if(c1 >= c2){
        cout << c1;
        return;
    }
    cout << c1 << ',';
    stampaCaratteri(c1 + 1, c2);
}
