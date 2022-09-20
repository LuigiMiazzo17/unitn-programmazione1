//
//  main.cpp
//  24-divisioneRicorsiva
//
//  Created by Luigi Miazzo on 17/02/22.
//

#include <iostream>

using namespace std;

int divisioneRicorsiva(int, int);

int main(int argc, const char * argv[]) {
    
    int divid = 7;
    int divis = 2;
    
    cout << divisioneRicorsiva(divid, divis) << endl;
    
    return 0;
}

int divisioneRicorsiva(int divis, int divid){
    if(divis < divid)
        return 0;
    int res = 0;
    divis -= divid;
    res += 1 + divisioneRicorsiva(divis, divid);
    return res;
}
