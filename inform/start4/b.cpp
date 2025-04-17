#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < n; j += i + 2) {
            a[j] = 1 - a[j];
        }
    }
    int sum = 0;
    for (auto &x : a)
        sum += x;
    cout << sum << endl;
    return 0;
}