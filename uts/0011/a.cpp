#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int len = 256;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> r(n);
    stack<int> st;
    st.push(n);
    for (int i = n - 1; i >= 0; i--) {
        while (st.top() != n && a[st.top()] >= a[i])
            st.pop();
        r[i] = st.top();
        st.push(i);
    }
    vector<int> dec(n / len + 1, n);
    for (int i = 0; i < n; i++) {
        if (dec[i / len] == n || a[dec[i / len]] <= a[i])
            dec[i / len] = i;
    }
    /*for (auto &x : r)
        cout << x << " ";
    cout << endl;
    for (auto &x : dec)
        cout << x << " ";
    cout << endl;*/
    int index = 0;
    int ans = 0;
    while (index < n) {
        int mx = index;
        for (int i = index; i < r[index];) {
            if (i % len == 0 && i + len - 1 < r[index]) {
                if (a[mx] <= a[dec[i / len]])
                    mx = dec[i / len];
                i += len;
            } else {
                if (a[mx] <= a[i])
                    mx = i;
                i++;
            }
        }
        // cout << a[index] << " " << r[index] << " " << mx << endl;
        index = mx + 1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}