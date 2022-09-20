//
//  main.cpp
//  51-mediaAsterischi
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>
#include <fstream>

using namespace std;

void mediaAsterischi(const char[]);
int strLen(const char[]);

int main(int argc, const char * argv[]) {
    
    mediaAsterischi("input.txt");
    
    return 0;
}

void mediaAsterischi(const char fname[]){
    fstream infile;
    infile.open(fname, ios::in);
    
    char buff[10];
    
    int counter = 0;
    int media = 0;
    infile >> buff;
    
    while(!infile.eof()){
        counter++;
        media += strLen(buff);
        infile >> buff;
    }
    
    infile.close();
    
    media = media/counter;
    char str[10];
    for(int i = 0; i < media; i++)
        str[i] = '*';
    str[media]  = '\0';
    
    infile.open(fname, std::ios_base::app);
    
    infile << str << endl;
    
    infile.close();
    return;
}

int strLen(const char str[]){
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}
