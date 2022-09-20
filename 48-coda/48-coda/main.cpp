//
//  main.cpp
//  48-coda
//
//  Created by Luigi Miazzo on 20/02/22.
//

#include <iostream>
#include <cstring>
#include "coda.hpp"

using namespace std;

int promptOptions();
void addQueue();
void removeQueue();
//
//int main(int argc, const char * argv[]) {
//
//    init();
//
//    while(true){
//        switch(promptOptions()){
//            case 1:
//                addQueue();
//                break;
//            case 2:
//                removeQueue();
//                break;
//            case 3:
//                print();
//                break;
//            case 0:
//                return 0;
//            default:
//                cout << "Input non valido!" << endl;
//                break;
//        }
//
//        cout << "-------------------------------" << endl;
//    }
//}


int main() {

    init();

    cout << "inserisci: " << endl;
    cout << "- 'rimuovi' per rimuovere una persona" << endl;
    cout << "- 'stampa' per vedere la coda" << endl;
    cout << "- 'esci' per terminare il programma" << endl;
    cout << "- un nome per aggiungere una persona " << endl;

    bool esci = false;
    char input[30];

    while (!esci) {
        
        cin >> input;

        if (strcmp(input, "rimuovi") == 0) {
            char * primo;
            if (first(primo)) {
                dequeue();
                cout << "abbiamo rimosso " << primo << endl;
                delete primo;
            } else {
                cout << "coda vuota" <<  endl;
            }
        }
        else if (strcmp(input, "stampa") == 0) {
            cout << "la coda contiene queste persone: " << endl;
            print();
        }
        else if (strcmp(input, "esci") == 0) {
            cout << "Uscita del programma" << endl;
            esci = true;
        }
        else {
            cout << "abbiamo inserito " << input << " nella coda" << endl;
            enqueue(input);
        }
    }

    deinit();

    return 0;
}

void addQueue(){
    cout << "Nome persona: ";
    char name[30];
    cin >> name;
    
    enqueue(name);
    cout << "Fatto!" << endl;
}

void removeQueue(){
    char * name;
    first(name);
    
    cout << "Persona rimossa: " << name << endl;
    dequeue();
    return;
}

int promptOptions(){
    int s = 0;
    
    cout    << "Alle poste!"            << endl
            << "1.Aggiungi persona"     << endl
            << "2.Rimuovi persona"      << endl
            << "3.Stampa situazione"    << endl
            << "0.Esci"                 << endl << endl
            << "Scelta: ";
    
    cin >> s;
    cout << endl;
    return s;
}
