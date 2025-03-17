#ifndef DONATEDCAT_H
#define DONATEDCAT_H

#include <Cat.h>
#include <windows.h>
#include <set>
#include <conio.h>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include "Decor.h"


class DonatedCat : public Cat
{
private:
    string username;
    string pass;
    Decor d;

public:
    DonatedCat();
    ~DonatedCat();

    void setdata();
    string setuser(bool b);
    void signup();
    bool login(char);
    void updateage();
    void update_HC();

};

#endif // DONATEDCAT_H
