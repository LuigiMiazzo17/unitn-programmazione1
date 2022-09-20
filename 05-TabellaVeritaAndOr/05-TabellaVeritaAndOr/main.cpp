//
//  main.cpp
//  05-TabellaVeritaAndOr
//
//  Created by Luigi Miazzo on 11/02/22.
//

#include <iostream>

using namespace std;

void PrintTable(char);

int main(int argc, const char * argv[]) {
    
    cout << "0- Tabella \"And\"" << endl;
    cout << "1- Tabella \"Or\"" << endl << "Scelta: ";
    bool scelta = false;
    cin >> scelta;
    cout << endl;
    
    PrintTable(scelta ? '|' : '&');
    
    return 0;
}
void PrintTable(char o){
    
    cout << "\tX\t|\tY\t|\tX" << o << o << "Y" << endl;
    cout << " -------|-------|--------" << endl;
    
    for(int x = 0; x <= 1; x++)
        for(int y = 0; y <= 1; y++)
            cout << "\t" << x << "\t|\t" << y << "\t|\t" << (o == '&' ? x&&y : x||y) << endl;
    
    return;
}
