#include "Decor.h"
using namespace std;
Decor::Decor()
{
    //ctor
      patternwidth=80;
      consolewidth=120;
      left=(consolewidth-patternwidth)/2;

}

Decor::~Decor()
{
    //dtor
}



    //Top border
void Decor::topBorder(string heading, int n)
{

    cout<<setw(left)<<"";
    for(int i=0;i<patternwidth;i++){
        if(i%4==0){
            cout<<"*";
        }
        else
            cout<<"-";
    }
    cout << endl;

    //content
    cout<<setw((consolewidth/2)+n)<<heading<<endl;

    //Bottom border
    cout<<setw(left)<<"";
    for(int i=0;i<patternwidth;i++){
        if(i%3==0){
            cout<<".";
        }
        else
            cout<<"-";
    }
    cout << endl;

}
