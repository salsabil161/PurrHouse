#include "DonatedCat.h"

DonatedCat::DonatedCat():username(""),pass("")
{
    //ctor
}



void DonatedCat::setdata()
{
    cout<<endl;
    d.topBorder("Cat Donation Form",6);
    cout<<endl<<setw(41)<< "Provide your cat info" << endl;
    Cat::setdata();
}

string DonatedCat::setuser(bool b)
{
    //d.topBorder("LogIn or SignUp Page", 8);
    cout<<setw(57)<< "Enter Username: ";
    cin >> username;
    cout<<setw(57)<< "Enter Password: ";
   // string password;
    char ch;
    while (true) {
        ch = _getch(); // Get a single character without displaying it

        if (ch == 13) // Enter key (ASCII 13) to stop input
            break;
        else if (ch == 8 && !pass.empty()) { // Handle Backspace (ASCII 8)
            cout << "\b \b"; // Erase last star
            pass.pop_back();
        } else {
            pass += ch;
            cout << '*'; // Mask input with stars
        }
    }
    if(b){
        string stname, stpass, stcatID, cname, stbreed, sthealth_condition, stgender, STatus;
        int stage;
        ifstream infile("store.txt");

        if (!infile.is_open()) {
            cout << setw(90) << "Error: Could not open file for reading." << endl;
            return "false";
        }

        set<string> catData;

        while (infile >> stname >> stpass >> stcatID >> cname >> stbreed >> sthealth_condition >> stgender >> stage >> STatus)
        {
            catData.insert(stname);
        }
        auto val = catData.insert(username);
        if (!val.second) { // If username already exists
            cout<<endl<<endl;
            cout << setw(64) << "Username already taken!" << endl;
            return "taken";
        }
    }
    return username;
}

void DonatedCat::signup()
{
    Cat::generateID();
    ofstream outfile;
    outfile.open("store.txt", ios::app);
    if (!outfile.is_open()) {
        cout <<endl<<setw(60)<< "Error: Could not open file for writing." << endl;
        return;
    }
    if (!breed.empty()) {
        transform(breed.begin(), breed.begin() + 1, breed.begin(), ::toupper);
    }
    outfile << username << ' ' << pass << ' ' << catID << ' ' << name << ' '
            << breed << ' ' << health_condition << ' ' << gender << ' ' << age << ' ' << status << endl;
    outfile.close();
    cout<<endl <<setw(65)<< "Sign Up Successful!" << endl;
}

bool DonatedCat::login(char O)
{
    string stname, stpass, stcatID, cname, stbreed, sthealth_condition, stgender, STatus;
    int stage;
    ifstream infile("store.txt");

    if (!infile.is_open()) {
        cout <<setw(90)<< "Error: Could not open file for reading." << endl;
        return false;
    }

    count = -1;
    while (infile >> stname >> stpass >> stcatID >> cname >> stbreed >> sthealth_condition >> stgender >> stage >> STatus)
    {
        count++;
        if (stname == username && stpass == pass)
        {
            cout<<endl<<endl;
            cout<<setw(68)<< "Login successful!" << endl;
            if(O=='l'){
                Sleep(2000);
                system("cls");
                cout<<endl;
                d.topBorder("Cat Information",6);
                cout<<endl<<endl<<setw(58)<< "Cat ID: " << stcatID << endl
                 <<setw(56)<< "Name: " << cname << endl
                 <<setw(57)<< "Breed: " << stbreed << endl
                 <<setw(68)<< "Health Condition: " << sthealth_condition << endl
                 <<setw(58)<< "Gender: " << stgender << endl
                 <<setw(55)<< "Age: " << stage << endl
                 <<setw(58)<< "Status: " << STatus << endl<<endl;
            }
            infile.close();
            if(STatus == "Adopted")
            {
                Cat::Delete();
                return false;
            }
            return true;
        }
    }
    cout<<endl<<setw(79)<< "Error: Username or password not found." << endl;
    return false;
    infile.close();
}

void DonatedCat::updateage()
{
    int currage;
    string text="";
    cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;
    cout<<endl<<setw(45)<<"What is the current age?"<< endl;
    cout<<setw(21)<<"";
    cin>>currage;
    cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;

    Cat::update();
    text = username + " " + pass + " " + catID + " " + name + " " + breed + " " + health_condition + " " + gender + " " + to_string(currage) + " " + status;
    ofstream outfile("store.txt");
    if (!outfile.is_open())
    {
        cout <<setw(80)<< "Error: Could not open file for writing." << endl;
        return;
    }
    for(int i=0; i<lines.size();i++)
    {
        if(i==count){
            outfile << text << endl;
        }
        else
            outfile<< lines[i] <<endl;
    }
    outfile.close();
    lines.clear();
    cout <<setw(66)<< "Your cat updated successfully!" << endl;
    Sleep(2000);
    system("cls");
    cout<<endl;
    d.topBorder("Updated Cat Information", 10);
    cout <<endl<<endl<<setw(58)<< "Cat ID: " << catID << endl
                 <<setw(56)<< "Name: " << name << endl
                 <<setw(57)<< "Breed: " << breed << endl
                 <<setw(68)<< "Health Condition: " << health_condition << endl
                 <<setw(58)<< "Gender: " << gender << endl
                 <<setw(55)<< "Age: " << currage << endl
                 <<setw(58)<< "Status: " << status << endl<<endl;
}

void DonatedCat::update_HC()
{
    string currHC;
    string text="";
    cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;
    cout<<endl<<endl<<setw(58)<<"What is the current health condition?"<< endl;
    cout<<setw(21)<<"";
    cin>>currHC;
    cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;

    Cat::update();
    text = username + " " + pass + " " + catID + " " + name + " " + breed + " " + currHC + " " + gender + " " + to_string(age) + " " + status;
    ofstream outfile("store.txt");
    if (!outfile.is_open())
    {
        cout <<setw(60)<< "Error: Could not open file for writing." << endl;
        return;
    }
    for(int i=0; i<lines.size();i++)
    {
        if(i==count){
            outfile<< text <<endl;
        }
        else
            outfile<<lines[i]<<endl;
    }
    outfile.close();
    lines.clear();
    cout <<setw(66)<< "Your cat updated successfully." << endl;
    Sleep(2000);
    system("cls");
    cout<<endl;
    d.topBorder("Updated Cat Information", 10);
    cout<<endl;
    cout<<endl<<setw(58)<< "Cat ID: " << catID << endl
                 <<setw(56)<< "Name: " << name << endl
                 <<setw(57)<< "Breed: " << breed << endl
                 <<setw(68)<< "Health Condition: " << currHC << endl
                 <<setw(58)<< "Gender: " << gender << endl
                 <<setw(55)<< "Age: " << age << endl
                 <<setw(58)<< "Status: " << status << endl<<endl;
}


DonatedCat::~DonatedCat()
{
    //dtor
}
