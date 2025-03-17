#include "InfoCenter.h"
#include <iomanip>
#include<map>
InfoCenter::InfoCenter()
{
    //ctor
}

InfoCenter::~InfoCenter()
{
    //dtor
}

void InfoCenter::showintro()
{
    d.topBorder("Information Center", 8);
    cout<<endl;
    cout<<endl;
   // cout<<setw(107)<<"A user-friendly platform that connects potential adopters with cats in need of homes."<<endl;
    cout<<setw(43)<<"Some common querries: "<<endl<<endl;
    cout<<setw(37)<<"1. Know about us"<<endl;
    cout<<setw(47)<<"2. Total cats at PurrHouse"<<endl;
    cout<<setw(37)<<"3. Youngest purr"<<endl;
    cout<<setw(35)<<"4. Oldest purr"<<endl;
    cout<<setw(46)<<"5. Emergency vet contacts"<<endl;

    cout<<endl<<setw(39)<<"Enter your query: ";
}

void InfoCenter::aboutus()
{
    d.topBorder("Who Are We?", 4);
    cout<<endl<<endl;
    cout<<setw(42)<<"Every cat has a story."<<endl;
    cout<<setw(95)<<"Some were abandoned, some lost their homes and others never felt love until"<<endl;
    cout<<setw(100)<<"they reached our doorstep. At the PurrHouse, we believe every whisker, every paw"<<endl;
    cout<<setw(75)<<"and every purr deserves proper love, care and kindness."<<endl<<endl<<endl;
    cout<<setw(65)<< "Our Journey"<<endl<<endl;
    cout<<setw(93)<<"It started when we saw the amount of stray cats left behind with no care "<<endl;
    cout<<setw(108)<<"and shelter. Many cats experience violence by humans or other animals who dislike them, "<<endl;
    cout<<setw(104)<<"then came the principle that we follow till this day:  No cat should be left behind."<<endl;
    cout<<setw(104)<<"Rescuing cats, taking care of them and growing them within a loving family. This has"<<endl;
    cout<<setw(72)<<"been the main goal at The 'PurrHouse' since day one."<<endl<<endl<<endl;

    cout<<setw(68)<<"What do We Offer?"<<endl<<endl;
    cout<<setw(98)<<"Adopt a Cat: Looking for a furry companion? Our adoption process ensures every"<<endl;
    cout<<setw(60)<<"cat finds a caring and trustworthy home."<<endl;
    cout<<setw(98)<<"Donate a Cat: If you can no longer care for a cat, we offer a safe place where"<<endl;
    cout<<setw(46)<<"they will be looked after."<<endl;
    cout<<setw(94)<<"Fundraising & Support: Every donation helps us provide food, medical care,"<<endl;
    cout<<setw(55)<<"and a better future for these cats."<<endl<<endl;

    cout<<setw(69)<<"Why Adopt from Us?"<<endl<<endl;
    cout<<setw(44)<<"Because love is rescued."<<endl;
    cout<<setw(102)<<"Each cat in our care has their own story, a soul and a heart that longs for a warm"<<endl;
    cout<<setw(88)<<"hug and home. When you adopt from us, you're not just getting a pet,"<<endl;
    cout<<setw(94)<<"you're welcoming a new member who will love you unconditionally. Sometimes"<<endl;
    cout<<setw(83)<<"the best thing in life is to own a soul with fur and four paws."<<endl<<endl;

    cout<<setw(79)<<"Every Purr deserves care. Join Us and make a difference. <3"<<endl;

}

void InfoCenter::getcatlist()
{

    int i=0;

    ifstream infile("store.txt");
    if (!infile.is_open())
    {
        cout << "Error: Could not open file for reading." << endl;
        return;
    }
    string stname,stpass,stcatID,cname,stbreed,sthealth_condition,STatus;
    char stgender;
    int stage;
    while (infile >> stname >> stpass >> stcatID >> cname >> stbreed >> sthealth_condition >> stgender >> stage >> STatus)
    {
        if(STatus=="Available")
        {
           cats[i].setcatID(stcatID);
           cats[i].setname(cname);
           cats[i].setbreed(stbreed);
           cats[i].setgender(stgender);
           cats[i].setage(stage);
           cats[i].setstatus(STatus);
           i++;
        }

    }
    total=i;
    infile.close();
}
void InfoCenter::showSmallest()
{
    d.topBorder("Youngest Cat", 5);
    if (total == 0)
    {
        cout << setw(65) << "No cats available.\n";
        return;
    }

    Cat smallestcat = cats[0];

    for (int i = 1; i < total; i++)
    {
        if (cats[i] < smallestcat)
        {
            smallestcat = cats[i];
        }
    }
    cout<<endl;
    cout << setw(59) << " CatID: " << smallestcat.getcatID() << endl;
    cout << setw(58) << " Name: " << smallestcat.getname() << endl;
    cout << setw(59) << " Breed: " << smallestcat.getbreed() << endl;
    cout << setw(60) << " Gender: " << smallestcat.getgender() << endl;
    cout << setw(57) << " Age: " << smallestcat.getAge() << endl;
    cout << setw(60) << " Status: " << smallestcat.getstatus() << endl;
}


void InfoCenter::showoldest()
{
    d.topBorder("Oldest Cat", 4);
    cout<<endl<<endl;
    if (total == 0)
    {
        cout << setw(65) << "No cats available.\n";
        return;
    }

    Cat oldestcat = cats[0];

    for (int i = 1; i < total; i++)
    {
        if (cats[i] > oldestcat )
        {
            oldestcat = cats[i];
        }
    }

    cout << setw(59) << "  CatID: " << oldestcat.getcatID() << endl;
    cout << setw(58) << "  Name: " << oldestcat.getname() << endl;
    cout << setw(59) << "  Breed: " << oldestcat.getbreed() << endl;
    cout << setw(60) << "  Gender: " << oldestcat.getgender() << endl;
    cout << setw(57) << "  Age: " << oldestcat.getAge() << endl;
    cout << setw(60) << "  Status: " << oldestcat.getstatus() << endl;
}


void InfoCenter::totalcats()
{
    d.topBorder("Cats at PurrHouse",7);
    cout<<setw(65)<<"  TOTAL CATS AT PURRHOUSE: "<<total<<endl;

    map<string,int> umap;
    for(int i=0;i<total;i++)
    {
        umap[cats[i].getbreed()]++;
    }
    cout<<endl;
    cout<<setw(65)<<"Breed Count:\n"<<endl;

    for (auto x : umap)
    {
        cout <<setw(60) << x.first
             << setw(5) << x.second << endl;
    }

}

void InfoCenter::vetcontacts(){
    d.topBorder("Emergency Contacts", 8);
    cout<<endl;
    cout<<setw(79)<<"- Dr. Didhiti Nahid (Dhaka Animal Clinic)\n";
    cout<<setw(62)<<"Phone no. 015371-44633\n";
    cout<<setw(80)<<"- Dr. Saeera Tanjim (Rangpur Pet Hospital)\n";
    cout<<setw(62)<<"Phone no. 017736-76096\n";
    cout<<setw(79)<<"- Dr. Anjim Hossain (Uttara Pet Wellness)\n";
    cout<<setw(62)<<"Phone no. 015214-40197\n";
    cout<<setw(83)<<"- Dr. Salsabil Saed (Cairo Veterinary Clinic)\n";
    cout<<setw(62)<<"Phone no. 018158-94417\n";

}







