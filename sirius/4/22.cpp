#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> p(n + 1);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        p[i + 1] = sum % 3;
    }
    /*for (auto &x : p)
        cout << x << " ";
    cout << endl;*/
    vector<int> c(3, -1);
    for (int i = 0; i <= n; i++) {
        int num = p[i];
        if (num == -1) num = 2;
        if (num == -2) num = 1;
        if (c[num] == -1) {
            c[num] = i;
        }
    }
    /*for (auto &x : c)
        cout << x << " ";
    cout << endl;*/
    int l = -1, r = -1;
    for (int i = 0; i <= n; i++) {
        int num = p[i];
        if (num == -1) num = 2;
        if (num == -2) num = 1;
        if (r - l < i - c[num]) {
            r = i;
            l = c[num];
        }
    }
    if (l == -1 && r == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << l + 1 << " " << r << endl;
    return 0;
}