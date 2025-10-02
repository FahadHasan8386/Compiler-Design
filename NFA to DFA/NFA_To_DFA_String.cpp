#include <bits/stdc++.h>
using namespace std;

/// ba*
bool match_ba_star(const string &s) {
    if (s.empty()) return false;
    if (s[0] != 'b') return false;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != 'a') return false;
    }
    return true;
}

/// b*
bool check_b_star(const string &s) {
    for (char c : s) {
        if (c != 'b') return false;
    }
    return true;
}

/// a
bool check_a(const string &s) {
    if (s.empty()) return false;
    return (s == "a");
}

/// [a + ba(a+b)]*
bool match_expr(const string &s) {
    int i = 0;
    while (i < s.size()) {
        if (s[i] == 'a') {
            i++;
        } else if (i + 2 < s.size() && s[i] == 'b' && s[i+1] == 'a' && (s[i+2] == 'a' || s[i+2] == 'b')) {
            i += 3;
        } else {
            return false;
        }
    }
    return true;
}

/// master check function
bool check(const string &s) {
    return match_ba_star(s) || check_b_star(s) || check_a(s) || match_expr(s);
}

int main() {
    ifstream fin("string_03.txt");
    if (!fin) {
        cout << "File not found!" << endl;
        return 0;
    }

    string line;
    while (getline(fin, line)) {
        if (check(line))
            cout << "Accepted: " << line << endl;
        else
            cout << "Rejected: " << line << endl;
    }

    fin.close();
    return 0;
}
