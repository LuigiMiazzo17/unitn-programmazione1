//
//  main.cpp
//  14-GiornoDellaSettimana
//
//  Created by Luigi Miazzo on 13/02/22.
//

#include <iostream>

using namespace std;

enum giorniDellaSettimana {Lunedi = 1, Martedi = 2, Mercoledi = 3, Giovedi = 4, Venerdi = 5, Sabato = 6, Domenica = 7};

void returnDay(char [], int );

int main(int argc, const char * argv[]) {
    
    cout << "Numero giorno: ";
    int g = 0;
    cin >> g;
    
    char res[10];
    
    returnDay(res, g);

    cout << "Il giorno della settimana è: " << res << endl;
    
    return 0;
}

void returnDay(char str[], int g){
    switch(g){
        case Lunedi:
            memcpy(str, "Lunedi", 10);
            return;
        case Martedi:
            memcpy(str, "Martedi", 10);
            return;
        case Mercoledi:
            memcpy(str, "Mercoledi", 10);
            return;
        case Giovedi:
            memcpy(str, "Giovedi", 10);
            return;
        case Venerdi:
            memcpy(str, "Venerdi", 10);
            return;
        case Sabato:
            memcpy(str, "Sabato", 10);
            return;
        case Domenica:
            memcpy(str, "Domenica", 10);
            return;
        default:
            memcpy(str, "Shtupido", 10);
            return;
    }
}
