#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, w, k;
    cin >> n >> w >> k;
    vector<ll> cost(w);
    for (auto &x : cost)
        cin >> x;
    vector<ll> cost_b(n);
    for (auto &x : cost_b) {
        ll this_cost = 0;
        for (int i = 0; i < w; i++) {
            ll a;
            cin >> a;
            this_cost += cost[i] * a;
        }
        x = this_cost;
    }
    sort(cost_b.begin(), cost_b.end());
    /*for (auto &x : cost_b)
        cout << x << " ";
    cout << endl;*/
    int cnt = 0, weight = 0;
    for (auto &x : cost_b) {
        if (weight + x <= k) {
            cnt++;
            weight += x;
        }
    }
    cout << cnt << endl;
    return 0;
}