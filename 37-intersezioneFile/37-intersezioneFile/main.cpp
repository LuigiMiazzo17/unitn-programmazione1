//
//  main.cpp
//  37-intersezioneFile
//
//  Created by Luigi Miazzo on 18/02/22.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_WORD_IN_FILE = 1000;
const int MAX_WORD_SIZE = 100;

bool generateDictionary(const char[], char[MAX_WORD_IN_FILE][MAX_WORD_SIZE], int &);
bool parseSecondFile(const char[], char[MAX_WORD_IN_FILE][MAX_WORD_SIZE], char[MAX_WORD_IN_FILE][MAX_WORD_SIZE], int, int &);
bool isWordInDictionary(char[MAX_WORD_SIZE], char[MAX_WORD_IN_FILE][MAX_WORD_SIZE], int);
bool printDictionaryToFile(const char[], char[MAX_WORD_IN_FILE][MAX_WORD_SIZE], int);

int main(int argc, const char * argv[]) {
    
    if(argc != 4){
        cout << "Wrong usage!" << endl << "Correct usage: ./37-intersezioneFile <input1.txt> <input2.txt> <output.txt>" << endl;
        return -1;
    }
    
    char dictionary[MAX_WORD_IN_FILE][MAX_WORD_SIZE];
    int nWord = 0;
    
    if(!generateDictionary(argv[1], dictionary, nWord)){
        cout << "Something went wrong!" << endl;
        return -1;
    }
    
    char goodDictionary[MAX_WORD_IN_FILE][MAX_WORD_SIZE];
    int nGoodWord = 0;
    
    if(!parseSecondFile(argv[2], dictionary, goodDictionary, nWord, nGoodWord)){
        cout << "Something went wrong!" << endl;
        return -1;
    }
    
    if(!printDictionaryToFile(argv[3], goodDictionary, nGoodWord)){
        cout << "Something went wrong writing to file!" << endl;
        return -1;
    }
    
    cout << "All done!" << endl;
    
    return 0;
}

//-------------------------------------------------------------------------------------------------------generateDictionary()

bool generateDictionary(const char fname[], char dictionary[MAX_WORD_IN_FILE][MAX_WORD_SIZE], int & counter){
    
    fstream file;
    file.open(fname, ios::in);
    
    if(file.fail())
        return false;
    
    char buffer[MAX_WORD_SIZE];
    file >> buffer;
    while(!file.eof()){
        strcpy(dictionary[counter++], buffer);
        file >> buffer;
    }
    
    file.close();
    return true;
}

//-------------------------------------------------------------------------------------------------------parseSecondFile()

bool parseSecondFile(const char fname[], char dictionary[MAX_WORD_IN_FILE][MAX_WORD_SIZE], char goodDictionary[MAX_WORD_IN_FILE][MAX_WORD_SIZE], int nWord, int & counter){
    
    fstream file;
    file.open(fname, ios::in);
    
    if(file.fail())
        return false;
    
    char buffer[MAX_WORD_SIZE];
    file >> buffer;
    while(!file.eof()){
        if(isWordInDictionary(buffer, dictionary, nWord))
            if(!isWordInDictionary(buffer,goodDictionary, counter))
                strcpy(goodDictionary[counter++], buffer);
        file >> buffer;
    }
    
    file.close();
    return true;
}

//-------------------------------------------------------------------------------------------------------isWordInDictionary()

bool isWordInDictionary(char word[MAX_WORD_SIZE], char dictionary[MAX_WORD_IN_FILE][MAX_WORD_SIZE], int nWord){
    for(int i = 0; i < nWord; i++)
        if(strcmp(word, dictionary[i]) == 0)
            return true;
    return false;
}

//-------------------------------------------------------------------------------------------------------printDictionaryToFile()

bool printDictionaryToFile(const char fname[], char dictionary[MAX_WORD_IN_FILE][MAX_WORD_SIZE], int nGoodWord){
    
    fstream file;
    file.open(fname, ios::out);
    
    if(file.fail())
        return false;
    
    for(int i = 0; i < nGoodWord - 1; i++)
        file << dictionary[i] << " ";
    file << dictionary[nGoodWord - 1];
    
    file.close();
    return true;
}
