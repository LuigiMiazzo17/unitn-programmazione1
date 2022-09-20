//
//  main.cpp
//  36-sostituisciLettera
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>
#include <fstream>

using namespace std;

void sostituisciLettera(char[], char, char);

const int BUFF_SIZE = 256;

int main(int argc, const char * argv[]) {
    
    if(argc != 3){
        cout << "Wrong usage!" << endl << "Example of good usage: ./36-sostituisciLettera <input.txt> <a> " << endl;
        return -1;
    }
    
    fstream filein;
    
    filein.open(argv[1], ios::in);
    
    if(filein.fail()){
        cout << "Error opening input file, check if file exists!" << endl;
        return -1;
    }
    
    char buffer[BUFF_SIZE];
    filein >> buffer;
    while(!filein.eof()){
        sostituisciLettera(buffer, argv[2][0], '?');
        cout << buffer << ' ';
        filein >> buffer;
    }
    
    cout << endl;
    filein.close();
    
    return 0;
}

void sostituisciLettera(char str[], char c, char s){
    for(int i = 0; i < BUFF_SIZE; i++)
        if(str[i] == c)
            str[i] = s;
            
}
