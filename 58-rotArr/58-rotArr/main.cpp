//
//  main.cpp
//  58-rotArr
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>

using namespace std;

int DIM_ARR = 5;
void shift(char[], int);
void shiftR(char[], int, char, int = 0);

int main(int argc, const char * argv[]) {
    
    char arr[] = {'A', 'B', 'C', 'D', 'E', '\0'};
    
    int s = 3;
    
    shiftR(arr, s, arr[0]);
    
    cout << arr << endl;
    
    return 0;
}

void shift(char arr[], int shift){
    char tempC = arr[0];
    int pos = 0;
    for(int i = 0; i < DIM_ARR; i++){
        char tmp = arr[(pos + shift) % DIM_ARR];
        arr[(pos + shift) % DIM_ARR] = tempC;
        tempC = tmp;
        pos = (pos + shift) % DIM_ARR;
    }
}

void shiftR(char arr[], int shift, char tempC, int pos){
    if(shift % DIM_ARR == 0)
        return;
    if(pos == 0 && tempC != arr[0]){
        return;
    }
    char tmp = arr[(pos + shift) % DIM_ARR];
    arr[(pos + shift) % DIM_ARR] = tempC;
    tempC = tmp;
    pos = (pos + shift) % DIM_ARR;
    shiftR(arr, shift, tempC, pos);
}
