#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    getline(cin, s);
    int f = 0;
    char last = ']';
    for (auto &x : s) {
        if (x == ' ' && last != ' ') {
            f++;
        }
        last = x;
    }
    stringstream in(s);
    string str;
    in >> str;
    in >> str;
    if (f == 1) {
        str = " ";
    }
    cout << str << endl;
    return 0;
}

