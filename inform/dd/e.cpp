#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> cnt(26);
    for (auto &x : b)
        cnt[x - 'a']++;
    for (auto &x : a) {
        if (cnt[x - 'a'] % 2 == 1) {
            cout << x;
        } else {
            cout << ".";
        }
    }
    cout << endl;
    return 0;
}