// Inserisci qui il codice

#include <iostream>
#include <fstream>
#include <cstring>

bool countWords(const char fname[], int & c, int maxWordSize);  //conta le parole nel file di input
void initCharArr(char* text[], int len, int size);              //crea un array di array dinamici
bool getWordsFromFile(const char fname[], char **& text, int& len); //mette le parole in un array di array dinamici
bool outToFile(const char fname[], char ** validWords, int occurrence[], int len);   //stampa su file le parole e la loro occorrenza
void deleteCharArr(char* text[], int len);          //elimina l'array di array dinamici
bool isValidWord(char * str);                       //controlla che la parola sia valida
int isIn(char * validWords[], char str[], int counter); //controlla se la parola è gia presente nell array di parole valide

using namespace std;

int main(int argc, const char * argv[]) {
    
    if(argc != 3){
        cout << "Numero di parametri errato!" << endl;
        cout << "Utilizzo corretto: ./a.out <input.txt> <output.txt>" << endl;
        return -1;
    }

    char ** words;
    int len = 0;
    if(!getWordsFromFile(argv[1], words, len)){
        return -1;
    }

    char *validWords[len];
    int occurence[len];
    int nValidWords = 0;

    for(int i = 0; i < len; i++){
        if(isValidWord(words[i])){
            int pos = isIn(validWords, words[i], nValidWords);
            if(pos == -1){
                validWords[nValidWords] = words[i];
                occurence[nValidWords] = 1;
                nValidWords++;
            }
            else
                occurence[pos]++;
        }
    }

    outToFile(argv[2], validWords, occurence, nValidWords);

    deleteCharArr(words, len);
    delete[] words;
    return 0;
}

int isIn(char * validWords[], char str[], int counter){
    for(int i = 0; i < counter; i++){
        if(strcmp(validWords[i], str) == 0)
            return i;
    }
    return -1;
}

bool isValidWord(char * str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return false;
    }
    return true;
}

bool getWordsFromFile(const char fname[], char **& text, int& len){
    
    int MAX_WORD_SIZE = 101;     //MAX WORD SIZE
    
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
    fstream file;
    file.open(fname, ios::in);
    
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

bool outToFile(const char fname[], char ** validWords, int occurrence[], int len){
    fstream file;
    file.open(fname, ios::out);
    
    if(file.fail()){
        cout << "Qualcosa e' andato storto nella scrittura!" << endl;
        file.close();
        return false;
    }
    
    for(int i = 0; i < len; i++)
        file << validWords[i] << ": " << occurrence[i] << endl;
    
    file.close();
    return true;
}

void initCharArr(char* text[], int len, int size){
    for(int i = 0; i < len; i++)
        text[i] = new char[size];
}

void deleteCharArr(char* text[], int len){
    for(int i = 0; i < len; i++)
        delete[] text[i];
}