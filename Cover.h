#ifndef COVER_H
#define COVER_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <windows.h>

#include "Cover.h"

using namespace std;

class Cover {
    const int terminalWidth = 120;

    int terminalHeight;
    int horizontalPadding;
    int verticalPadding;

public:
    Cover(int height);
    ~Cover();

    void verticalSpacing(const vector<string>& lines);

    void horizontalSpacing(const vector<string>& lines);
};


#endif // COVER_H
