#ifndef INFOCENTER_H
#define INFOCENTER_H
#include "Cat.h"
#include "Decor.h"

using namespace std;
class InfoCenter
{
    private:
          Cat cats[100];
          int total;
          Decor d;
    public:
        InfoCenter();
        ~InfoCenter();

        void aboutus();
        void showintro();
        void getcatlist();
        void showSmallest();
        void showoldest();
        void totalcats();
        void vetcontacts();




};

#endif // INFOCENTER_H
