//
//  main.cpp
//  47-pila
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>
#include <fstream>
#include "pila.hpp"

using namespace std;

void retriveData(const char[]);
void dumpData(const char[]);
bool isValidSentence(const char[]);

int main(int argc, const char * argv[]) {
    
    init();
    
    char text[] = "()()(()()()(()()))";
    
    if(isValidSentence(text))
        cout << "OK!" << endl;
    else
        cout << "No!" << endl;
    
    
//    retriveData("input.txt");
//    dumpData("output.txt");
    
    deinit();
    
    return 0;
}

void retriveData(const char fname[]){
    fstream infile;
    infile.open(fname, ios::in);
    
    if(infile.fail()){
        cout << "Something went wrong!" << endl;
        return;
    }
    
    int buff;
    while(infile >> buff){
        push(buff);
    }
    
    infile.close();
    return;
}

void dumpData(const char fname[]){
    fstream outfile;
    outfile.open(fname, ios::out);
    
    if(outfile.fail()){
        cout << "Something went wrong!" << endl;
        return;
    }
    
    int buff;
    top(buff);
    while(pop()){
        outfile << buff << endl;
        top(buff);
    }
    
    outfile.close();
    return;
}

bool isValidSentence(const char text[]){
    
    int counter = 0;
    char currChar = text[counter++];
    
    while(currChar != '\0'){
        if(currChar == '('){
            push(currChar);
        }
        else if(currChar == ')'){
            int tmp;
            if(top(tmp) == false)
                return false;
            if(tmp == '(')
                pop();
            else
                return false;
        }
        else
            return false;
        currChar = text[counter++];
    }
    
    if(pop() == false)
        return true;
    
    return false;
}
