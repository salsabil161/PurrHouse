#include "AdoptedCat.h"
#include<set>

AdoptedCat::AdoptedCat()
{
    //ctor
}

void AdoptedCat::setname(string n){ adopter_name=n; }
void AdoptedCat::setaddress(string ads){ adress=ads; }

string AdoptedCat::setuser1(bool b, string filename){
    return user::setuser(b, filename); }
void AdoptedCat::signup1(string filename){
    user::signup(filename); }
bool AdoptedCat::login1(string filename){
    return user::login(filename); }

bool AdoptedCat::setadopter()
{


    string stname, stpass, stcatID, cname, stbreed, sthealth_condition, stgender, STatus;
    int stage;
    vector<string> catlist;
    vector<int>index;
    count=-1;

    ifstream infile("store.txt");
    if (!infile.is_open())
    {
        cout<<endl<<setw(90)<< "Error: Could not open file for reading." << endl;
        return false;
    }

    cout<<endl<<setw(69)<<"Available cat breeds:\n" <<endl;
    set<string> brd;
    while (infile >> stname >> stpass >> stcatID >> cname >> stbreed >> sthealth_condition >> stgender >> stage >> STatus)
    {
        if(STatus=="Available")
            brd.insert(stbreed);

    }
    infile.close();
    for(auto x:brd)
    {
       cout<<setw(50)<<"*"<<x<<endl;
    }

    cout<<setw(88)<<"-------------------------------------------------------------------"<<endl;
    cout<<endl<<setw(55)<<"What is your preferred cat breed? "<<endl;
    cout<<setw(35)<<"Enter choice: ";
    cin>>cat_breed;
    //Sleep(1000);
    //system("cls");

    //cout<<setw(88)<<"--------------------------------------------------------------"<<endl;

    cout<<endl<<setw(53)<<"What is your preferred cat age? "<<endl;
    cout<<setw(35)<<"Enter choice: ";
    cin>>cat_age;
    cout<<endl<<setw(50)<<"Preferred cat gender(M/F/All)"<<endl;
    cout<<setw(35)<<"Enter choice: ";
    cin>>cat_gender;
    Sleep(1000);
    system("cls");

    ifstream infile2("store.txt");
    if (!infile2.is_open())
    {
        cout<<endl<<setw(90)<< "Error: Could not open file for reading." << endl;
        return false;
    }

    while (infile2 >> stname >> stpass >> stcatID >> cname >> stbreed >> sthealth_condition >> stgender >> stage >> STatus)
    {
        count++;
        if(cat_gender != "All")
        {
            if (cat_gender==stgender && (stbreed==cat_breed || cat_age==stage) && STatus == "Available")
            {
                catlist.push_back("\n\t\t\t\t\t\tCatID: "+stcatID + "\n\t\t\t\t\t\tCat Name: " + cname + "\n\t\t\t\t\t\tCat Breed: " + stbreed + "\n\t\t\t\t\t\tHealth: "  + sthealth_condition + "\n\t\t\t\t\t\tGender: " + stgender + "\n\t\t\t\t\t\tAge: " + to_string(stage) + "\n\t\t\t\t\t\tStatus: " + STatus);
                index.push_back(count);
            }
        }
        else
        {
            if (STatus == "Available" && (stbreed==cat_breed || cat_age==stage) )
            {
                catlist.push_back("\n\t\t\t\t\t\tCatID: "+stcatID + "\n\t\t\t\t\t\tCat Name: " + cname + "\n\t\t\t\t\t\tCat Breed: " + stbreed + "\n\t\t\t\t\t\tHealth: "  + sthealth_condition + "\n\t\t\t\t\t\tGender: " + stgender + "\n\t\t\t\t\t\tAge: " + to_string(stage) + "\n\t\t\t\t\t\tStatus: " + STatus);
                index.push_back(count);
            }
        }

    }
    infile2.close();

    int choice;
     cout<<endl<<endl<<setw(66)<<"*Available Cats!*"<<endl;
     for(int k=0;k<catlist.size();k++)
     {
         cout<<"\n\n\n"<<setw(57)<<"Cat "<<k+1<<": "<<endl;
         cout<<catlist[k]<<endl;
     }
     if(catlist.size()!=0)
     {
        cout<<endl<<endl<<setw(75)<<"Which cat do you want to adopt? "<<endl;
        cout<<setw(58)<<"Type here: ";
        cin>>choice;
     }
     else
     {
        cout<<endl<<setw(75)<<"SORRY!! No such matching cat found."<<endl;
        return false;
     }
    ofstream Outfile("adopter.txt",ios::app);
    if (!Outfile.is_open()) {
        cout<<endl<<setw(90)<< "Error: Could not open file for writing." << endl;
        return false;
    }
    string info="Adopter name: "+adopter_name+ " Address: "+adress+catlist[choice-1];
    Outfile<<setw(60)<<info<<endl;
    count=index[choice-1];
    Sleep(2000);
    system("cls");
    return true;

}
void AdoptedCat::updatestatus()
{
    string text="";
    string user;
    user = Cat::update();
    Cat::status = "Adopted";
    d.topBorder("Adoption Procedure", 7);
    cout<<endl<<setw(67)<<"Adoption Successful!!"<<endl;

    cout<<endl<<endl<<setw(58)<< "Cat ID: " << catID << endl
                 <<setw(56)<< "Name: " << name << endl
                 <<setw(57)<< "Breed: " << breed << endl
                 <<setw(68)<< "Health Condition: " << health_condition << endl
                 <<setw(58)<< "Gender: " << gender << endl
                 <<setw(55)<< "Age: " << age << endl
                 <<setw(58)<< "Status: " << status << endl<<endl;
    text = user+ " " + catID + " " + name + " " + breed + " " + health_condition + " " + gender + " " + to_string(age) + " " + status;
    cout<<endl<<setw(43)<<"Your cat " << name <<" will reach your door steps in no time!!"<<endl;
    ofstream outfile("store.txt");
    if (!outfile.is_open())
    {
        cout<<endl<<setw(90)<< "Error: Could not open file for writing." << endl;
        return;
    }
    for(int i=0; i<lines.size();i++)
    {
        if(i==count){
            outfile << text << endl;
        }
        else{
            cout<<setw(60);
            outfile<< lines[i] <<endl;
        }
    }
    outfile.close();
    lines.clear();
}

AdoptedCat::~AdoptedCat()
{
    //dtor
}
