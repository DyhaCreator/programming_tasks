#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll max_mult = 2000000000000000000;

ll nod(ll a, ll b) {
    if (a < b) swap(a, b);
    while (a % b != 0) {
        a %= b;
        swap(a, b);
    }
    return b;
}

int main() {
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    vector<pair<ll, ll>> d(n);
    for (auto &[l, r] : d)
        cin >> l >> r;
    ll mx = 0;
    for (auto &[l, r] : d)
        mx = max(mx, r);
    ll ln = a * b;
    if (b < a) {
        if (a - b == 1 || a % (a - b - 1) == 0)
            ln = a * b / (a - (b + 1) % a);
    } else if (b > a) {
        if ((b - a + 1) % a == 0 || a % (b - a + 1) == 0)
            ln = a * b / (a - (b + 1) % a);
    } else {
        ln = a * b;
    }
    cout << ln << endl;
    if (max_mult / a < b || max_mult / b < a || ln > mx) {
        ll sum = 0;
        for (auto &[l, r] : d)
            sum += r - l + 1;
        cout << sum << endl;
        return 0;
    }
    for (auto &[l, r] : d) {
        if (r / ln - l / ln > 1) {
            cout << ln << endl;
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
    cout << sum << endl;
    return 0;
}