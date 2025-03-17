#include "Cover.h"



Cover::Cover(int height): terminalHeight(height){}

void Cover::verticalSpacing(const vector<string>& lines) {
        int artHeight = lines.size();
        int verticalPadding = (terminalHeight - artHeight) / 2;

        for (int i = 0; i < verticalPadding; i++) {
            cout << endl;
        }
}

void Cover::horizontalSpacing(const vector<string>& lines) {
        for (const string& line : lines) {
            int horizontalPadding = (terminalWidth - line.length()) / 2;
            cout << string(horizontalPadding, ' ') << line << endl;
        }
}

Cover::~Cover()
{
    //dtor
}
