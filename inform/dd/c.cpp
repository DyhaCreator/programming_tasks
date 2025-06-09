#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    set<int> st;
    for (auto &x : a)
        st.insert(x);
    int ans = 0;
    while (st.size() != 1) {
        vector<int> b(n);
        b[n - 1] = a[n - 1] / 2 + a[0] / 2; 
        for (int i = 0; i < n - 1; i++)
            b[i] = a[i] / 2 + a[i + 1] / 2;
        a = b;
        for (auto &x : a)
            if (x % 2 == 1) x++;
        st.clear();
        for (auto &x : a)
            st.insert(x);
        ans++;
    }
    int mx = a[0];
    for (auto &x : a)
        mx = max(mx, x);
    cout << ans << " " << mx << endl;
    return 0;
}