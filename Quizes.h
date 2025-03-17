#ifndef QUIZES_H
#define QUIZES_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class Quizes
{
    private:
        struct questions{
            string text;
            vector<string>options;
            int correctopt;
        };

    vector<questions>ques;

    public:
        Quizes();
        ~Quizes();
        int startQuiz();
        void loadQuestionsFromFile(const string& filename);

};

#endif // QUIZES_H
