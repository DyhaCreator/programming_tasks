#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
map<ll, ll> mp;
int f = 0;
ll n;

void dfs(ll num, vector<ll> &a) {
    if (a.size() == n) {
        for (auto &x : a)
            cout << x << " ";
        cout << endl;
        f = 1;
        return;
    }
    a.push_back(-1);
    if (mp[num * 2] > 0 && f == 0) {
        a[a.size() - 1] = num * 2;
        mp[num * 2]--;
        dfs(num * 2, a);
        mp[num * 2]++;
    }
    if (mp[num / 3] > 0 && num % 3 == 0 && f == 0) {
        a[a.size() - 1] = num / 3;
        mp[num / 3]--;
        dfs(num / 3, a);
        mp[num / 3]++;
    }
}

int main() {
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a) {
        for (auto &y : a)
            mp[y] = 0;
        for (auto &y : a)
            mp[y]++;
        ll num = x;
        mp[num]--;
        vector<ll> ans = {num};
        dfs(num, ans);
        if (f) break;
    }
    return 0;
}