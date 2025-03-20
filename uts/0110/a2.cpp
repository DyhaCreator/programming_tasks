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
    vector<int> p(cnt, 0);
    for (int i = 0; i < cnt; i++) {
        ll mx = 0;
        ll mx_sum = 0;
        for (int j = 0; j < 26; j++) {
            p[i] = j;
            string c = "";
            int index = 0;
            for (auto &x : a) {
                if (x == '?') {
                    if (index <= i) {
                        c.push_back(p[index] + 'A');
                        index++;
                    } else {
                        c.push_back('Z');
                    }
                } else {
                    c.push_back(x);
                }
            }
            ll sum = num(c, b);
            if (sum > mx_sum) {
                mx_sum = sum;
                mx = j;
            }
            // cout << c << endl;
        }
        p[i] = mx;
    }
    string c = "";
    int index = 0;
    for (auto &x : a) {
        if (x == '?') {
            if (index < cnt) {
                c.push_back(p[index] + 'A');
                index++;
            }
        } else {
            c.push_back(x);
        }
    }
    cout << num(c, b) << endl;
    cout << c << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}