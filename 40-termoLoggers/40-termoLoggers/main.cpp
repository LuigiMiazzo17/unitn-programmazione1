//
//  main.cpp
//  40-termoLoggers
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>
#include <fstream>

bool countData(const char[], int &);
float * retriveData(const char[], int &);
template <typename T>
void bubbleSort(T[], int);
template <typename T>
void swap(T &, T &);
template <typename T>
bool isSorted(T[], int);
float * getHighTemps(float *, int, int);
void displayTemps(float *, int);

//--------------------------------------------------------------------------------main()

int main(int argc, const char * argv[]) {
    
    if(argc != 3){
        std::cout << "Wrong number of parameters" << std::endl << "Usage: ./40-termoLogger <input.txt> <n>" << std::endl;
        return -1;
    }
    
    int nEle = 0;
    
    float * temps = retriveData(argv[1], nEle);
    bubbleSort(temps, nEle);
    
    float * highTemps = getHighTemps(temps, nEle, atoi(argv[2]));
    delete [] temps;

    displayTemps(highTemps, atoi(argv[2]));
    delete [] highTemps;
    
    return 0;
}

//--------------------------------------------------------------------------------DisplayTemps()

void displayTemps(float * temps, int len){
    --len;
    for(int i = 0; i < len; i++)
        std::cout << temps[i] << ", ";
    std::cout << temps[len] << std::endl;
    return;
}

//--------------------------------------------------------------------------------CountData()

bool countData(const char fname[], int & counter){
    std::fstream file;
    file.open(fname, std::ios::in);
    
    if(file.fail())
        return false;
    
    char buffer[256];
    
    file >> buffer;
    while(!file.eof()){
        counter++;
        file >> buffer;
    }
    
    file.close();
    
    return true;
}

//--------------------------------------------------------------------------------retriveData()

float * retriveData(const char fname[], int & nEle){
    if(!countData(fname, nEle)){
        std::cout << "Something went wrong!" << std::endl;
        return NULL;
    }
    float * arr = new float[nEle];
    
    std::fstream file;
    file.open(fname, std::ios::in);
    
    char buffer[256];
    int counter = 0;
    
    file >> buffer;
    while(!file.eof()){
        arr[counter] = atof(buffer);
        counter++;
        file >> buffer;
    }
    
    file.close();
    return arr;
}

//--------------------------------------------------------------------------------getHighTemps()

float * getHighTemps(float * temps, int len, int n){
    float * highTemps = new float[n];
    
    for(int i = 0; i < n; i++){
        highTemps[i] = temps[len - i - 1];
    }
    
    return highTemps;
}

//--------------------------------------------------------------------------------bubbleSort()

template <typename T>
void bubbleSort(T arr[], int len){
    while(!isSorted(arr, len)){
        for(int i = 0; i < len - 1; i++){
            if(arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
    }
    
    return;
}

//--------------------------------------------------------------------------------swap()

template <typename T>
void swap(T & a, T & b){
    T tmp = a;
    a = b;
    b = tmp;
    return;
}

//--------------------------------------------------------------------------------isSorted()

template <typename T>
bool isSorted(T arr[], int len){
    --len;
    for(int i = 0; i < len; i++)
        if(arr[i] > arr[i + 1])
            return false;
    return true;
}
