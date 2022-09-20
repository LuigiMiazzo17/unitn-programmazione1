//
//  main.cpp
//  35-cp
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    if(argc != 3){
        cout << "Wrong usage!" << endl << "Example of good usage: ./35-cp <input.txt> <output.txt>" << endl;
        return -1;
    }
    
    fstream filein;
    fstream fileout;
    
    filein.open(argv[1], ios::in);
    fileout.open(argv[2], ios::out);
    
    if(filein.fail()){
        cout << "Error opening input file, check if file exists!" << endl;
        return -1;
    }
    if(fileout.fail()){
        cout << "Error opening output file, check if file exists!" << endl;
        return -1;
    }
    
    char buffer[256];
    filein >> buffer;
    while(!filein.eof()){
        fileout << buffer << ' ';
        filein >> buffer;
    }
    
    filein.close();
    fileout.close();
    
    return 0;
}
