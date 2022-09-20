//
//  main.cpp
//  20-MaxMin
//
//  Created by Luigi Miazzo on 16/02/22.
//

#include <iostream>
#include <climits>

using namespace std;

void max(int *, int, int = INT_MIN, int = INT_MIN, int = INT_MIN, int = INT_MIN);
void min(int *, int, int = INT_MAX, int = INT_MAX, int = INT_MAX, int = INT_MAX);
bool askMinMax();
bool askNumbers(int[]);
void displayNumero(int);
void errore();

int main(int argc, const char * argv[]) {
    
    int res, arr[5];
    
    if(askNumbers(arr)){
        if(askMinMax())
            max(&res, arr[0], arr[1], arr[2], arr[3], arr[4]);
        else
            min(&res, arr[0], arr[1], arr[2], arr[3], arr[4]);
    }
    else
        errore();
    
    return 0;
}

bool askMinMax(){ //true = max, false = min
    
    cout << endl << "Minimo o massimo?" << endl << "0.Min" << endl << "1.Max" << endl << "Scelta: ";
    bool s = true;
    cin >> s;
    
    return s;
}

void displayNumero(int r){
    cout << endl << "Risultato: " << r << endl;
    return;
}

void errore(){
    cout << "Ma Shei Shtupidou?" << endl;
    return;
}

bool askNumbers(int arr[]){
    
    cout << "Calcolatore Min Max" << endl << endl << "Quanti numeri vuoi inserire (da 1 a 5): ";
    int s = 0;
    cin >> s;
    
    if (s >= 1 && s <= 5){
        for(int i = 1; i <= s; i++){
            cout << "n" << i << ": ";
            cin >> arr[i-1];
        }
        return true;
    }
    
    return false;
}

void min(int * res, int n1, int n2, int n3, int n4, int n5){
    
    *res = n1;
    
    if(*res > n2)
        *res = n2;
    if (*res > n3)
        *res = n3;
    if(*res > n4)
        *res = n4;
    if(*res > n5)
        *res = n5;
    
    displayNumero(*res);
    
    return;
}

void max(int * res, int n1, int n2, int n3, int n4, int n5){
    
    *res = n1;
    
    if(*res < n2)
        *res = n2;
    if (*res < n3)
        *res = n3;
    if(*res < n4)
        *res = n4;
    if(*res < n5)
        *res = n5;
    
    displayNumero(*res);
    
    return;
}
