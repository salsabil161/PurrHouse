#include "Reviews.h"
#include<iostream>
#include<string>
#include<limits>
#include<fstream>
#include<iomanip>
#include<vector>

using namespace std;

// Function to calculate padding for centering text
string centerText(const string& text, int consoleWidth) {
    int padding = (consoleWidth - text.length()) / 2;
    if (padding < 0) padding = 0; // In case text is longer than console width
    return string(padding, ' ') + text;
}

// Function to wrap text into a specific width
vector<string> wrapText(const string& text, int width) {
    vector<string> wrappedLines;
    stringstream ss(text);
    string word, line;

    while (ss >> word) {
        if (line.length() + word.length() + 1 > width) {
            wrappedLines.push_back(line);
            line = word;
        } else {
            if (!line.empty()) line += " ";
            line += word;
        }
    }

    if (!line.empty()) wrappedLines.push_back(line);
    return wrappedLines;
}

void Review::displayReviews(const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << centerText("No reviews available yet.", 120) << endl;
        return;
    }

    string line;
    bool hasContent = false;
    int consoleWidth = 120; // Console width
    int textWidth = 80;     // Text wrapping width

    d.topBorder("Reviews", 3);
    cout<<endl;
    cout << centerText(string(textWidth, '-'), consoleWidth) << endl;

    while (getline(inFile, line)) {
        size_t colonPos = line.find(':');

        if (colonPos == string::npos || colonPos == 0) continue; // Skip invalid lines

        string name = line.substr(0, colonPos);
        string review = line.substr(colonPos + 1);

        cout << centerText(name + ":", consoleWidth) << endl;

        vector<string> wrappedLines = wrapText(review, textWidth);

        for (const string& wLine : wrappedLines) {
            cout << centerText(wLine, consoleWidth) << endl;
        }

        cout << endl;
        hasContent = true;
    }

    if (!hasContent) {
        cout << centerText("No valid reviews found in the file.", consoleWidth) << endl;
    }

    cout << centerText(string(textWidth, '-'), consoleWidth) << endl;

    inFile.close();
}


void Review::addReview(const string& filename, string name){
    string username, review;

    cout<<setw(39)<<"Write your review: ";
    getline(cin, review);
    cout<<endl;
    username=name;

    ofstream outFile(filename, ios::app);

    if(outFile.is_open()){
    outFile<<username<<": ";
    outFile<<review<<endl<<endl;
    cout<<setw(66)<<"Thank you for your review!"<<endl;
    cin.ignore();
    }
    else{
        cout<<"Unable to send review :( \nCheck your network connectivity"<<endl;
    }
    outFile.close();
}

