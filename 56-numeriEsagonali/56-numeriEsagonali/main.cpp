//
//  main.cpp
//  56-numeriEsagonali
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>

using namespace std;

void printEsagonal(int *, int, int);

int main(int argc, const char * argv[]) {
    
    int n = 0;
    
    cout << "Lunghezza: ";
    cin >> n;
    
    if (n <= 0){
        cout << "Lunghezza non valida!" << endl;
        return -1;
    }
    
    int * arr = new int[n];
    
    printEsagonal(arr, 0, n);
    cout << endl;
    
    delete [] arr;
    return 0;
}

void printEsagonal(int * arr, int s, int n){
    if(s == n)
        return;
    arr[s] = s*((s * 2) - 1);
    cout << arr[s] << " ";
    printEsagonal(arr, s + 1, n);
    return;
}
