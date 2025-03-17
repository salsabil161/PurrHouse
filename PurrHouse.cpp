#include "PurrHouse.h"
#include "ASCIIArt.h"
#include "Cover.h"
#include<iomanip>
PurrHouse::PurrHouse()
{
    //ctor
}

vector<string> PurrHouse::getLogin() {
    return {
        "  ***********     ",
        "  *  LOGIN  *     ",
        "  ***********     ",
        "       1          "
    };
}

// Function to return ASCII representation of the signup screen
vector<string> PurrHouse::getSignup() {
    return {
        "  ***********     ",
        "  * SIGNUP  *     ",
        "  ***********     ",
        "       2          "
    };
}
ASCIIArt PurrHouse::getlogo() {
    return ASCIIArt({
        "     /\\_/\\        ",
        "    ( o.o )       ",
        "     > ^ <        "
    });
    //d.topBorder("The PurrHouse", 7);
}

// Function to generate ASCII-based entry screen
ASCIIArt PurrHouse::createEntry() {
    vector<vector<string>> letters = {getLogin(), getSignup()};
    vector<string> entry;

    // Ensure we iterate within the valid range
    int maxRows = letters[0].size(); // Assuming all have the same number of rows
    for (int row = 0; row < maxRows; row++) {
        string line;
        for (const auto& letter : letters) {
            line += letter[row] + "  "; // Adding space for separation
        }
        entry.push_back(line);
    }

    return ASCIIArt(entry);
}

void PurrHouse::makelogo(){
    ASCIIArt logo = getlogo();
    vector<string> combinedlogo = logo.getLines();
    Cover cover3(0);
    cover3.horizontalSpacing(combinedlogo);
}

// Function to handle cat donation process
void PurrHouse::donateCat() {
    string ch="";
    string choice="2";
    while(true){
        cout<<endl;
        makelogo();
        cout<<endl;
        d.topBorder("LogIn or SignUp Page", 8);
        // Display entry screen
        ASCIIArt entry = createEntry();
        vector<string> Entry = entry.getLines();
        Cover cover(15);
        cover.verticalSpacing(Entry);
        cover.horizontalSpacing(Entry);



        //cout<<"\n\t\t\t\t W E L C O M E   T O   T H E   P U R R H O U S E"<<endl;
        if(ch!="taken"){
        //cover3.horizontalSpacing(combinedlogo);
        cout<<endl<<" "<<setw(45)<<"Would"<<" you like to Log In or Sign Up?"<<endl;
        //cout<<setw(50)<<"1. Log In"<<endl<<setw(51)<<"2. Sign Up"<<endl<<endl;
        cout<<setw(41)<<"";
            cin>>choice;
        }
        else{
            cout<<endl<<" "<<setw(45)<<"Enter"<<" your credentials again!"<<endl;
        }
        if(choice=="2")
        {
            u1 = new DonatedCat;
            cout<<endl;
            ch=u1->setuser(true);
            if(ch!="taken"){
                Sleep(500);
                system("cls");
                cout<<endl;
                makelogo();
                u1->setdata();
                u1->signup();
                break;
            }
        }
        else if(choice=="1"){
            bool factor;
            bool cng=false;
            bool update=false;
            string option="yes";
            string opt;
            u1 = new DonatedCat;
            cout<<endl;
            u1->setuser(false);
            factor = u1->login('l');
            if(factor == true)
            {
                while(true){
                    if(cng==false){
                        cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;
                        cout<<endl<<setw(26)<<"Would"<<" you like to make any updates? (y/n)"<<endl;
                        cout<<setw(21)<<"";
                        cin>>option;
                        cin.ignore();
                    }
                    if(option=="y"){
                        cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;
                        cout<<endl<<setw(25)<<"What"<<" would you like to change?";
                        cout<<endl<<setw(27)<<"1. Age";
                        cout <<endl<<setw(40)<<"2. Health condition"<<endl;
                        //cin.ignore();

                        cout<<endl<<setw(35)<<"Enter choice: ";
                        cin>>opt;
                        if(opt=="1"){
                            u1->updateage();
                        }
                        else{
                            u1->update_HC();
                        }
                        cng=true;
                        cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;

                    }
                    else{
                        cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;
                        cout<<setw(22)<<"Do"<<" you want to delete the account? (y/n)"<<endl;
                        cout<<setw(20)<<"";
                        cin>>option;
                        if(option=="y"){
                            u1->Delete();
                            delete u1;
                        }
                    }
                    string ans;
                    cout<<endl;
                    if(option=="n"){
                        break;
                    }
                    //cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;

                    cout<<endl<<setw(26)<<"Would"<<" you like to make any other changes? (y/n)"<<endl;
                    cout<<setw(21)<<"";
                    cin>>ans;
                    if(ans=="n"){
                        break;
                    }
                    //cout<<endl<<setw(21)<<"-"<<"-------------------------------------------------------------------------------"<<endl;

                }
            }
            break;
        }
        Sleep(500);
        system("cls");
    }
}

void PurrHouse::adoptCat()
{
    string nm,ch="", choice;
    AdoptedCat a;
    while(true){
        makelogo();
        d.topBorder("Cat Adoption Form", 7);
        ASCIIArt entry = createEntry();
        vector<string> Entry = entry.getLines();
        Cover cover(15);
        cover.verticalSpacing(Entry);
        cover.horizontalSpacing(Entry);
        cout<<endl<<" "<<setw(45)<<"Would"<<" you like to Log In or Sign Up?"<<endl;
        cout<<setw(41)<<"";
        cin>>choice;
        ch=a.setuser1(true, "adopterID.txt");
        if(ch!="taken"){
            if(choice=="1"){
                if(a.login1("adopterID.txt")){
                cout<<endl<<endl<<setw(69)<< "WELCOME TO PURRHOUSE AGAIN!!"<<endl;
                cout<<setw(69)<<"You may now choose your cat!" << endl<<endl;
                }
                else {
                    Sleep(4000);
                    system("cls");
                    continue;
                }
            }
            else if(choice=="2"){
                a.signup1("adopterID.txt");
                cout<<endl;
                Sleep(4000);
                system("cls");
                cout<<endl;
                makelogo();
                d.topBorder("Fill up your info", 7);
               // cout<<"\n\n"<<setw(68)<<"**Fill up your info**"<<endl;
                cout<<"\n"<<setw(37)<<"Enter your name: ";
                cin>>nm;
                a.setname(nm);
                cout<<setw(40)<<"Enter your address: ";
                cin>>nm;
                int num;
                cout<<setw(41)<<"Enter your phone no: ";
                cin>>num;
                string mail;
                cout<<setw(45)<<"Enter your mail address: ";
                cin>>mail;
                a.setaddress(nm);
            }
            Sleep(4000);
            system("cls");
            cout<<endl;
            makelogo();
            d.topBorder("Cat Breeds", 3);
            bool t=a.setadopter();
            cout<<endl;
            if(t)
            {
                makelogo();
                a.updatestatus();
            }
            break;

        }
        Sleep(500);
        system("cls");
    }
}

int PurrHouse::quiz()
{
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    Quizes quizz;
    //cout<<"\n\t\t\t\t W E L C O M E   T O   T H E   P U R R H O U S E"<<endl;
    d.topBorder("QUIZ TIME", 3);
    cout<<endl<<setw(80)<<"Think you're ready to adopt a cat? ^.^"<<endl;
    cout<<endl<<setw(90)<<"In order to ensure you're a perfect parent for our precious cats,"<<endl;
    cout<<setw(86)<<"you'll be facing a short and fun quiz to gain our trust!"<<endl;
    cout<<endl<<setw(93)<<"You'll need to score at least an 8 out of 10 to get your cat in hand!"<<endl;
    cout<<endl<<setw(75)<<"You can do it! Best wishes <3 "<<endl;

    Sleep(5000);
    system("cls");
    int SCORE=quizz.startQuiz();
    return SCORE;
}

int PurrHouse::fund()
{
    vector<Fund> donors;

    string projectName, ch;

    ofstream file("DonorsInfo.txt");
    if(!file){
        cout<<"Error opening file."<<endl;
        return 1;
    }

    char choice='y';
    bool exit=false;

    while(choice=='y'||choice=='Y'){
        cout<<endl;
        d.topBorder("FUND FOR PURRS", 6);
        //cout<<endl<<setw(65)<<"Fundraising Project Name: Purrs for a Purpose";
        //getline(cin, projectName);

        //cout<<endl<<setw(42)<<"Adding a new donor...\n"<<endl;

        cout<<endl<<endl;
        //cout<<setw(61)<<"Sign Up"<<endl;
        ch=f.setuser(true, "fundID.txt");
        if(ch!="taken"){
                cout<<endl;
            f.signup("fundID.txt");
            cout<<endl;
            cin.ignore();
            //Sleep(3000);
            //system("cls");
            //d.topBorder("Helloo", 5);
            Fund newDonor= Fund:: donorInfoInput();
            donors.push_back(newDonor);
            donors.back().saveDonorInfoToFile(file);

            cout<<endl<<setw(58)<<"Do you want to add a new donor? (y/n) "<<endl;
            cout<<setw(20)<<"";
            cin>>choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//clear buffer input
            system("cls");

            file.close();

            //Sleep(1000);
            system("cls");
            if(choice=='n'){
                    cout<<endl;
                 d.topBorder("DONORS DETAILS", 6);

            cout<<endl<<endl;
            for(int i=0; i<donors.size(); i++){
                cout<<setw(46)<<"Donor "<<i+1<<":"<<endl;
                donors[i].displayDonorInfo();
                cout<<endl;
            }
            exit=true;
            }
        }
        if(exit==false){
            Sleep(500);
            system("cls");
        }
    }
}

void PurrHouse::reviews(){
    const string filename= "reviews.txt";

    r.displayReviews(filename);

    char ch;
    bool val;
    cout<<endl<<setw(59)<<"Would you like to add a review? (y/n): ";
    cin>>ch;
    string name;

    if(ch=='Y'||ch=='y'){
        int choice;

        cout<<endl<<endl<<setw(58)<<"How are you associated with Purrhouse?"<<endl;
        cout<<setw(31)<<"1. Adoption"<<endl;
        cout<<setw(31)<<"2. Donation"<<endl;
        cout<<setw(28)<<"3. Funds"<<endl;

        cout<<endl<<setw(39)<<"Enter Your Choice: ";
        cout<<setw(1)<<" ";
        cin>>choice;
        if(choice==1){
            name=r.setuser(false, "adopterID.txt");
            val=r.login("adopterID.txt");
        }
        else if(choice==2){
            u1 = new DonatedCat;
            name = u1->setuser(false);
            val=u1->login('r');
        }
        else if(choice==3){
            name=f.setuser(false,"FundID.txt");
            val=f.login("FundID.txt");
        }
        cin.ignore();
        cout<<endl<<endl<<setw(68)<< "You may now write your review!" << endl<<endl;
        if(val==true)
            r.addReview(filename,name);
    }
    else{
        cout<<endl<<endl<<setw(70)<<"Thank you for checking the Reviews!"<<endl;
    }
}

PurrHouse::~PurrHouse()
{
    //dtor
}

