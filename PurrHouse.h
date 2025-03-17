#ifndef PURRHOUSE_H
#define PURRHOUSE_H
#include "DonatedCat.h"
#include "AdoptedCat.h"
#include "Quizes.h"
#include "Fund.h"
#include "Reviews.h"
#include "user.h"
#include "Decor.h"
#include "ASCIIArt.h"
#include "Cover.h"
#include <windows.h>
#include <cstdlib>

class PurrHouse
{
    private:
        Cat* u1;
        DonatedCat obj;
        user U;
        Decor d;
        Review r;
        Fund  f;
    public:
        PurrHouse();
        ~PurrHouse();

        void donateCat();
        void adoptCat();
        int quiz();
        int fund();
        void makelogo();
        void reviews();
        ASCIIArt createEntry();
        ASCIIArt getlogo();
        vector<string> getLogin();
        vector<string> getSignup();

};

#endif // PURRHOUSE_H
