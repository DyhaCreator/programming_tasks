#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int q;
    cin >> q;
    vector<int> a = {};
    while (q != -1) {
        a.push_back(q) ;
        if (q == 0) {
            a.pop_back();
            int ans = 0;
            for (auto &x : a) {
                for (auto &y : a) {
                    if (x == y * 2) {
                        ans++;
                    }
                }
            }
            cout << ans << endl;
            a = {};
        }
        cin >> q;
    }
    return 0;
}