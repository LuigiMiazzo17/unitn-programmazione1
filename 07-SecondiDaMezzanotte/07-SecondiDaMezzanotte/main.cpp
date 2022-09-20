//
//  main.cpp
//  07-SecondiDaMezzanotte
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

int SecondiDaMezzanotte();
int MezzanotteDaSecondi();

int main(int argc, const char * argv[]) {
    
    cout << "0-SecondiDaMezzanotte" << endl;
    cout << "1-MezzanotteDaSecondi" << endl;
    cout << "Scelta: ";
    bool scelta = false;
    cin >> scelta;
    
    if(scelta)
        return MezzanotteDaSecondi();
    
    return SecondiDaMezzanotte();
}

int SecondiDaMezzanotte(){
    int ore = 0, minuti = 0, secondi = 0;
    
    cout << "Ore: ";
    cin >> ore;
    cout << "Minuti: ";
    cin >> minuti;
    cout << "Secondi: ";
    cin >> secondi;
    
    if (ore < 0 || ore > 23 || minuti < 0 || minuti > 59 || secondi < 0 || secondi > 59){
        cout << "Ma Shei Shtupidou?";
        return -1;
    }
    
    cout << "Ecco: " << (ore * 3600 + minuti * 60 + secondi) << endl;
    
    return 0;
}

int MezzanotteDaSecondi(){
    int i = 0;
    
    cout << "Secondi passati: ";
    cin >> i;
    
    if (i < 0 || i > 86399){
        cout << "Ma Shei Shtupidou?";
        return -1;
    }
    
    int ore = i / 3600, minuti = (i / 60) % 60, secondi = i % 60;
    
    cout << "Ore: " << ore << endl << "Minuti: " << minuti << endl << "Secondi: " << secondi << endl;
    
    return 0;
}
