#include "user.h"
#include<iomanip>
#include <windows.h>

user::user()
{
    //ctor
}

user::~user()
{
    //dtor
}
string user::setuser(bool b, string filename)
{
    cout<<endl<<setw(57)<< "Enter Username: ";
    cin >> username;
    cout<<setw(57)<< "Enter Password: ";
    //string password;
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
        string stname, stpass;
        int stage;
        ifstream infile(filename);

        if (!infile.is_open()) {
            cout << setw(90) << "Error: Could not open file for reading." << endl;
            return "false";
        }

        set<string> catData;
        while (infile >> stname >> stpass)
        {
            catData.insert(stname);
        }
        auto val = catData.insert(username);
        if (!val.second) { // If username already exists
            cout <<endl<< setw(65) << "Username already taken!" << endl;
            return "taken";
        }
    }
    return username;
}

void user::signup(string filename)
{
    ofstream outfile;
    outfile.open(filename, ios::app);
    if (!outfile.is_open()) {
        cout<<endl<<setw(68)<< "Error: Could not open file for writing." << endl;
        return ;
    }
    outfile << username << ' ' << pass <<endl;
    outfile.close();
    cout<<endl<<endl<<setw(68)<< "Signup successful!" << endl;
    //Sleep(1000);
    //system("cls");
}

bool user::login(string filename)
{
    string stname, stpass;
    ifstream infile(filename);

    if (!infile.is_open()) {
        cout << "Error: Could not open file for reading." << endl;
        return false;
    }
    while (infile >> stname >> stpass)
    {
        if (stname == username && stpass == pass)
        {
            //cout<<endl<<endl<<setw(68)<< "You may now write your review!" << endl<<endl;
            infile.close();
            return true;
        }
    }
    cout <<endl<<setw(68)<<"Error: Username or password not found." << endl;
    infile.close();
    return false;
}
