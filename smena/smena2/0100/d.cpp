#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n;

int nod(int a, int b) {
    while (b > 0) {
        a %= b;
        int buff = a;
        a = b;
        b = buff;
    }
    return a;
}

bool comp(pair<int, int> &a, pair<int, int> &b) {
    int q = (a.S - a.F < 0)?(a.S - a.F + n):(a.S - a.F);
    int w = (b.S - b.F < 0)?(b.S - b.F + n):(b.S - b.F);
    if (q == w) {
        return a.F < b.F;
    }
    return q < w;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int index = i - 1;
        while (((index < 0)?index+n:index) != i && nod(a[i], a[((index < 0)?index+n:index)]) != 1)
            index--;
        b[i] = ((index < 0)?index+n:index);
    }
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++)
        c[i] = {b[i], i};
    sort(c.begin(), c.end(), comp);
    for (auto &x : c)
        cout << x.F << " " << x.S << endl;
    vector<int> used(n);
    vector<int> ans = {};
    for (auto &x : c) {
        if (used[x.F] == 0) {
            x.S = 1;
        } else {
            cout << ans.size() << endl;
            for (auto &x : ans)
                cout << x << " ";
            cout << endl;
            break;
        }
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