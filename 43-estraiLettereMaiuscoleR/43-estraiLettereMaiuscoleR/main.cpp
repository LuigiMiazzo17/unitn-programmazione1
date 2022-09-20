//
//  main.cpp
//  43-estraiLettereMaiuscoleR
//
//  Created by Luigi Miazzo on 19/02/22.
//

#include <iostream>
#include "estrai.hpp"

int main(int argc, const char * argv[]) {
    
    const char text[80] = "CiaoMiChiamoLuigi E QueSto E uN TeST!";
    char res[80];
    
    estrai(res, text, 80);
    
    std::cout << res << std::endl;
    return 0;
}
