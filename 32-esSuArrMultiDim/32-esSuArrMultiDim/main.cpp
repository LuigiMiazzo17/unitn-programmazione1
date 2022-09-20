//
//  main.cpp
//  32-esSuArrMultiDim
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 3;

void genRndArr(int*, int);
void printArr(int[]);
void genRndMat(int[][DIM], int = 10);
void printMat(int[][DIM]);
void trasponiMat(int[][DIM]);
int countIsland(int[][DIM]);
bool isIsland(int[][DIM], int, int);
int sarrus(int[][DIM]);

int main(int argc, const char * argv[]) {
    
    srand((uint)time(NULL));
    
    int mat[DIM][DIM];
    
    cout << "Matrice: " << endl;
    
    genRndMat(mat);
    printMat(mat);
    
    cout << "Discriminante matrice: " << sarrus(mat) << endl;
    
    return 0;
}

void genRndMat(int mat[][DIM], int n){
    for(int i = 0; i < DIM; i++){
        genRndArr(*(mat + i), n);
    }
}

void printMat(int mat[][DIM]){
    for(int i = 0; i < DIM; i++){
        printArr(*(mat + i));
    }
}

void trasponiMat(int mat[][DIM]){
    int tmp = 0;
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            if(j-i > 0){
                tmp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = tmp;
            }
}

void genRndArr(int* arr, int n){
    for(int i = 0; i < DIM; i++){
        arr[i] = rand() % n;
    }
}

void printArr(int* arr){
    for(int i = 0; i < DIM - 1; i++)
        cout << *(arr + i) << ", ";
    cout << *(arr + DIM - 1) << endl;
}

int countIsland(int mat[][DIM]){
    int counter = 0;
    
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            if(mat[i][j] == 1)
                if(isIsland(mat, i, j))
                    ++counter;
    
    return counter;
}

bool isIsland(int mat[][DIM], int i, int j){
    for(int l = -1; l < 2; l++)
        for(int m = -1; m < 2; m++)
            if(l+i >= 0 && l+i < DIM && m+j >= 0 && m+j < DIM)
                if(l!=0 || m!=0)
                    if(mat[l+i][m+j] == 1)
                        return false;
        
    return true;
}

int sarrus(int mat[][DIM]){
    int det = 0;
    
    for(int i = 0; i < DIM; i++){
        int tmpProduct = 1;
        for(int j = 0; j < DIM; j++){
            tmpProduct *= mat[(i+j) % DIM][j];
        }
        det += tmpProduct;
    }
    
    for(int i = 0; i < DIM; i++){
        int tmpProduct = 1;
        for(int j = 0; j < DIM; j++){
            tmpProduct *= mat[((i-j) < 0 ? DIM + (i-j) : (i-j))][j];
        }
        det -= tmpProduct;
    }
    
    return det;
}
