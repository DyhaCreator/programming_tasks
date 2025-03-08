#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    uint64_t cnt1 = 0;
    uint64_t cnt2 = 0;
    for (auto &x : a)
        if (x == '-') cnt1++;
        else cnt2++;
    cout << (cnt1 / 2) * ((cnt1 + 1) / 2) * cnt2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}