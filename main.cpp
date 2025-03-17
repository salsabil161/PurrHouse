#include "PurrHouse.h"
#include "InfoCenter.h"
#include "ASCIIArt.h"
#include "Cover.h"
//#include "Decor.h"
using namespace std;

vector<string> getP() {
    return {"  ****   ", "  *   *  ", "  ****   ", "  *      ", "  *      "};
}

vector<string> getU() {
    return {"  *   *  ", "  *   *  ", "  *   *  ", "  *   *  ", "   ***   "};
}

vector<string> getR() {
    return {"  ****   ", "  *   *  ", "  ****   ", "  *  *   ", "  *   *  "};
}

vector<string> getH() {
    return {"  *   *  ", "  *   *  ", "  *****  ", "  *   *  ", "  *   *  "};
}

vector<string> getO() {
    return {"   ***   ", "  *   *  ", "  *   *  ", "  *   *  ", "   ***   "};
}

vector<string> getS() {
    return {"   ****  ", "  *      ", "   ***   ", "      *  ", "  ****   "};
}

vector<string> getE() {
    return {"  *****  ", "  *      ", "  ****   ", "  *      ", "  *****  "};
}
vector<string> getAdopt() {
   return {
        "     /\\_/\\        ",
        "    ( o.o )       ",
        "     > ^ <        ",
        "  ***********     ",
        "  *  ADOPT  *     ",
        "  *  PURRS  *     ",
        "  ***********     ",
        "       1          "
    };
}
vector<string> getDonate() {
    return {
        "     /\\_/\\        ",
        "    ( o.o )       ",
        "     > ^ <        ",
        "  ***********     ",
        "  *  GIFT   *     ",
        "  *  PURRS  *     ",
        "  ***********     ",
        "       2          "
    };
}
vector<string> getFund() {
    return {
        "     /\\_/\\        ",
        "    ( o.o )       ",
        "     > ^ <        ",
        "  ***********     ",
        "  *  RAISE  *     ",
        "  *  FUND   *     ",
        "  ***********     ",
        "       3          "
    };
}

vector<string> getInfo() {
    return {
        "     /\\_/\\        ",
        "    ( o.o )       ",
        "     > ^ <        ",
        "  ***********     ",
        "  *   INFO  *     ",
        "  *  CENTER *     ",
        "  ***********     ",
        "       4          "
    };
}
vector<string> getreview() {
    return {
        "     /\\_/\\        ",
        "    ( o.o )       ",
        "     > ^ <        ",
        "  ***********     ",
        "  *   SEE   *     ",
        "  *  REVIEW *     ",
        "  ***********     ",
        "       5          "
    };
}

ASCIIArt createPurrhouse() {
    vector<vector<string>> letters = {getP(), getU(), getR(), getR(), getH(), getO(), getU(), getS(), getE()};
    vector<string> purrhouse;

    for (int row = 0; row < 5; row++) {
        string line;
        for (const auto& letter : letters) {
            line += letter[row];
        }
        purrhouse.push_back(line);
    }

    return ASCIIArt(purrhouse);
}
ASCIIArt createOption() {
    vector<vector<string>> letters = {getAdopt(), getDonate(), getFund(), getInfo(), getreview()};
    vector<string> purrhouse;

    for (int row = 0; row < 8; row++) {
        string line;
        for (const auto& letter : letters) {
            line += letter[row];
        }
        purrhouse.push_back(line);
    }

    return ASCIIArt(purrhouse);
}

ASCIIArt createCat() {
    return ASCIIArt({
        "                ",
        "                ",
        "     /\\     /\\",
        "     {  `---'  }",
        "     {  O   O  }",
        "     ~~>  V  <~~",
        "     \\  \\|/  /",
        "         `-----'___",
        "          /     \\    \\_",
        "          {       }\\  ) \\",
        "           |  \\_/ _ / /   \\",
        "             \\_/  / (_/   (_)",
        "           (__/        "
    });
}

ASCIIArt getlogo() {
    return ASCIIArt({
        "     /\\_/\\        ",
        "    ( o.o )       ",
        "     > ^ <        "
    });
    //d.topBorder("The PurrHouse", 7);
}

ASCIIArt getFinal() {
    return ASCIIArt({
           "\t\t\t\t\t               _____       \n"
           "\t\t\t\t\t              /     \\      \n"
           "\t\t\t\t\t             /       \\        \n"
           "\t\t\t\t\t         /\\_/\\        \\        \n"
           "\t\t\t\t\t        ( o.o )   __  |            \n"
           "\t\t\t\t\t         > ^ <   |__| |            \n"
           "\t\t\t\t\t           |          |            \n"
           "\t\t\t\t\t           |__________|            \n\n"
           "\t\t\t\t\t                                    \n\n"
           "\t\t\t\t\t   --THANK YOU FOR CHOOSING US--            \n"
    });
}

void Loading(){
    system("color F5");
  //  system("cls");

    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177,bar2 = 219;
    cout << "\n\t\t\t\t\t\t    Loading...";
    cout << "\n\t\t\t\t\t\t    ";
    for(int i=0;i<25;i++){
        cout << (char)bar1;
    }
    cout <<"\r"; cout<< "\t\t\t\t\t\t    ";
    for(int i=0;i<25;i++){
        cout << (char)bar2;
        Sleep(120);
    }
}

int main() {
    system("color F5");
    ASCIIArt cat = createCat();
    ASCIIArt purrhouse = createPurrhouse();
    ASCIIArt opt = createOption();
    ASCIIArt logo = getlogo();
    ASCIIArt Final = getFinal();

    ASCIIArt combined = purrhouse + cat;

    vector<string> combinedLines = combined.getLines();

    Cover cover(30);
    cover.verticalSpacing(combinedLines);
    cover.horizontalSpacing(combinedLines);
    Sleep(1000);
    Loading();
    Sleep(500);
    system("cls");
    vector<string> combinedOpt = opt.getLines();
    Cover cover2(15);
    bool exit=true;
    Cover cover3(0);
    Cover cover4(15);
    vector<string> combinedlogo = logo.getLines();
    vector<string> combinedFinal = Final.getLines();
    while(true){
        cout<<"\n\t\t\t\t    W E L C O M E   T O   T H E   P U R R H O U S E"<<endl;
        cout<<"\n\n\n\t\t\t\t\t      WHAT WOULD YOU LIKE TO DO?"<<endl;
        cover2.verticalSpacing(combinedOpt);
        cover2.horizontalSpacing(combinedOpt);
        cout<<"\n\n\t\t\t\tYour Choice:  ";
        PurrHouse ph;
        int ch;
        cin>>ch;
        Sleep(500);
        system("cls");
        if(ch==1)
        {
            cout<<endl<<endl;
            cover3.horizontalSpacing(combinedlogo);
            int scr=ph.quiz();
            //ph.quiz();
            if(scr>=7)
            {
                cout<<endl<<endl;
                cover3.horizontalSpacing(combinedlogo);
                cout<<endl<<endl;
                //cout<<"\n\n";
                cout<<setw(65)<<"Your marks: "<<scr<<endl;
                cout<<endl<<setw(70)<<"YOOHUUUU CONGRATS!!!"<<endl;
                cout<<setw(72)<<"Now u can adopt a cat >.<"<<endl<<endl;;
                cout<<endl<<setw(77)<<"Press Enter to go to the next step...";
                cin.get();
                //Loading();
                system("cls");
                cout<<endl<<endl;
                //cover3.horizontalSpacing(combinedlogo);
                ph.adoptCat();
            }
            else
            {
                cout<<"\n\n\n\n\n";
                cout<<setw(65)<<"Your marks: "<<scr<<endl;
                cout<<endl<<setw(68)<<"MAYBE NEXT TIME!"<<endl;
                cout<<endl<<setw(65)<<"S O R R Y..."<<endl;
            }


        }
        else if(ch==2)
        {
            cout<<endl<<endl;
            //cover3.horizontalSpacing(combinedlogo);
            ph.donateCat();
        }
        else if(ch==3){
            cout<<endl<<endl;
            cover3.horizontalSpacing(combinedlogo);
            ph.fund();
        }
        else if (ch==4)
        {
            while(true)
            {
                cout<<endl<<endl;
                cover3.horizontalSpacing(combinedlogo);
                int q;
                InfoCenter i;
                i.showintro();
                i.getcatlist();
                cin>>q;
                system("cls");
                cout<<endl<<endl;
                cover3.horizontalSpacing(combinedlogo);
                cout<<endl;
                if(q==1)
                    i.aboutus();
                else if(q==2)
                    i.totalcats();
                else if(q==3)
                    i.showSmallest();
                else if(q==4)
                    i.showoldest();
                else if(q==5)
                    i.vetcontacts();
                else
                    cout<<"Wrong input";
                Sleep(1500);
                cout<<endl<<endl;
                cout<<endl<<endl<<setw(45)<<"Do"<<" you have any other query?  (y/n)";
                cout<<endl<<setw(43)<<"";
                string choice;
                cin>>choice;
                if(choice=="y")
                {
                    system("cls");
                }
                else
                {
                    exit=true;
                    break;
                }

            }

        }
        else if(ch==5){
            cout<<endl<<endl;
            cover3.horizontalSpacing(combinedlogo);
            ph.reviews();

        }
        string choice;
        if(exit==true)
        {
            cout<<"\n\n\n\n";
            cout<<setw(75)<<"Do you want to exit? (y/n)"<<endl<<endl;
            cout<<setw(49)<<"";
            cin>> choice;
        }
        if(choice=="y"){
            system("cls");
            cover4.verticalSpacing(combinedFinal);
            for (const auto& line : combinedFinal)
            cout<< line << endl;
            cout<<endl;
            break;
        }
        system("cls");
    }
    return 0;
}

