#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    a.push_back(0);
    ll sum = 0;
    ll ans = INF;
    ll index = 0;
    for (int i = 0; i <= n; i++) {
        if (i >= k) {
            if (ans > sum) {
                index = i - k;
                ans = sum;
            }
            sum -= a[i - k];
        }
        sum += a[i];
    }
    cout << index + 1 << endl;
    return 0;
}