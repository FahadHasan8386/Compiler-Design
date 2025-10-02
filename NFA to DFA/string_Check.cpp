#include <bits/stdc++.h>
using namespace std;

///  a(a+b)
bool check_a_ab_star(const string &s) {
    if (s.empty()) return false;
    if (s[0] != 'a') return false;

    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("string_01.txt");
    if (!fin.is_open()) {
        cout << "File not found!" << endl;
        return 0;
    }

    string line;
    while (getline(fin, line)) {
        if (check_a_ab_star(line))
            cout << "Accepted: " << line << endl;
        else
            cout << "Rejected: " << line << endl;
    }
    fin.close();
    return 0;
}
