//
//  main.cpp
//  38-randomArrayDyn
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>

using namespace std;

int * genArr(int);
void printArr(int[], int);

int main(int argc, const char * argv[]) {
    
    int n = 0;
    
    cout << "Lunghezza array richiesto: ";
    cin >> n;
    
    int * arr;
    if((arr = genArr(n)) == NULL){
        cout << "Lunghezza non valida" << endl;
        return -1;
    }
    
    cout << "Array richiesto: ";
    printArr(arr, n);
    
    delete [] arr;
    
    return 0;
}


int * genArr(int len){
    if(len <= 0)
        return NULL;
    
    int * arr = new int[len];
    
    for(int i = 0; i < len; i++)
        arr[i] = rand() % 10;
    
    return arr;
}

void printArr(int arr[], int len){
    --len;
    for(int i = 0; i < len; i++)
        cout << arr[i] << ", ";
    cout << arr[len] << endl;
}
