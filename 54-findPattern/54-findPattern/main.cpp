//
//  main.cpp
//  54-findPattern
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void genArr(int[], int);
void printArr(const int[], int);
bool checkPattern(int[], int, int[], int);

int main(int argc, const char * argv[]) {

    srand((uint)time(NULL));
    
    int pat[3];
    int text[25];
    
    genArr(pat, 3);
    genArr(text, 25);
    
    printArr(pat, 3);
    printArr(text, 25);
    
    if(checkPattern(pat, 3, text, 25))
        cout << "OK!";
    else
        cout << "No!";
    
    cout << endl;
    
    return 0;
}

void genArr(int arr[], int len){
    for(int i = 0; i < len; i++)
        arr[i] = rand() % 10;
}

void printArr(const int arr[], int len){
    --len;
    for(int i = 0; i < len; i++)
        cout << arr[i] << ", ";
    cout << arr[len] << endl;
}

bool checkPattern(int patt[], int lenPatt, int text[], int lenText){
    
    int counter = 0;
    
    for(int i = 0; i < lenText; i++){
        if(text[i] == patt[counter]){
            counter++;
            if(counter == lenPatt)
                return true;
        }
        else
            counter = 0;
    }
    
    return false;
}
