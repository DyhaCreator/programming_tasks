#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000000007
using namespace std;

ll f(string num, ll k) {
    ll ans = 0;
    for (auto &x : num)
        ans = (ans * 10 + x - '0') % k;
    return ans;
}

int main() {
    string str;
    ll k;
    cin >> str >> k;
    ll m;
    cin >> m;
    vector<ll> d(m);
    for (auto &x : d)
        cin >> x;
    ll tOst = f(str, k);

    vector<pair<ll, ll>> prev(k, {-1, -1});
    vector<ll> used(k, INF);
    used[tOst] = 0;
    queue<ll> q;
    q.push(tOst);

    while (!q.empty()) {
        ll ost = q.front();
        // cout << ost << endl;
        q.pop();

        for (auto &x : d) {
            ll ost2 = (ost * 10 + x) % k;
            if (used[ost2] == INF) {
                q.push(ost2);
                used[ost2] = used[ost] + 1;
                prev[ost2] = {ost, x};
            }
        }
    }

    if (used[0] == INF) {
        cout << -1 << endl;
        return 0;
    }

    // cout << used[0] << endl;

    vector<ll> ans = {};
    ll p = 0;
    while (p != -1) {
        ans.push_back(prev[p].second);
        p = prev[p].first;
    }

    reverse(ans.begin(), ans.end());

    cout << str;
    for (ll i = 1; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}