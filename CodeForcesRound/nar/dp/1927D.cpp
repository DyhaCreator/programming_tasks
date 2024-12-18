#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> left(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] == a[i]) st.pop();
        if (st.empty()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    vector<int> right(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] == a[i]) st.pop();
        if (st.empty()) right[i] = INF;
        else right[i] = st.top();
        st.push(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        if (left[r] >= l) {
            cout << r + 1 << " " << left[r] + 1 << endl;
        } else if (right[l] <= r) {
            cout << l + 1 << " " << right[l] + 1 << endl;
        } else {
            cout << -1 << " " << -1 << endl;
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}