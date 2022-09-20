//
//  main.cpp
//  57-subMatrix
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int ** genMat(int, int);
int * genArr(int);
void printSubMatrix(int **, int, int, int, int);

int main(int argc, const char * argv[]) {

    int r = 0;
    int c = 0;
    
    cout << "Righe: ";
    cin >> r;
    cout << "Colonne: ";
    cin >> c;
    
    srand((uint)time(NULL));
    int ** mat = genMat(r, c);

    printSubMatrix(mat, 0, 0, r, c);
    printSubMatrix(mat, 10, 10, 15, 15);
    
    delete[] mat;
    return 0;
}

void printSubMatrix(int ** mat, int r, int c, int lenR, int lenC){
    for(int i = r; i < lenR; i++){
        for(int j = c; j < lenC - 1; j++)
            cout << mat[i][j] << ", ";
        cout << mat[i][lenC - 1] << endl;
    }
}

int ** genMat(int r, int c){
    int ** mat = new int*[r];
    for(int i = 0; i < r; i++)
        mat[i] = genArr(c);
    return mat;
}

int * genArr(int n){
    int * arr = new int[n];
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 10;
    return arr;
}
