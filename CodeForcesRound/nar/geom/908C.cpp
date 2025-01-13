#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n, r;

double f(int x1, double y1, int x2) {
    if (abs(x1 - x2) > 2 * r) return r;
    return y1 + sqrt((2 * r) * (2 * r) - abs(x2 - x1) * abs(x2 - x1));
}

int main() {
    cin >> n >> r;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<double> ans(n, r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            ans[i] = max(ans[i], f(a[j], ans[j], a[i]));
    }
    for (auto &x : ans)
        printf("%.6f ", x);
    cout << endl;
    return 0;
}