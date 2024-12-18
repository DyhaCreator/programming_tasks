#include <iostream>
#include <string>
#define ll long long
using namespace std;

void f(string s) {
    if (s[0] == '?') {
        string a = "";
        a += s[1];
        a += s[2];
        if (a == "AB" || a == "BA") {
            cout << "C" << endl;
        } else if (a == "AC" || a == "CA") {
            cout << "B" << endl;
        } else if (a == "CB" || a == "BC") {
            cout << "A" << endl;
        }
    } else if (s[1] == '?') {
        string a = "";
        a += s[0];
        a += s[2];
        if (a == "AB" || a == "BA") {
            cout << "C" << endl;
        } else if (a == "AC" || a == "CA") {
            cout << "B" << endl;
        } else if (a == "CB" || a == "BC") {
            cout << "A" << endl;
        }
    } else if (s[2] == '?') {
        string a = "";
        a += s[1];
        a += s[0];
        if (a == "AB" || a == "BA") {
            cout << "C" << endl;
        } else if (a == "AC" || a == "CA") {
            cout << "B" << endl;
        } else if (a == "CB" || a == "BC") {
            cout << "A" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        f(s);
        cin >> s;
        f(s);
        cin >> s;
        f(s);
    }
    return 0;
}