#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    set<pair<pair<ll, ll>, ll>> st;
    for (int i = 0; i < n; i++)
        st.insert({a[i], i});
    /*for (auto &x : st)
        cout << x.F.F << " " << x.F.S << " " << x.S << endl;
    cout << endl;*/
    set<pair<pair<ll, ll>, ll>> st2;
    ll ans = st.begin()->F.F * n;
    ll mx = 0;
    while (st.size() > 0) {
        st2.insert({{-st.begin()->F.S, st.begin()->F.F}, st.begin()->S});
        st.erase(*st.begin());
        for (auto &x : st)
            cout << x.F.F << " " << x.F.S << " " << x.S << endl;
        cout << endl;
        for (auto &x : st2)
            cout << x.F.F << " " << x.F.S << " " << x.S << endl;
        cout << endl;
        ll sum = st.begin()->F.F * st.size();
        ll ind = 1;
        for (auto &x : st2) {
            ans = max(ans, sum + (-x.F.F) * ind);
            ind++;
            cout << (-x.F.F) * ind << endl;
        }
        // ans = max(ans, sum + mx);
        cout << endl;
        // cout << sum << endl;
    }
    cout << ans << endl;
    return 0;
}