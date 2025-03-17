#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include<string>
using namespace std;
class Cat
{
protected:
    string name, breed, health_condition, catID, status;
    char gender;
    int age;
    int count = -1;
    vector<string> lines;
public:
    Cat();
    virtual ~Cat();



    void setname(string n);
    void setage(int a);
    void setgender(char g);
    void setbreed(string b);
    void setcatID(string id);
    void setstatus(string st);

    int getAge();
    string getname();
    char getgender();
    string getbreed();
    string getcatID();
    string getstatus();

    bool operator >(Cat c);
    bool operator <(Cat c);

    virtual void setdata();
    void generateID();
    string update();
    void Delete();

    virtual string setuser(bool b);
    virtual void signup();
    virtual bool login(char);
    virtual void updateage();
    virtual void update_HC();
};

#endif // CAT_H
