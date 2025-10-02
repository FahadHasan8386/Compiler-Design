#include <bits/stdc++.h>
using namespace std;

/// Valid C++ datatypes
set<string> validTypes = {"int", "float", "double", "string"};

/// Trim spaces
string trim(string s) {
    while (!s.empty() && isspace(s.back())) s.pop_back();
    while (!s.empty() && isspace(s.front())) s.erase(s.begin());
    return s;
}

/// Get first word
string getFirstWord(const string &s) {
    stringstream ss(s);
    string word;
    ss >> word;
    return word;
}

/// Function Declaration Checker
bool isDeclaration(string s) {
    s = trim(s);

    if (s.empty() || s.back() != ';') return false;
    if (s.find('(') == -1|| s.find(')') == -1) return false;

    ///Check ()
    int open = 0, close = 0;
    for (char c : s) {
        if (c == '(') open++;
        if (c == ')') close++;
    }
    if (open != 1 || close != 1) return false;

    /// Check valid Datatype
    string firstWord = getFirstWord(s);
    if (validTypes.find(firstWord) == validTypes.end()) return false;

    return true;
}

/// Function Definition Checker
bool isDefinition(string s) {
    s = trim(s);

    if (s.find('(') == string::npos || s.find(')') == string::npos ||
        s.find('{') == string::npos || s.find('}') == string::npos)
        return false;

    /// (){}
    int parOpen = 0, parClose = 0, brOpen = 0, brClose = 0;
    for (char c : s) {
        if (c == '(') parOpen++;
        if (c == ')') parClose++;
        if (c == '{') brOpen++;
        if (c == '}') brClose++;
    }
    if (parOpen != 1 || parClose != 1 || brOpen != 1 || brClose != 1) return false;

    ///Also check data type
    string firstWord = getFirstWord(s);
    if (validTypes.find(firstWord) == validTypes.end()) return false;

    return true;
}

int main() {
    ifstream fin("final_01.txt");
    if (!fin.is_open()) {
        cout << "File not found!" << endl;
        return 0;
    }

    string line;
    while (getline(fin, line)) {
        if (isDeclaration(line)) {
            cout << "Declaration: " << line << endl;
        } else if (isDefinition(line)) {
            cout << "Definition: " << line << endl;
        } else {
            cout << "Invalid: " << line << endl;
        }
    }

    fin.close();
    return 0;
}
