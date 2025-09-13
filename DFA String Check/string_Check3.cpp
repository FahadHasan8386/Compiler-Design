#include <bits/stdc++.h>
using namespace std;

/// a(a+b)*
bool check_a_ab_star(const string &s) {
    if (s.empty()) return false;
    if (s[0] != 'a') return false;

    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != 'a' && s[i] != 'b') return false;
    }
    return true;
}

/// b
bool check_b(const string &s) {
    return (s.size() == 1 && s[0] == 'b');
}

/// a(a+b)* + b
bool check(const string &s) {
    return check_a_ab_star(s) || check_b(s);
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
