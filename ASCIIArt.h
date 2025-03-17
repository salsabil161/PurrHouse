#ifndef ASCIIART_H
#define ASCIIART_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <set>
#include <windows.h>

using namespace std;

class ASCIIArt{
private:
    vector<string> lines;

public:
    ASCIIArt(const vector<string>& inputLines);
    ~ASCIIArt();

    ASCIIArt operator+(const ASCIIArt& other) const;

    vector<string> getLines() const;
    string toString() const;
};

#endif // ASCIIART_H
