#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll num(string &a, vector<ll> &b) {
    ll sum = 0;
    stack<char> st;
    st.push(-1);
    for (int i = a.size() - 1; i >= 0; i--) {
        while (st.top() != -1 && st.top() <= a[i]) {
            st.pop();
        }
        if (st.top() == -1) {
            sum += b[a[i] - 'A'];
        } else {
            sum -= b[a[i] - 'A'];
        }
        st.push(a[i]);
    }
    return sum;
}

void rec(vector<int> &p, int index, 
    string &a, vector<ll> &b, string &mx, ll &mx_sum) {
    if (index == p.size()) {
        string c = "";
        int i = 0;
        for (auto &x : a) {
            if (x == '?') {
                c.push_back(p[i] + 'A');
                i++;
            } else {
                c.push_back(x);
            }
        }
        ll cnt = num(c, b);
        if (cnt > mx_sum) {
            mx = c;
            mx_sum = cnt;
        }
        return;
    }
    for (int i = 0; i < 26; i++) {
        p[index] = i;
        rec(p, index + 1, a, b, mx, mx_sum);
    }
}

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    vector<ll> b(26);
    b[0] = 1;
    for (int i = 1; i < 26; i++) {
        b[i] = b[i - 1];
        if (i % 2 == 0) {
            b[i] *= 2;
        } else {
            b[i] *= 5;
        }
    }
    int cnt = 0;
    for (auto &x : a)
        if (x == '?') cnt++;
    if (cnt == 0) {
        cout << num(a, b) << endl;
        cout << a << endl;
    } else {
        string mx = a;
        ll mx_sum = 0;
        vector<int> p(cnt);
        rec(p, 0, a, b, mx, mx_sum);
        cout << mx_sum << endl;
        cout << mx << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}