//
//  main.cpp
//  55-CorreggiSintassi
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>
#include <fstream>

using namespace std;

bool correctSintax(const char[], const char[]);
void toCap(char &);
int strFindNext(const char[], int);
int strLen(const char[]);
bool nextCharIsCap(char[], int, int);

int main(int argc, const char * argv[]) {
    
    if(argc != 3){
        cout << "Invalid usage!" << endl;
        cout << "Correct usage: ./* <input.txt> <output.txt>" << endl;
        return -1;
    }

    if(!correctSintax(argv[1], argv[2])){
        cout << "Something went wrong!" << endl;
        return -1;
    }
    
    return 0;
}

bool correctSintax(const char inFname[], const char outFname[]){
    fstream filein, fileout;
    filein.open(inFname, ios::in);
    fileout.open(outFname, ios::out);
    
    if(filein.fail() || fileout.fail()){
        fileout.close();
        filein.close();
        return false;
    }
    
    char buff[256];
    int nextDot = -1;
    
    filein.getline(buff, sizeof(buff));
    
    int len = strLen(buff);
    nextCharIsCap(buff, 0, len);
    
    bool nextLineRequireCap = false;
    
    while(!filein.eof()){
        while(!nextLineRequireCap && (nextDot = strFindNext(buff, (nextDot == -1 ? 0 : nextDot + 1))) != -1 )
            nextLineRequireCap = !nextCharIsCap(buff, nextDot, len);
        
        fileout << buff << endl;
        filein.getline(buff, sizeof(buff));
        len = strLen(buff);
        if(nextLineRequireCap){
            nextCharIsCap(buff, 0, len);
            nextLineRequireCap = false;
        }
        nextDot = -1;
    }
    
    
    
    fileout.close();
    filein.close();
    return true;
}

bool nextCharIsCap(char str[], int s, int len){
    for(int i = s; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            return true;
        else if(str[i] >= 'a' && str[i] <= 'z'){
            toCap(str[i]);
            return true;
        }
    }
    
    return false;
}

void toCap(char &c){
    if(c >= 'a' && c <= 'z')
         c -= 32;
}

int strFindNext(const char str[], int f){
    int len = strLen(str);
    for(int i = f; i < len; i++){
        if(str[i] == '.' || str[i] == '?' || str[i] == '!')
            return i;
    }
    return -1;
}

int strLen(const char str[]){
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}
