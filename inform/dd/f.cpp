#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    map<char, int> mp = {
        {'A', 2},
        {'B', 2},
        {'C', 2},
        {'D', 3},
        {'E', 3},
        {'F', 3},
        {'G', 4},
        {'H', 4},
        {'I', 4},
        {'J', 5},
        {'K', 5},
        {'L', 5},
        {'M', 6},
        {'N', 6},
        {'O', 6},
        {'P', 7},
        {'Q', 7},
        {'R', 7},
        {'S', 7},
        {'T', 8},
        {'U', 8},
        {'V', 8},
        {'W', 9},
        {'X', 9},
        {'Y', 9},
        {'Z', 9},
    };
    while (cin >> s) {
        for (auto &x : s) {
            if (mp[x] != 0)
                cout << mp[x];
            else
                cout << x;
        }
        cout << endl;
    }
    return 0;
}