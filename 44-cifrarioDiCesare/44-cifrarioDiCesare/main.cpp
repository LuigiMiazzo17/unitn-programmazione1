//
//  main.cpp
//  44-cifrarioDiCesare
//
//  Created by Luigi Miazzo on 19/02/22.
//

#include <iostream>
#include <fstream>
#include "cifrarioDiCesare.h"

using namespace std;

void retriveData(const char[], char[], char[], int &, int);
void dumpData(const char[], const char[]);

int main(int argc, const char * argv[]) {
    
    cout << "Nome del file: ";
    char fname[16];
    cin >> fname;
    
    const int MAX_LEN = 256;
    
    char text[MAX_LEN];
    char outfile[16];
    int key;
    
    retriveData(fname, text, outfile, key, MAX_LEN);
    
    cout << "0.Cifra" << endl;
    cout << "1.Decifra" << endl;
    cout << "Scelta: ";
    bool s = false;
    cin >> s;
    
    char cText[MAX_LEN];
    if(s)
        decifra(cText, text, key , MAX_LEN);
    else
        cifra(cText, text, key, MAX_LEN);
    
    
    dumpData(outfile, cText);
    
    return 0;
}

void dumpData(const char fname[], const char text[]){
    fstream file;
    file.open(fname, ios::out);
    
    if(file.fail()){
        cout << "Something went wrong!" << endl;
        return;
    }
    
    file << text << endl;
    
    file.close();
    return;
}

void retriveData(const char fname[], char line[], char outfile[], int & key, int len){
    fstream file;
    file.open(fname, ios::in);
    
    if(file.fail()){
        cout << "Something went wrong!" << endl;
        return;
    }
    
    char buffer[len];
    
    file.getline(buffer, sizeof(buffer));
    strcpy(line, buffer);
    
    file.getline(buffer, sizeof(buffer));
    strcpy(outfile, buffer);
    
    file.getline(buffer, sizeof(buffer));
    key = atoi(buffer);
    
    file.close();
    return;
}
