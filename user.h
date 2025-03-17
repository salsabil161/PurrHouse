#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
#include <fstream>
#include <conio.h>
#include <set>
using namespace std;

class user
{
    private:
        string username;
        string pass;

    public:
        user();
        virtual ~user();

        string setuser(bool b, string filename);
        void signup(string);
        bool login(string);
};

#endif // USER_H
