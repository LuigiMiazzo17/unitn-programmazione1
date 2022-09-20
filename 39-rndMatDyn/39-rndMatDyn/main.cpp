//
//  main.cpp
//  39-rndMatDyn
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>

using namespace std;

int * genArr(int);
int ** genMat(int, int);
void printMat(int **, int, int);
void printArr(int*, int);

int main(int argc, const char * argv[]) {
    
    int r, c;
    
    cout << "Numero di righe: ";
    cin >> r;
    cout << "Numero di colonne: ";
    cin >> c;
    
    int ** mat;
    if((mat = genMat(r, c)) == NULL){
        cout << "Dimensioni non valide" << endl;
        return -1;
    }
    
    printMat(mat, r, c);
    
    delete [] mat;
    
    return 0;
}

int ** genMat(int r, int c){
    if(r <= 0 || c <= 0)
        return NULL;
    
    int ** mat = new int*[r];
    
    for(int i = 0; i < r; i++){
        *(mat + i) = genArr(c);
    }
    
    return mat;
}

int * genArr(int len){
    if(len <= 0)
        return NULL;
    
    int * arr = new int[len];
    
    for(int i = 0; i < len; i++)
        arr[i] = rand() % 10;
    
    return arr;
}

void printArr(int* arr, int n){
    for(int i = 0; i < n - 1; i++)
        cout << *(arr + i) << ", ";
    cout << *(arr + n - 1) << endl;
}

void printMat(int ** mat, int r, int c){
    for(int i = 0; i < r; i++){
        printArr(*(mat + i), c);
    }
}
