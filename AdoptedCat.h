#ifndef ADOPTEDCAT_H
#define ADOPTEDCAT_H

#include <Cat.h>
#include<user.h>
#include "Decor.h"

#include <windows.h>
#include <cstdlib>

class AdoptedCat : public Cat, public user
{
    private:
        string adopter_name;
        string adress;
        string cat_breed;
        string cat_gender;
        int cat_age;
        Decor d;
    public:
        AdoptedCat();
        ~AdoptedCat();

        void setname(string n);
        void setaddress(string ads);
        bool setadopter();
        void updatestatus();
        string setuser1(bool b, string filename);
        void signup1(string filename);
        bool login1(string filename);


};

#endif // ADOPTEDCAT_H
