//
//  main.cpp
//  42-esse3
//
//  Created by Luigi Miazzo on 19/02/22.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_STUD = 100;

//---------------------------------------------------------------------------------------------------struct studente

struct studente{
    static const int lenNomCognome = 20;
    char nome[lenNomCognome];
    char cognome[lenNomCognome];
    int matricola;
    float media;
    
    void stampaStudente(){
        cout << "Nome: " << this->nome << endl;
        cout << "Cognome: " << this->cognome << endl;
        cout << "Matricola: " << this->matricola << endl;
        cout << "Media: " << this->media << endl;
        return;
    }
    
    static studente generaStudente(char nome[], char cognome[], int matricola, float media){
        studente s;
        strcpy(s.nome, nome);
        strcpy(s.cognome, cognome);
        s.matricola = matricola;
        s.media = media;
        return s;
    }
    
    static int cercaStudenteMatricola(studente * db, int lenDB, int matricola){
        for(int i = 0; i < lenDB; i++)
            if(db[i].matricola == matricola)
                return i;
        
        return -1;
    }
    
    static int cercaStudenteNomeCognome(studente * db, int lenDB, const char nome[], const char cognome[]){
        for(int i = 0; i < lenDB; i++)
            if(strcmp(db[i].nome, nome) == 0 && strcmp(db[i].cognome, cognome) == 0)
                return i;
        
        return -1;
    }
};

//---------------------------------------------------------------------------------------------------function delcarations

bool countLines(const char[], int &);
int findSpace(const char[], int len);
studente * importData(const char[], int&);
void strCpy(char[], const char[], int, int);
void subStr(char[], int, int);
int promptOptions();
void addUsr(studente *, int &);
void ricercaStudente(studente *, int);
void caricaStudenti(studente *, int &);
void dbCpy(studente *, int, studente *, int);
void studenteMaxMedia(studente *, int);

//---------------------------------------------------------------------------------------------------int main(int, const char *)

int main(int argc, const char * argv[]){
    
    studente db[MAX_STUD];
    
    int counter = 0;
    
    while(true){
        switch(promptOptions()){
            case 0:
                return 0;
            case 1:
                addUsr(db, counter);
                break;
            case 2:
                ricercaStudente(db, counter);
                break;
            case 3:
                studenteMaxMedia(db, counter);
                break;
            case 4:
                caricaStudenti(db, counter);
                break;
            default:
                cout << "Input non valido!" << endl;
                break;
        }
        cout << "----------------------------------------------------";
        cout << endl << endl;
    }
    
    return 0;
}

//---------------------------------------------------------------------------------------------------void studenteMaxMedia(studente *, int)

void studenteMaxMedia(studente * db, int counter){
    
    if(counter == 0){
        cout << "Nessun utente nel sistema!" << endl;
        return;
    }
    
    studente max;
    max = db[0];
    
    for(int i = 1; i < counter; i++)
        if(max.media < db[i].media)
            max = db[i];
    
    cout << "Studente con media piu' alta:" << endl;
    max.stampaStudente();
    return;
}

//---------------------------------------------------------------------------------------------------void caricaStudenti(int)

void caricaStudenti(studente * db, int & nStud){
    char fname[32];
    cout << "Nome del file: ";
    cin >> fname;
    
    int newStud = 0;
    
    studente * newDB = importData(fname, newStud);
    
    if(newDB == NULL)
        return;
    
    
    if(newStud + nStud > MAX_STUD){
        cout << "Il numero di studenti che è stato inserito supera il limite, nessun cambiamento è stato effettuato!" << endl;
        return;
    }
    dbCpy(db, nStud, newDB, newStud);
    nStud += newStud;
    
    cout << "Eseguito!";
}

//---------------------------------------------------------------------------------------------------void ricercaStudente()

void dbCpy(studente * db, int index, studente * newDB, int len){
    
    for(int i = index; i < len; i++)
        db[i] = newDB[i - index];
    
}

//---------------------------------------------------------------------------------------------------void ricercaStudente()

void ricercaStudente(studente * db, int counter){
    cout    << "0.Per nome e cognome"   << endl
            << "1.Per matricola"        << endl << endl
            << "Scelta: ";
    bool scelta = false;
    cin >> scelta;
    
    if(scelta){ //true: per matricola
        cout << endl << "Numero matricola: ";
        int matricola;
        cin >> matricola;
        
        int index = studente::cercaStudenteMatricola(db, counter, matricola);
        
        if(index >= 0 && index < counter){
            cout << endl << "Utente richiesto: " << endl;
            db[index].stampaStudente();
        }
        else
        {
            cout << "Utente non trovato!" << endl;
        }
        
    }
    else{       //false: per nome e cognome
        char nome[studente::lenNomCognome];
        char cognome[studente::lenNomCognome];
        cout << endl << "Nome: ";
        cin >> nome;
        cout << "Cognome: ";
        cin >> cognome;
        
        int index = studente::cercaStudenteNomeCognome(db, counter, nome, cognome);
        
        if(index >= 0 && index < counter){
            cout << endl << "Utente richiesto: " << endl;
            db[index].stampaStudente();
        }
        else
        {
            cout << "Utente non trovato!" << endl;
        }
    }
}

//---------------------------------------------------------------------------------------------------studente addUsr()

void addUsr(studente * db, int & counter){
    if(counter >= 99){
        cout << "Numero massimo di utenti raggiunto" << endl;
        return;
    }
    char nome[studente::lenNomCognome];
    char cognome[studente::lenNomCognome];
    int matricola;
    float media;
    
    cout << "Nome: ";
    cin >> nome;
    cout << "Cognome: ";
    cin >> cognome;
    cout << "Matricola: ";
    cin >> matricola;
    cout << "Media: ";
    cin >> media;
    
    
    db[counter] = studente::generaStudente(nome, cognome, matricola, media);
    counter++;
    cout << endl << "Utente aggiunto!" << endl;
    return;
}

//---------------------------------------------------------------------------------------------------int promptOptions()

int promptOptions(){
    cout    << "1.Aggiungi utente al sistema"   << endl
            << "2.Funzioni cerca utente"        << endl
            << "3.Utente con media piu' alta"   << endl
            << "4.Carica utenti da file"        << endl
            << "0.Esci"                         << endl << endl
            << "Scelta: ";
    
    int scelta = 0;
    cin >> scelta;
    cout << endl;
    return scelta;
}

//---------------------------------------------------------------------------------------------------studente * importData(const char[], int&)

studente * importData(const char fname[], int & nLines){
    if(!countLines(fname, nLines)){
        nLines = -1;
        return NULL;
    }
    
    fstream file;
    file.open(fname, ios::in);
    
    if(file.fail()){
        cout << "Something went wrong!" << endl;
        return NULL;
    }
    
    studente * db = new studente[nLines];
    
    int BUFF_SIZE = 52;
    
    char line[BUFF_SIZE];
    int counter = 0;
    
    file.getline(line, sizeof(line));
    while(!file.eof()){
        int index = 0;
        char nome[studente::lenNomCognome];
        char cognome[studente::lenNomCognome];
        int matricola;
        float media;

        index = findSpace(line, studente::lenNomCognome);
        strCpy(nome, line, 0, index);
        subStr(line, index + 1, BUFF_SIZE);

        index = findSpace(line, studente::lenNomCognome);
        strCpy(cognome, line, 0, index);
        subStr(line, index + 1, BUFF_SIZE);
        
        index = findSpace(line, studente::lenNomCognome);
        char matString[5];
        strCpy(matString, line, 0, index);
        matricola = atoi(matString);
        subStr(line, index + 1, BUFF_SIZE);
        
        media = atof(line);
        
        db[counter] = studente::generaStudente(nome, cognome, matricola, media);
        
        file.getline(line, sizeof(line));
        counter++;
        
    }
    
    file.close();
    return db;
}

//---------------------------------------------------------------------------------------------------int findSpace(const char[], int len)

int findSpace(const char line[], int len){
    for(int i = 0; i < len; i++)
        if(line[i] == ' ')
            return i;
    return -1;
}

//---------------------------------------------------------------------------------------------------void strCpy(char[], const char[], int, int)

void strCpy(char toStr[], const char fromStr[], int from, int to){
    for(int i = from; i < to; i++)
        toStr[i - from] = fromStr[i];
    toStr[to] = '\0';
}

//---------------------------------------------------------------------------------------------------void strCpy(char[], int, int)

void subStr(char str[], int from, int len){
    strCpy(str, str, from, len);
    
    for(int i = len - from; i < len; i++)
        str[i] = NULL;
}

//---------------------------------------------------------------------------------------------------bool countLines(const char[], int &)

bool countLines(const char fname[], int & counter){
    counter = 0;
    
    fstream file;
    file.open(fname, ios::in);
    
    if(file.fail()){
        cout << "Something went wrong!" << endl;
        return false;
    }
    
    char buffer[52];
    
    file.getline(buffer, sizeof(buffer));
    
    while(!file.eof()){
        counter++;
        file.getline(buffer, sizeof(buffer));
    }
    
    file.close();
    return true;
}

