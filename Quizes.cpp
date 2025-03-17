#include "Quizes.h"
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include<fstream>
#include<sstream>
Quizes::Quizes()
{
     loadQuestionsFromFile("Questions.txt");
}

void Quizes::loadQuestionsFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file,line)) {
        stringstream ss(line);
        string questionText, option, correctOptStr;
        vector<string> options;
        int correctOpt;

        getline(ss, questionText, '|');
        for(int i=0;i<4;i++){
            getline(ss, option, '|');
            options.push_back(option);
        }
        getline(ss, correctOptStr);
        correctOpt=stoi(correctOptStr);

        ques.push_back({questionText, options, correctOpt});
    }
    file.close();
}
int Quizes::startQuiz()
{
    vector<int>selected;
    while (selected.size()<10)
    {
        int randomgeneration=rand()%ques.size();
        if (find(selected.begin(), selected.end(), randomgeneration)==selected.end())
        {
            selected.push_back(randomgeneration);
        }
    }

    int score=0;
    for (int i=0; i<10; i++){
        cout<<endl;
        cout<<endl;
        cout<<setw(67)<<"**QUIZ_TIME**"<<endl<<endl<<endl<<endl;

        const questions& q=ques[selected[i]];
        cout<<endl;
        cout<<setw(42)<<"Q no."<<(i+1)<<": "<<q.text<<endl;
        for (int j=0; j<q.options.size(); j++) {
            cout<<setw(42)<<j+1<<". "<<q.options[j]<<endl;
        }

        int ans;
        bool validinput=false;
        while(!validinput){
            cout<<setw(50)<<"Your answer: ";
            cin>>ans;

            if(cin.fail() || ans<1 || ans>4){
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<setw(65)<<"Invalid input! Please enter a number between 1 and 4."<<endl;
            }
            else{
                validinput=true;
            }
        }
        if (ans==q.correctopt+1){
            cout<<endl;
            cout<<setw(65)<<"YOU ARE CORRECT!"<<endl;
            score++;
        }
        else{
            cout<<endl;
            cout<<setw(60)<<"OOPSIE :("<<endl;
        }
        cout<<endl;
        cout<<setw(75)<<"Please wait to see the next question...";
        cin.ignore();
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("cls");

    }
    return score;

}


Quizes::~Quizes()
{
    //dtor
}
