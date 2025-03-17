#ifndef DECOR_H
#define DECOR_H
#include<string>
#include<iostream>
#include <iomanip>
using namespace std;

class Decor
{
    public:
        Decor();
        ~Decor();
        void topBorder(string heading, int n);

    private:
        int patternwidth;
        int consolewidth;
        int left;

};

#endif // DECOR_H
