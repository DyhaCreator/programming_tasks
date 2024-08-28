#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    ll minj = 0;
    ll ans1 = -2, ans2 = -2;
    ll maxR = k;
    for (int i = 1; i < n; i++) {
        if (maxR == -1 || (k / a[minj]) * b[i] > maxR) {
            ans1 = minj;
            ans2 = i;
            maxR = (k / a[minj]) * b[i];
        }
        if (a[i] < a[minj])
            minj = i;
    }
    cout << maxR << endl;
    cout << ans1 + 1 << " " << ans2 + 1 << endl;
    return 0;
}