#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    vector<int> cnt(26);
    for (auto &x : a)
        cnt[x - 'A']++;
    int f = 0 ;
    for (auto &x : cnt)
        if (x % 2 == 1)
            f++;
    if (f > 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 0) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                cout << char(i + 'A');
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << char(i + 'A');
            }
        }
    }
    for (int i = 25; i >= 0; i--) {
        if (cnt[i] % 2 == 0) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                cout << char(i + 'A');
            }
        }
    }
    cout << endl;
    return 0;
}