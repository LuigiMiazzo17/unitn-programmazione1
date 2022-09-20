//
//  main.cpp
//  53-albero
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>
#include <fstream>
#include "tree.hpp"

using namespace std;

bool importData(const char[], tree&);

int main(int argc, const char * argv[]) {

    tree t = tree::createNewTree();
    
    if(!importData("input.txt", t)){
        t.deleteTree();
        cout << "Something went wrong!" << endl;
        return -1;
    }
    
    t.deleteTree();
    return 0;
}

bool importData(const char fname[], tree &t){
    
    fstream file;
    file.open(fname, ios::in);
    
    if(file.fail()){
        file.close();
        return false;
    }
        
    int buff;
    file >> buff;
    
    while(!file.eof()){
        t.insert(buff);
        file >> buff;
    }
    
    file.close();
    return true;
}
