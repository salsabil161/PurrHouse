#include "ASCIIArt.h"



ASCIIArt::ASCIIArt(const vector<string>& inputLines) : lines(inputLines) {}

ASCIIArt::~ASCIIArt()
{
    //dtor
}

ASCIIArt ASCIIArt::operator+(const ASCIIArt& other) const {
        vector<string> combinedLines = lines;
        combinedLines.insert(combinedLines.end(), other.lines.begin(), other.lines.end());
        return ASCIIArt(combinedLines);
}

vector<string> ASCIIArt:: getLines() const {
        return lines;
}


string ASCIIArt::toString() const {
        string result;
        for (const string& line : lines) {
            result += line + "\n";
        }
        return result;
    }


