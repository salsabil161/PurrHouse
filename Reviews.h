#ifndef REVIEWS_H
#define REVIEWS_H

#include "Decor.h"
#include<user.h>
#include<string>
using namespace std;

class Review: public user
{
private:
    Decor d;

public:
    void displayReviews(const string& filename);
    void addReview(const string& filename,string name);

};

#endif // REVIEWS_H
