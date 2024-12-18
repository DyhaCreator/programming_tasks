#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll ans = 0;

bool comp(int a, int b) {
    if (a < b) ans++;
    return a < b;
}

vector<ll> sort(vector<ll>a) {
    if (a.size() <= 1) {
        return a;
    }
    ll middle = (a.size() / 2);
    vector<ll>l(a.begin(), a.begin() + middle);
    vector<ll>r(a.begin() + middle, a.end());
    l = sort(l);
    r = sort(r);
    ll l_it = 0;
    ll r_it = 0;
    a = vector<ll>();
    while (l_it < l.size()) {
        while (l[l_it] > r[r_it] && r_it < r.size()) {
            ans += l.size() - l_it;
            a.push_back(r[r_it]);
            r_it++;
        }
        a.push_back(l[l_it]);
        l_it++;
    }
    while (r_it < r.size()) {
        a.push_back(r[r_it]);
        r_it++;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, l;
    cin >> n >> l;
    vector<ll>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    vector<ll>b = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        b[i] = l * a[i] + i;
    }
    sort(b);
    cout << ans << endl;
    return 0;
}