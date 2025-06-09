#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    getline(cin, s);
    vector<string> a = {""};
    for (auto &x : s) {
        if (x == '.') {
            a.push_back("");
        } else {
            if (a[a.size() - 1].size() != 0 || x != ' ')
                a[a.size() - 1].push_back(x);
        }
    }
    a.pop_back();
    for (auto &x : a) {
        vector<string> b = {""};
        for (auto &y : x) {
            if (y == ' ') {
                b.push_back("");
            } else {
                b[b.size() - 1].push_back(y);
            }
        }
        reverse(b.begin(), b.end());
        for (int i = 0; i < b.size() - 1; i++) 
            cout << b[i] << " ";
        cout << b[b.size() - 1] << ". ";
    }
    cout << endl;
    return 0;
}