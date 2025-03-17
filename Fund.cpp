#include "Fund.h"

using namespace std;

Fund::Fund(){

}

Fund::Fund(const string& dName, const string& dPhone, const string& dAddress, double amount)
:donorName(dName), donorPhone(dPhone), donorAddress(dAddress), amountDonated(amount) {}


void Fund::displayDonorInfo() const{
    cout<<"\n\t\t\t\t\tDonor Name: "<<donorName <<endl
            <<"\t\t\t\t\tPhone Number: " << donorPhone <<endl
            <<"\t\t\t\t\tAddress: "<<donorAddress<<endl
            <<"\t\t\t\t\tDonation Amount: $"<<fixed<<setprecision(2)<<amountDonated<<endl;

}

void Fund::saveDonorInfoToFile(ofstream& file) const{
    file<<"Donor Name: "<<donorName<<endl
            <<"Phone Number: "<<donorPhone<<endl
            <<"Address: "<<donorAddress<<endl
            <<"Donation Amount: $"<<fixed<<setprecision(2)<<amountDonated<<endl
            <<"----------------------------------------------------"<<endl;
}

Fund Fund::donorInfoInput(){
    string dName, dAddress, dPhone;
        double amount;

        cout<<endl<<setw(38)<<"Enter Donor Name: ";
        getline(cin, dName);
        cout<<setw(39)<<"Enter Donor Phone: ";
        getline(cin, dPhone);
        cout<<setw(41)<<"Enter Donor Address: ";
        getline(cin, dAddress);
        cout<<setw(43)<<"Enter Donation Amount: ";
        while(!(cin>>amount)){
            cout<<"Invalid input. Enter a valid donation amount:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ensures robust input handling when mixing cin and getline

        }
        cin.ignore();

        return Fund(dName, dPhone, dAddress, amount);
}
