#ifndef FUND_H
#define FUND_H
#include "FundProj.h"

#include<iostream>
#include<string>
#include<iomanip>
#include<limits>
#include<fstream>
#include<vector>
#include<user.h>


using namespace std;

class Fund: public user
{
    private:
        string donorName;
        string donorPhone;
        string donorAddress;
        double amountDonated;
        static string projectName;

    public:
        Fund(const string& dName, const string& dPhone, const string& dAddress, double amount);
        Fund();

        static void setProjectName(const string& project) ;
        void displayDonorInfo()const;
        void saveDonorInfoToFile(ofstream& file) const;
        static Fund donorInfoInput();
        void displayProjectName() ;

};

#endif // FUND_H
