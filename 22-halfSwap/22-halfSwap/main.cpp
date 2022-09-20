//
//  main.cpp
//  22-halfSwap
//
//  Created by Luigi Miazzo on 16/02/22.
//

#include <iostream>

using namespace std;

//void halfSwap(short *, short *);

//int main(int argc, const char * argv[]) {
//
//    short n1 = 256, n2 = 2;
//
//    cout << "n1: " << n1 << "; n2: " << n2 << endl;
//
//    halfSwap(&n1, &n2);
//
//    cout << "n1: " << n1 << "; n2: " << n2 << endl;
//
//    return 0;
//}

//void halfSwap(short * n1, short * n2){
//    char * p1 = (char *) n1;
//    char * p2 = (char *) n2;
//
//    char temp = *(p1+1*sizeof(char));
//    *(p1+1) = *(p2+1);
//    *(p2+1) = temp;
//}

void swapHalf(short * n1, short * n2);

int main() {

    short n1, n2;
    n1 = 257;
    n2 = 2;

    cout << "n1 " << n1 << ", n2 " << n2 << endl;

    swapHalf(&n1, &n2);

    cout << "n1 " << n1 << ", n2 " << n2 << endl;

    return 0;
}

void swapHalf(short * n1, short * n2) {

    char * pn1 = (char *) n1;
    char * pn2 = (char *) n2;

    char tempSecondHalfN1 = *(pn1+1*sizeof(char));
    *(pn1+1) = *(pn2+1);
    *(pn2+1) = tempSecondHalfN1;
}
