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

ll solve1(string a) {
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
        return num(a, b);
    } else {
        string mx = a;
        ll mx_sum = 0;
        vector<int> p(cnt);
        rec(p, 0, a, b, mx, mx_sum);
        return mx_sum;
    }
}

ll solve2(string a) {
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
                        c.push_back(p[index] + 'A');
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
    return num(c, b);
}


int main() {
    for (int i = 0; i < 100000; i++) {
        int n = 6;
        string a = "";
        for (int j = 0; j < n; j++) {
            int r = rand() % 26;
            if (r > 25) {
                a.push_back('?');
            } else {
                a.push_back(r + 'A');
            }
        }
        int l = rand() % n;
        int r = rand() % n;
        int k = rand() % n;
        a[l] = '?';
        a[r] = '?';
        a[k] = '?';
        // cout << a << endl;
        if (solve1(a) != solve2(a)) {
            cout << a << endl;
            cout << solve1(a) << endl;
            cout << solve2(a) << endl;
        }
    }
    return 0;
}