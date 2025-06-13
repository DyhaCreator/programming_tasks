#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct ms{
    vector<ll> a;
    vector<ll> l;
    vector<ll> r;
    ll beg;
    ll end;
    ll sum;
    ll ans;
    ms(ll f) {
        a.push_back(f);
        l.push_back(0);
        r.push_back(0);
        beg = 0;
        end = 0;
        sum = f;
        ans = f;
    }

    ll add(ll n) {
        r[end] = a.size();
        l[beg] = a.size();
        a.push_back(n);
        l.push_back(end);
        r.push_back(beg);
        end = a.size();
    }
};

void solve() {
    
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}