#include <bits/stdc++.h>
using namespace std;

/// a(a+b)*
bool check_a_ab_star(const string &s) {
    if (s.empty()) return false;
    if (s[0] != 'a') return false;
    for (char c : s) {
        if (c != 'a' && c != 'b') return false;
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

///a(a+b)* + b*
bool check(const string &s) {
    return check_a_ab_star(s) || check_b_star(s);
}

int main() {
    ifstream fin("string_02.txt");
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
