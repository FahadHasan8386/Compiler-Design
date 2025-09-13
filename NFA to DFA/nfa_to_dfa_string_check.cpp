#include <bits/stdc++.h>
using namespace std;

enum State {
    Q0Q2,
    Q1Q2,
    Q3,
    Q2,
    Q0Q2Q3,
    Q4,
    Q1Q2Q4,
    Q0Q2Q3Q5,
    Q1Q2Q3Q4,
    Q2Q4,
    Q3Q5,
    Q3Q4,
    Q5,
    DEAD
};

bool isFinalState(State s) {
    return (s == Q3 || s == Q0Q2Q3 || s == Q0Q2Q3Q5 ||
            s == Q1Q2Q3Q4 || s == Q3Q5 || s == Q3Q4);
}

State transition(State current, char input) {
    switch (current) {
        case Q0Q2:
            if (input == 'b') return Q1Q2;
            if (input == 'a') return Q3;
            break;
        case Q1Q2:
            if (input == 'b') return Q2;
            if (input == 'a') return Q0Q2Q3;
            break;
        case Q2:
            if (input == 'a') return Q3;
            if (input == 'b') return Q2;
            break;
        case Q3:
            if (input == 'a') return Q3;
            if (input == 'b') return Q4;
            break;
        case Q4:
            if (input == 'a') return Q5;
            break;
        case Q5:
            if (input == 'a') return Q3;
            if (input == 'b') return Q3;
            break;
        case Q0Q2Q3:
            if (input == 'a') return Q3;
            if (input == 'b') return Q1Q2Q4;
            break;
        case Q1Q2Q4:
            if (input == 'a') return Q0Q2Q3Q5;
            if (input == 'b') return Q2;
            break;
        case Q0Q2Q3Q5:
            if (input == 'a') return Q3;
            if (input == 'b') return Q1Q2Q3Q4;
            break;
        case Q1Q2Q3Q4:
            if (input == 'a') return Q0Q2Q3Q5;
            if (input == 'b') return Q2Q4;
            break;
        case Q2Q4:
            if (input == 'a') return Q3Q5;
            if (input == 'b') return Q2;
            break;
        case Q3Q5:
            if (input == 'a') return Q3;
            if (input == 'b') return Q3Q4;
            break;
        case Q3Q4:
            if (input == 'a') return Q3Q5;
            if (input == 'b') return Q4;
            break;
        default:
            return DEAD;
    }
    return DEAD;
}

bool is_valid_expression(const string& input) {
    State current_state = Q0Q2;
    for (char c : input) {
        if (c != 'a' && c != 'b') return false;
        current_state = transition(current_state, c);
        if (current_state == DEAD) return false;
    }
    return isFinalState(current_state);
}

int main() {
    string test;

    cout << "Write stop to stop the program" << endl;

    while (true) {
        cout << "Enter a string: ";
        getline(cin, test);

        if (test == "stop") break;

        if (is_valid_expression(test))
            cout << "Accepted" << endl;
        else
            cout << "Rejected" << endl;
    }

    cout << "Program End." << endl;
    return 0;
}
