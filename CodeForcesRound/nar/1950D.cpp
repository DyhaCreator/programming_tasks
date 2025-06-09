#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve(vector<int> &c) {
    int n;
    cin >> n;
    if (c[n] == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    vector<int> a;
    for (int i = 1; i <= (1 << 5) + 1; i++) {
        int n = 0;
        int st = 1;
        for (int j = 0; j < 6; j++) {
            n += st * ((i & (1 << j)) > 0);
            st *= 10;
        }
        a.push_back(n);
    }
    vector<int> cnt(100001, 0);
    for (auto &x : a)
        cnt[x] = 1;
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] == 1) {
            for (int j = i; i * j < cnt.size(); j++) {
                if (cnt[j] == 1) {
                    cnt[i * j] = 1;
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--) solve(cnt);
    return 0;
}