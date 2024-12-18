#include <iostream>
#include <vector>
#include <deque>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    vector<ll>sum = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i - 1];
    vector<ll>pref = vector<ll>(n - k + 1);
    for (int i = 0; i + k <= n; i++) {
        pref[i] = sum[i + k] - sum[i];
    }
    deque<ll>d;
    for (int j = k; j + k <= n; j++) {
        while (!d.empty() && pref[d.back()] <= pref[j]) {
            d.pop_back();
        }
        d.push_back(j);
    }
    ll min = 1e18 + 10;
    for (int i = 1; i + k <= n + 1; i++) {
        ll max = pref[d.front()];
        if (!d.empty() && d.front() < i + k && d.front() > i - k) {
            d.pop_front();
        }
        if (i >= k) {
            while (!d.empty() && pref[d.back()] <= pref[i - k]) {
                d.pop_back();
            }
            d.push_back(i - k);
        }
        if (max < min) {
            min = max;
        }
    }
    cout << min << endl;
    return 0;
}
/*

10 2
1 2 4 5 2 4 2 2 1 6

6 2
4 2 2 3 1 3

*/