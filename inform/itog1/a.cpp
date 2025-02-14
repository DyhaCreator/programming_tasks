#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = n - 1; i > 0; i--) {
        int mx = 0;
        for (int j = 0; j <= i; j++)
            if (a[j] > a[mx] && a[j] % k == a[i] % k) mx = j;
        if (a[mx] % k == a[i] % k) {
            int buff = a[i];
            a[i] = a[mx];
            a[mx] = buff;
        }
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    if (a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}