#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string t_to_all(ll a, ll p) {
    string ans = "";
    while (a > 0) {
        ans.push_back(a % p + '0');
        a /= p;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

ll all_to_t(string a, ll p) {
    reverse(a.begin(), a.end());
    ll ans = 0;
    ll st = 1;
    for (auto &x : a) {
        ans += st * (x - '0');
        st *= p;
    }
    return ans;
}

bool sled(bool a, bool b) {
    return a & !b;
}

bool fnd(string a, char b) {
    for (auto &x : a)
        if (x == b) return true;
    return false;
}