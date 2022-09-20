//
//  iofile.cpp
//  utils02-inputOutputFile
//
//  Created by Luigi Miazzo on 21/02/22.
//

#include "iofile.hpp"
#include <iostream>
#include <fstream>

/*--------------------------------------------------------------------------getFromFile()

 ricordarsi di fare delete[] dell array passato "text"
 passare per parametro questo array e una variabile per indicare quante parole sono state lette
 
*/

bool getFromFile(const char fname[], char **& text, int& len){
    
    int MAX_WORD_SIZE = 256;     //MAX WORD SIZE
    
    if(!countWords(fname, len, MAX_WORD_SIZE))
        return false;
    
    std::fstream file;
    file.open(fname, std::ios::in);
    
    text = new char*[len];
    initCharArr(text, len, MAX_WORD_SIZE);
    
    file >> text[0];
    int c = 1;
    
    while(!file.eof())
        file >> text[c++];
    
    file.close();
    return true;
}

bool countWords(const char fname[], int & c, int maxWordSize){
    std::fstream file;
    file.open(fname, std::ios::in);
    
    if(file.fail()){
        std::cout << "Errore nell'apertura del file, controllare se il file esiste" << std::endl;
        file.close();
        return false;
    }
    char buff[maxWordSize];
    
    file >> buff;
    c = 1;
    while(!file.eof()){
        file >> buff;
        c++;
    }
    
    file.close();
    return true;
}

/*--------------------------------------------------------------------------getLinesFromFile()

 ricordarsi di fare delete[] dell array passato "lines"
 passare per parametro questo array e una variabile per indicare quante line sono state lette
 
*/

bool getLinesFromFile(const char fname[], char **& lines, int & len){
    
    int MAX_LINE_SIZE = 256; //MAX LINE SIZE
    
    if(!countLines(fname, len, MAX_LINE_SIZE))
        return false;
    
    std::fstream file;
    file.open(fname, std::ios::in);
    
    lines = new char*[len];
    initCharArr(lines, len, MAX_LINE_SIZE);
    
    file.getline(lines[0], MAX_LINE_SIZE);
    int c = 1;
    
    while(!file.eof())
        file.getline(lines[c++], MAX_LINE_SIZE);
    
    file.close();
    return true;
}

bool countLines(const char fname[], int & c, int maxLineSize){
    std::fstream file;
    file.open(fname, std::ios::in);
    
    if(file.fail()){
        std::cout << "Errore nell'apertura del file, controllare se il file esiste" << std::endl;
        file.close();
        return false;
    }
    char buff[maxLineSize];
    
    file.getline(buff, sizeof(buff));
    c = 1;
    while(!file.eof()){
        file.getline(buff, sizeof(buff));
        c++;
    }
    
    file.close();
    return true;
}

/*--------------------------------------------------------------------------outToFile()*/

bool outToFile(const char fname[], char ** dictionary, int len){
    std::fstream file;
    file.open(fname, std::ios::out); //std::ios_base::app per append
    
    if(file.fail()){
        std::cout << "Qualcosa e' andato storto nella scrittura!" << std::endl;
        file.close();
        return false;
    }
    
    for(int i = 0; i < len; i++)
        file << dictionary[i] << std::endl;
    
    file.close();
    return true;
}

/*----------------------------------------------------------------initCharArr

 inizializza gli array passati per parametro sotto forma di matrice
 
*/

void initCharArr(char* text[], int len, int size){
    for(int i = 0; i < len; i++)
        text[i] = new char[size];
}
