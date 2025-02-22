#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool comp(string &a, string &b) {
    int l = 0, r = 0;
    for (auto &x : a) {
        if (x == '0') l++;
        else l = 0;}
    for (auto &x : b) {
        if (x == '0') r++;
        else r = 0;}

    return l > r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end(), comp);
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        int d = 0;
        for (auto &x : a[i]) {
            if (x == '0') d++;
            else d = 0;}
        l[i] = d;
    }
    ll sum = 0;
    for (auto &x : a)
        sum += x.size();
    for (int i = 0; i < n; i += 2)
        sum -= l[i];
    if (sum > k) {
        cout << "Sasha" << endl;
    } else {
        cout << "Anna" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}