#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll max_mult = 2000000000000000000;

int solve1(ll n, ll a, ll b, vector<pair<ll, ll>> d) {
    set<pair<ll, ll>> st;
    for (auto &[l, r] : d) {
        for (ll t = l; t <= r; t++) {
            st.insert({(t + (t / b)) % a, t % b});
        }
    }
    return st.size();
    return 0;
}

int solve2(ll n, ll a, ll b, vector<pair<ll, ll>> d) {
    ll mx = 0;
    for (auto &[l, r] : d)
        mx = max(mx, r);
    ll ln = a * b;
    if (b < a) {
        if (a - b == 1 || a % (a - b - 1) == 0 || (a - b - 1) % a == 0)
            ln = a * b / (a - (b + 1) % a);
    } else if (b > a) {
        if ((b - a + 1) % a == 0 || a % (b - a + 1) == 0)
            ln = a * b / (a - (b + 1) % a);
    } else {
        ln = a * b;
    }
    if (max_mult / a < b || max_mult / b < a || ln > mx) {
        ll sum = 0;
        for (auto &[l, r] : d)
            sum += r - l + 1;
        return sum;
        return 0;
    }
    for (auto &[l, r] : d) {
        if (r / ln - l / ln > 1) {
            return ln;
            return 0;
        }
    }
    vector<pair<ll, ll>> st = {};
    for (auto &[l, r] : d) {
        if (r / ln == l / ln) {
            st.push_back({l % ln, r % ln});
        } else {
            st.push_back({l % ln, ln - 1});
            st.push_back({0, r % ln});
        }
    }
    sort(st.begin(), st.end());
    vector<pair<ll, ll>> c = {};
    for (auto &[l, r] : st) {
        if (c.size() == 0) {
            c.push_back({l, r});
        } else if (c.back().second + 1 >= l) {
            c[c.size() - 1].second = max(c[c.size() - 1].second, r);
        } else {
            c.push_back({l, r});
        }
    }
    /*for (auto &[l, r] : c)
        cout << l << " " << r << endl;
    cout << endl;*/
    ll sum = 0;
    for (auto &[l, r] : c)
        sum += r - l + 1;
    return sum;
    return 0;
}

int main() {
    for (int t = 0; t < 1000; t++) {
        ll n = rand() % 5 + 1;
        ll b = rand() % 16 + 1;
        ll a = rand() % b + 1;
        vector<pair<ll, ll>> d = {};
        ll last = 0;
        for (int i = 0; i < n; i++) {
            last += rand() % 16 + 1;
            ll r = rand() % 16 + 1;
            d.push_back({last, last + r});
            last += r;
        }
        if (solve1(n, a, b, d) != solve2(n, a, b, d)) {
            cout << n << " " << a << " " << b << endl;
            for (auto &[l, r] : d)
                cout << l << " " << r << endl;
            cout << solve1(n, a, b, d) << " " << solve2(n, a, b, d) << endl;
            cout << "-----" << endl;
        }
    }
    return 0;
}