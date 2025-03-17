#include "Cat.h"
#include<iomanip>

Cat::Cat() : status("Available")
{
    //ctor
}

void Cat::setdata()
{

    cout<<endl<<setw(36)<< "Enter cat name: ";
    cin >> name;
    cout<<endl<<setw(37)<< "Enter cat breed: ";
    cin >> breed;
    cout<<endl<<setw(44)<< "Enter health condition: ";
    cin >> health_condition;
    cout<<endl<<setw(44)<< "Enter cat gender (M/F): ";
    cin >> gender;
    cout<<endl<<setw(35)<< "Enter cat age: ";
    cin >> age;
}

void Cat::generateID()
{
    catID = "";
    srand(time(0));
    bool det = true;
    for (int j = 0; j < 5; j++)
    {
        if (det)
        {
            catID += to_string(rand() % 10);
            det = false;
        }
        else
        {
            bool isUppercase = rand() % 2;
            if (isUppercase)
            {
                catID += ('A' + (rand() % 26));
            }
            else
            {
                catID += ('a' + (rand() % 26));
            }
            det = false;
        }
    }
}

string Cat::update()
{
    int i=0;
    string line, user,pass;
    ifstream infile("store.txt");

    if (!infile.is_open())
    {
        cout<<endl<<setw(60)<< "Error: Could not open file for reading." << endl;
        return "0";
    }

    while (getline(infile, line))
    {
        if(i==count)
        {
            stringstream ss(line);
            ss >> user >> pass >> catID >> name >> breed >> health_condition >> gender >> age >> status;
        }
        lines.push_back(line);
        i++;
    }
    infile.close();
    string text = user + " " + pass;
    return text;
}

void Cat::Delete()
{
    string line;
    ifstream infile("store.txt");

    if (!infile.is_open())
    {
        cout<<endl<<setw(60)<< "Error: Could not open file for reading." << endl;
        return;
    }

    while (getline(infile, line))
    {
        lines.push_back(line);
    }
    infile.close();

    ofstream outfile("store.txt");
    if (!outfile.is_open())
    {
        cout<<endl<<setw(60)<< "Error: Could not open file for writing." << endl;
        return;
    }

    for (int i = 0; i < lines.size(); i++)
    {
        if (i != count)
        {
            outfile << lines[i] << endl;
        }
    }
    outfile.close();
    lines.clear();
    cout<<endl<<setw(60)<< "Your account deleted successfully." << endl;

}




void Cat::setname(string n){name=n;}
void Cat::setage(int a){age=a;}
void Cat::setgender(char g){gender=g;}
void Cat::setbreed(string b){breed=b;}
void Cat::setcatID(string id){catID=id;}
void Cat::setstatus(string st){status=st;}

int Cat::getAge(){ return age; }
string Cat::getname(){ return name; }
char Cat::getgender(){ return gender; }
string Cat::getbreed(){ return breed; }
string Cat::getcatID(){ return catID; }
string Cat::getstatus(){ return status; }

bool Cat::operator >(Cat c)
{
    return age > c.getAge();
}

bool Cat::operator < (Cat c)
{
    return age < c.getAge();
}

string Cat::setuser(bool b){}
void Cat::signup(){}
bool Cat::login(char){}
void Cat::updateage(){}
void Cat::update_HC(){}

Cat::~Cat()
{
    //dtor
}
