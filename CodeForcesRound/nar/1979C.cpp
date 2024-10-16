#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    int sum1 = 0;
    set<int> st;
    for (auto &x : a)
        st.insert(x);
    for (auto &x : st)
        cout << x << " ";
    cout << endl;
    for (auto &x : st)
        sum1 += x;
    cout << (sum1 + st.size() - 1) / st.size() << endl;
    if ((sum1 + st.size() - 1) / st.size() <= n) {
        cout << -1 << endl;
        return;
    }
    vector<ll> b(n, 1);
    ll c = 1;
    ll sum = n;
    ll count = 0;
    while (c > 0) {
        c = 0;
        for (int i = 0; i < n; i++) {
            if (sum >= b[i] * a[i]) {
                ll sum2 = sum - b[i];
                b[i] = (sum + a[i]) / a[i];
                sum = sum2 + b[i];
                c++;
            }
        }
        if (count > n * n * n) {
            cout << -1 << endl;
            return;
        }
        for (auto &x : b)
            cout << x << " ";
        cout << endl;
        count++;
    }
    for (auto &x : b)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}