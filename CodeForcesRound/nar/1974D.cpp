#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int num;
    cin >> num;
    string str;
    cin >> str;
    int n = 0, s = 0, e = 0, w = 0;
    for (auto &x : str) {
        if (x == 'N') n++;
        if (x == 'S') s++;
        if (x == 'E') e++;
        if (x == 'W') w++;
    }
    if (n > s) {
        n -= s;
        s = 0;
    } else {
        s -= n;
        n = 0;
    }
    if (e > w) {
        e -= w;
        w = 0;
    } else {
        w -= e;
        e = 0;
    }
    if (n % 2 == 1 || s % 2 == 1 || e % 2 == 1 || w % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    n /= 2;
    s /= 2;
    e /= 2;
    w /= 2;

    vector<int> ans(num, 0);
    int count = 0;
    for (int i = 0; i < num; i++) {
        if (str[i] == 'N' && n > 0) {
            ans[i] = 1;
            n--;
        }
        if (str[i] == 'S' && s > 0) {
            ans[i] = 1;
            s--;
        }
        if (str[i] == 'E' && e > 0) {
            ans[i] = 1;
            e--;
        }
        if (str[i] == 'W' && w > 0) {
            ans[i] = 1;
            w--;
        }
        if (ans[i] == 1) count++;
    }
    if (count == 0) {
        int a = -1;
        int b = -1;
        for (int i = 0; i < num; i++)
            if (str[i] == 'N') a = i;
        for (int i = 0; i < num; i++)
            if (str[i] == 'S') b = i;
        if (a == -1 || b == -1) {
            a = -1;
            b = -1;
            for (int i = 0; i < num; i++)
                if (str[i] == 'W') a = i;
            for (int i = 0; i < num; i++)
                if (str[i] == 'E') b = i;
        }
        if (a == -1 || b == -1) {
            cout << "NO" << endl;
            return;
        }
        ans[a] = 1;
        ans[b] = 1;
    }
    if (count == 0 && num == 2) {
        cout << "NO" << endl;
        return;
    }
    for (auto &x : ans) {
        if (x == 1) {
            cout << 'R';
        } else {
            cout << 'H';
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