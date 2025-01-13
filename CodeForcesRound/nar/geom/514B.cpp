#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

int main() {
    int n, ys, xs;
    cin >> n >> ys >> xs;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    vector<int> d(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].S == xs) {
            ans = 1;
            d[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) {
            for (int j = 0; j < n; j++) {
                if ((double)(ys - a[i].F) / (xs - a[i].S) == (double)(ys - a[j].F) / (xs - a[j].S)) {
                    d[j] = 1;
                }
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}