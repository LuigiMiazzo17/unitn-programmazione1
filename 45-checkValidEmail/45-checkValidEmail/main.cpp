//
//  main.cpp
//  45-checkValidEmail
//
//  Created by Luigi Miazzo on 19/02/22.
//

#include <iostream>
#include "emailVerifier.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    const char email[] = "luigi.miazzo.93@gmail.com";
    
    cout << isValidEmail(email) << endl;
    
    return 0;
}
