//
//  main.cpp
//  21-basicSort
//
//  Created by Luigi Miazzo on 16/02/22.
//

#include <iostream>

using namespace std;

void sort(int &, int &, int &);

int main(int argc, const char * argv[]) {
    
    int n1, n2, n3;
    
    cout << "Inserisci i 3 numeri " << endl << "n1: ";
    cin >> n1;
    cout << "n2: ";
    cin >> n2;
    cout << "n3: ";
    cin >> n3;
    
    sort(n1, n2, n3);
    
    cout << endl << "Risultato:" << endl << "n1: " << n1 << "; n2: " << n2 << "; n3: " << n3 << endl;
    return 0;
}

void sort(int & n1, int & n2, int & n3){
    
    if(n1 > n2){
        int t = n1;
        n1 = n2;
        n2 = t;
    }
    if(n2 > n3){
        int t = n2;
        n2 = n3;
        n3 = t;
    }
    if(n1 > n2){
        int t = n1;
        n1 = n2;
        n2 = t;
    }
    
    return;
}
