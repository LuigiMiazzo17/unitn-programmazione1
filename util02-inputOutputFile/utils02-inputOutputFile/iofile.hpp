//
//  iofile.hpp
//  utils02-inputOutputFile
//
//  Created by Luigi Miazzo on 21/02/22.
//

#ifndef iofile_hpp
#define iofile_hpp

bool getFromFile(const char[], char**&, int&);
bool countWords(const char[], int&, int);
bool getLinesFromFile(const char[], char **&, int&);
bool countLines(const char[], int&, int);
void initCharArr(char*[], int, int);
bool outToFile(const char[], char **, int);

#endif /* iofile_hpp */
