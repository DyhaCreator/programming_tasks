#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int del = 1;
    int ans = n;
    for (int del = 1; del <= n; del++) {
        if (n % del == 0) {
            vector<vector<int>> a(del, vector<int>(26));
            for (int i = 0; i < n; i++)
                a[i % del][s[i] - 'a']++;
            /*for (auto &x : a) {
                for (auto &y : x)
                    cout << y << " ";
                cout << endl;
            }
            cout << endl;*/
            int f = 0;
            for (auto &x : a) {
                int cnt = 0;
                int cnt2 = 0;
                for (auto &y : x) {
                    if (y > 1) {
                        cnt++;
                    }
                    if (y > 0) {
                        cnt2++;
                    }
                }
                if (cnt > 1) {
                    f = 1;
                }
                if (cnt2 > 2) {
                    f = 1;
                }
            }
            // cout << f << endl;
            int f2 = 0;
            for (auto &x : a) {
                int cnt = 0;
                for (auto &y : x) {
                    if (y > 0) {
                        cnt++;
                    }
                }
                if (cnt > 1) {
                    f2++;
                }
            }
            if (f == 0 && f2 <= 1) {
                cout << del << endl;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}