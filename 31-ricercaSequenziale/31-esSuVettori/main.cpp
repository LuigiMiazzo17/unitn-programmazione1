//
//  main.cpp
//  31-ricercaSequenziale
//
//  Created by Luigi Miazzo on 17/02/22.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int ricercaSequenziale(int[], int, int);
void genArr(int[], int);
void stampaArr(int[], int);
int uguaglianzaArr(int[], int[], int);
float mediaArr(int[], int);
int minArr(int[], int);
int maxArr(int[], int);
void invertiArr(int[], int);
void inserisciElemento(int[], int, int, int);
void bubbleSort(int[], int);
bool isSorted(int[], int);
void swap(int&, int&);
void eliminaDuplicati(int[], int);
bool isIn(int[], int, int);
void initArr(int[], int, int);
int ricercaBinaria(int[] , int, int = 0, int = 0);
void mergeArr(int[], int[], int, int[], int);

int main(int argc, const char * argv[]) {
    
    int DIM = 10;
    
    int arr1[DIM];
    int arr2[DIM];
    
    srand((uint)time(NULL));
    genArr(arr1, DIM);
    genArr(arr2, DIM);
    
    stampaArr(arr1, DIM);
    stampaArr(arr2, DIM);

    cout << "Numero di elementi uguali: " << uguaglianzaArr(arr1, arr2, DIM) << endl;

    cout << "Media elementi arr1: " << mediaArr(arr1, DIM) << endl;
    cout << "Minimo arr1: " << minArr(arr1, DIM) << endl;
    cout << "Massimo arr1: " << maxArr(arr1, DIM) << endl;
    
    cout << "arr1 invertito: " << endl;
    
    invertiArr(arr1, DIM);
    stampaArr(arr1, DIM);
    
    cout << "arr1 con elemento inserito: " << endl;
    
    inserisciElemento(arr1, 12, 2, DIM);
    stampaArr(arr1, DIM);
    
    cout << "arr1 ordinato: " << endl;
    
    bubbleSort(arr1, DIM);
    stampaArr(arr1, DIM);
    
    cout << "arr1 senza doppioni: " << endl;
    
    eliminaDuplicati(arr1, DIM);
    stampaArr(arr1, DIM);
    
    cout << "arr2 ordinato: " << endl;
    
    bubbleSort(arr2, DIM);
    stampaArr(arr2, DIM);
  
    
    int n = 3;

    int index = ricercaSequenziale(arr2, n, DIM);

    cout << "Ricerca sequenziale: " << endl;
    
    if(index == -1)
        cout << "Nessuna occorrenza di " << n << " nell'array!" << endl;
    else
        cout << "Prima occorenza di " << n << ": " << index + 1 << endl;
    
    index = ricercaBinaria(arr2, n, 0, DIM);

    cout << "Ricerca binaria: " << endl;
    
    if(index == -1)
        cout << "Nessuna occorrenza di " << n << " nell'array!" << endl;
    else
        cout << "Prima occorenza di " << n << ": " << index + 1 << endl;
    
    int arr3[DIM];
    int arr4[DIM];
    
    genArr(arr3, DIM);
    genArr(arr4, DIM);
    
    bubbleSort(arr3, DIM);
    bubbleSort(arr4, DIM);
    
    int arr5[DIM*2];
    
    mergeArr(arr5, arr3, DIM, arr4, DIM);
    
    cout << "arr3 ordinato: " << endl;
    stampaArr(arr3, DIM);
    cout << "arr4 ordinato: " << endl;
    stampaArr(arr4, DIM);
    
    cout << "arr 5:" << endl;
    stampaArr(arr5, DIM*2);
    
    return 0;
}

void genArr(int arr[], int len){
    
    for(int i = 0; i < len; i++){
        arr[i] = rand() % 10;
    }
}

int ricercaSequenziale(int arr[], int n, int len){
    for(int i = 0; i < len; i++)
        if(arr[i] == n)
            return i;
    
    return -1;
}

void stampaArr(int arr[], int len){
    cout << "Array richiesto: ";
    --len;
    for(int i = 0; i < len; i++)
        cout << arr[i] << ", ";
    cout << arr[len] << endl;
}

int uguaglianzaArr(int arr1[], int arr2[], int len){
    
    int counter = 0;
    for(int i = 0; i < len; i++)
        if(arr1[i] == arr2[i])
            ++counter;
    
    return counter;
}

float mediaArr(int arr[], int len){
    int sum = 0;
    for(int i = 0; i < len; i++)
        sum += arr[i];
    
    return sum/(float)len;
}

int minArr(int arr[], int len){
    int min = INT_MAX;
    for(int i = 0; i < len; i++)
        if(min > arr[i])
            min = arr[i];
    return min;
}

int maxArr(int arr[], int len){
    int min = INT_MIN;
    for(int i = 0; i < len; i++)
        if(min < arr[i])
            min = arr[i];
    return min;
}

void invertiArr(int arr[], int len){
    int tmp = 0;
    --len;
    for (int i = 0; i < (len + 1)/2; i++){
        tmp = arr[i];
        arr[i] = arr[len - i];
        arr[len - i] = tmp;
    }
    
    return;
}

void inserisciElemento(int arr[], int n, int index, int len){
    int tmp = 0;
    for(int i = index; i < len; i++){
        tmp = arr[i];
        arr[i] = n;
        n = tmp;
    }
    
    return;
}

void bubbleSort(int arr[], int len){
    
    while(!isSorted(arr, len)){
        for(int i = 0; i < len - 1; i++){
            if(arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
    }
    
    return;
}

bool isSorted(int arr[], int len){
    --len;
    for(int i = 0; i < len; i++)
        if(arr[i] > arr[i + 1])
            return false;
    return true;
}

void swap(int & a, int & b){
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

void eliminaDuplicati(int arr[], int len){
    
    int elementi[len];
    initArr(elementi, NULL, len);
    
    for(int i = 0; i < len - 1; i++){
        if(isIn(elementi, arr[i], len))
            arr[i] = -1;
        else
            inserisciElemento(elementi, arr[i], i, len);
    }
    
    return;
}

bool isIn(int arr[], int n, int len){
    --len;
    for(int i = 0; i < len; i++)
        if(n == arr[i])
            return true;
    
    return false;
}

void initArr(int arr[], int n, int len){
    --len;
    for(int i = 0; i < len; i++)
        arr[i] = n;
    return;
}

int ricercaBinaria(int arr[], int n, int ini, int fine){
    if(arr[(fine + ini) / 2] == n)
        return ini + ((fine - ini)/2);
    if(fine == ini)
        return -1;
    if(n < arr[(fine + ini) / 2])
        return ricercaBinaria(arr, n, ini, ((fine + ini) / 2) - 1);
    else if (n > arr[(fine + ini) / 2])
        return ricercaBinaria(arr, n, ((fine + ini) / 2) + 1, fine);
    return -1;
}

void mergeArr(int res[], int arr1[], int len1, int arr2[], int len2){
    int lenRes = len1 + len2;
    
    int i = 0;
    int j = 0;
    for(int k = 0; k < lenRes; k++){
        if((i != len1) && (arr1[i] < arr2[j] || j == len2)){
            res[k] = arr1[i];
            i++;
        }
        else{
            res[k] = arr2[j];
            j++;
        }
    }
    
    return;
}
