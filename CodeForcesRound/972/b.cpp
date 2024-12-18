#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n, m, q;

int localSolve(ll a, ll b) {
    // cout << a << " " << b << endl;
    cout << min(b - (a + b) / 2, (a + b) / 2 - a) << endl;
    return 0;
}

int solve() {
    cin >> n >> m >> q;
    vector<ll> b(m);
    vector<ll> a(q);
    for (auto &x : b)
        cin >> x;
    for (auto &x : a)
        cin >> x;
    /*set<ll> st;
    for (auto &x : b)
        st.insert(x);
    b.clear();
    for (auto &x : st)
        b.push_back(x);*/
    /*for (auto &x : b)
        cout << x << " ";
    cout << endl;*/
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    // int index = 0;
    for (int i = 0; i < q; i++) {
        if (a[i] < b[0]) {
            cout << b[0] - 1 << endl;
        } else if (a[i] > b[m - 1]) {
            cout << n - b[m - 1] << endl;
        } else {
            int l = 0;
            int r = m;
            while (l < r) {
                int m = (l + r) / 2;
                if (b[m] < a[i]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            int index = r;
            // cout << b[r] << endl;
            /*while (index < b.size() && b[index] < a[i])
                index++;*/
            localSolve(b[index - 1], b[index]);
            // cout << min(b[1] - (b[0] + b[1]) / 2, (b[0] + b[1]) / 2 - b[0]) << endl;
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}