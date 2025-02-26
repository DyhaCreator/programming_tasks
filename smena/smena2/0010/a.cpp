#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    string ans;
    while (cin >> s) {
        for (auto &x : s)
            if (x >= 'A' && x <= 'Z') {
                cout << x;
            }
    }
    return 0;
}