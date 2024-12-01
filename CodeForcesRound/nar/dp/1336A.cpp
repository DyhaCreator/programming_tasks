#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int dfs(vector<vector<int>> &g, vector<ll> &ln, vector<ll> &ln2, int index, int len) {
    ln[index] = 1;
    ln2[index] = len;
    int sum = 0;
    for (auto &x : g[index]) {
        if (ln[x] == 0) {
            sum += dfs(g, ln, ln2, x, len + 1);
        }
    }
    ln[index] = sum;
    return sum + 1;
}

bool comp(pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.F - a.S > b.F - b.S;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> ln(n);
    vector<ll> ln2(n);
    dfs(g, ln, ln2, 0, 0);
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = {ln2[i], ln[i]};
    sort(arr.begin(), arr.end(), comp);
    
    ll ans = 0;
    for (int i = 0; i < k; i++)
        ans += arr[i].F - arr[i].S;
    cout << ans << endl;
    return 0;
}