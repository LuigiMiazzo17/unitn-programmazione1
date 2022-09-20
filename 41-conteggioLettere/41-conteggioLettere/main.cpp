//
//  main.cpp
//  41-conteggioLettere
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>
#include <fstream>

using namespace std;

bool getherInfoOnFile(const char[], int[]);
void displayLetArr(int[]);
void initArr(int[], int);

int main(int argc, const char * argv[]) {
    
    if(argc != 2){
        cout << "Wrong usage!" << endl <<"Example of good usage: ./41-conteggioLettere <input.txt>" << endl;
        return -1;
    }
    
    int letArr[26];
    initArr(letArr, 26);
    
    if(!getherInfoOnFile(argv[1], letArr)){
        cout << "Something went wrong!" << endl;
        return -1;
    }
    
    displayLetArr(letArr);
    
    return 0;
}

void displayLetArr(int letArr[]){
    for(char i = 'a'; i <= 'z'; i++){
        cout << i << ": " << letArr[i - 'a'] << endl;
    }
}

void initArr(int arr[], int len){
    for(int i = 0; i < len; i++)
        arr[i] = 0;
}

bool getherInfoOnFile(const char fname[], int letArr[]){
    
    fstream file;
    file.open(fname, ios::in);
    
    char buffer[256];
    
    file >> buffer;
    while(!file.eof()){
        for(int i = 0; i < 256; i++){
            char c = buffer[i];
            if(c >= 'a' && c <= 'z')
                c -= 'a';
            else if(c >= 'A' && c <= 'Z')
                c -= 'A';
            else if(c == '\0')
                break;
            else
                continue;
            letArr[c]++;
        }
        file >> buffer;
    }
    
    file.close();
    return true;
}
