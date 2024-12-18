#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> b(n, 0);
    vector<int> c(n, 0);
    for (auto &x : a)
        c[x]++;
    /*for (auto &x : b)
        cout << x << " ";
    cout << endl;
    for (auto &x : c)
        cout << x << " ";
    cout << endl;*/
    int i1 = 0;
    int i2 = 0;
    while (c[i2] != 0)
        i2++;
    // cout << i2 << endl;
    bool find = 0;
    for (int s = 0; s < n; s++) {
        b[a[s]]++;
        while (b[i1] != 0) i1++;
        c[a[s]]--;
        if (c[a[s]] == 0 && a[s] < i2) i2 = a[s];
        if (i1 == i2) {
            // cout << s << endl;
            find = 1;
            cout << 2 << endl;
            cout << "1 " << s + 1 << "\n" << s + 2 << " " << n << endl;
            break;
        }
        /*for (auto &x : b)
            cout << x << " ";
        cout << endl;
        for (auto &x : c)
            cout << x << " ";
        cout << endl;
        cout << i1 << " " << i2 << endl;*/
    }
    if (!find) {
        cout << -1 << endl;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}