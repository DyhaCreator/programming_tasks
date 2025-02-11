#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        c[a[i] - 1] = i;
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    for (int i = 0; i < n; i++) {
        if (c[b[i] - 1] >= i) {
            l[c[b[i] - 1] - i]++;
            r[i + n - c[b[i] - 1]]++;
        } else {
            r[i - c[b[i] - 1]]++;
            l[c[b[i] - 1] + n - i]++;
        }
    }
    int mx = 0;
    for (auto &x : l)
        mx = max(mx, x);
    for (auto &x : r)
        mx = max(mx, x);
    cout << mx << endl;
    return 0;
}