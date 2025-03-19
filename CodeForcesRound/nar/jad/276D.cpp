#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll l, r;
    cin >> l >> r;
    if (l == r) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> a = {};
    vector<int> b = {};
    ll s = l;
    while (s > 0) {
        a.push_back(s % 2);
        s /= 2;
    }
    s = r;
    while (s > 0) {
        b.push_back(s % 2);
        s /= 2;
    }
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    /*for (auto &x : a)
        cout << x << ' ';
    cout << endl;
    for (auto &x : b)
        cout << x << " ";
    cout << endl;*/
    int len = 0;
    while (a[len] == b[len])
        len++;
    int y = 0;
    while ((1LL << y) <= (r % (1LL << (b.size() - len))))
        y++;
    y--;
    // cout << ((1LL << y) ^ ((1LL << y) - 1)) << endl;
    cout << max(((1LL << y) ^ ((1LL << y) - 1)), (r ^ l)) << endl;

    return 0;
}