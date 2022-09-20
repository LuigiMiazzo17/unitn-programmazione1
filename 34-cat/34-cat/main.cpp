//
//  main.cpp
//  34-cat
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    if(argc != 2){
        cout << "Wrong usage!" << endl << "Example of good usage: ./34-cat <input.txt>" << endl;
        return -1;
    }
    
    fstream file;
    
    file.open(argv[1], ios::in);
    
    if(file.fail()){
        cout << "Error opening file, check if file exists!" << endl;
        return -1;
    }
    
    char buffer[256];
    file >> buffer;
    while(!file.eof()){
        cout << buffer << endl;
        file >> buffer;
    }
    
    file.close();
    
    return 0;
}
