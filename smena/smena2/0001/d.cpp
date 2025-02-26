#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.rbegin(), a.rend());
    vector<int> c(n);
    c[0] = 1;
    for (int i = 1; i < n; i++) {
        c[i] = c[i - 1];
        if (a[i].F != a[i - 1].F) c[i]++;
    }
    int index = 0;
    while (c[index] != k && index < n) {
        index++;
    }
    if (c[index] != k) {
        cout << -1 << endl;
        return 0;
    }
    reverse(a.begin(), a.begin() + index + 1);
    for (auto &x : a)
        cout << x.S + 1 << " ";
    cout << endl;
    return 0;
}