//
//  main.cpp
//  utils02-inputOutputFile
//
//  Created by Luigi Miazzo on 21/02/22.
//

#include <iostream>
#include "iofile.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    char ** lines;
    int len = 0;
    getLinesFromFile("input.txt", lines, len);
    
    for(int i = 0; i < len - 1; i++)
        cout << "line " << i << ": " << lines[i] << endl;
    
    cout << endl;
    
    outToFile("output.txt", lines, len);
    
    delete[] lines;
    
    len = 0;
    
    getFromFile("input.txt", lines, len);
    
    for(int i = 0; i < len - 1; i++)
        cout << "word " << i << ": " << lines[i] << endl;
    
    cout << endl;
    
    delete[] lines;
    return 0;
}

