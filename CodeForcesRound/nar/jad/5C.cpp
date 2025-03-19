#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<int> l(n);
    int len = 0;
    int cnt = 1;
    for (int i = 0; i < n;) {
        int cnt0 = 0;
        int cnt1 = 0;
        int index = i;
        while (index < n && cnt0 >= cnt1) {
            if (a[index] == '(') {
                cnt0++;
            } else {
                cnt1++;
            }
            if (cnt0 == cnt1) {
                l[i] = max(l[i], index - i + 1);
            }
            index++;
        }
        i = index;
    }
    vector<int> r(n);
    reverse(a.begin(), a.end());
    for (int i = 0; i < n;) {
        int cnt0 = 0;
        int cnt1 = 0;
        int index = i;
        while (index < n && cnt0 >= cnt1) {
            if (a[index] == ')') {
                cnt0++;
            } else {
                cnt1++;
            }
            if (cnt0 == cnt1) {
                r[i] = max(r[i], index - i + 1);
            }
            index++;
        }
        i = index;
    }
    reverse(r.begin(), r.end());
    for (int i = 0; i < n; i++) {
        if (l[i] != 0) {
            r[i + l[i] - 1] = 0;
        }
    }
    /*for (auto &x : l)
        cout << x << " ";
    cout << endl;
    for (auto &x : r)
        cout << x << " ";
    cout << endl;*/
    for (auto &x : l) {
        if (x > len) {
            len = x;
            cnt = 1;
        } else if (x == len && len != 0) {
            cnt++;
        }
    }
    for (auto &x : r) {
        if (x > len) {
            len = x;
            cnt = 1;
        } else if (x == len && len != 0) {
            cnt++;
        }
    }
    cout << len << " " << cnt << endl;
    return 0;
}