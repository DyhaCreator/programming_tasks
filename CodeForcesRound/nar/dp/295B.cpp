#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const ll INF = 1e18 + 7LL;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> m(n, vector<ll>(n));
    for (auto &x : m)
        for (auto &y : x)
            cin >> y;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a)
        x--;
    reverse(a.begin(), a.end());
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    vector<ll> b = {};
    vector<vector<ll>> m2(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++)
        m2[i][i] = 0;
    vector<ll> ans = {};
    for (int i = 0; i < n; i++) {
        for (auto &x : b) {
            m2[a[i]][x] = m[a[i]][x];
            m2[x][a[i]] = m[x][a[i]];
        }
        b.push_back(a[i]);

        vector<ll> d(n, INF);
        set<pair<ll, ll>> st;
        d[a[i]] = 0;
        for (auto &x : b)
            st.insert({d[x], x});
        for (int i = 0; i < b.size(); i++) {
            ll v = st.begin()->S;
            st.erase(*st.begin());
            for (auto &x : b) {
                if (d[x] > d[v] + m2[v][x]) {
                    st.erase({d[x], x});
                    d[x] = d[v] + m2[v][x];
                    st.insert({d[x], x});
                }
            }
        }
        vector<ll> d2(n, INF);
        d2[a[i]] = 0;
        for (auto &x : b)
            st.insert({d2[x], x});
        for (int i = 0; i < b.size(); i++) {
            ll v = st.begin()->S;
            st.erase(*st.begin());
            for (auto &x : b) {
                if (d2[x] > d2[v] + m2[x][v]) {
                    st.erase({d2[x], x});
                    d2[x] = d2[v] + m2[x][v];
                    st.insert({d2[x], x});
                }
            }
        }

        for (int l = 0; l < n; l++) {
            for (int r = 0; r < n; r++) {
                dp[l][r] = min(dp[l][r], d2[l] + d[r]);
            }
        }
        
        /*for (auto &x : dp) {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }*/
        
        ll sum = 0;
        for (auto &x : dp) {
            for (auto &y : x)
                if (y != INF) sum += y;
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}