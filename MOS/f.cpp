#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int f(int l, int k) {
    return l / k;
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    vector<int>pref = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    int ans = 0;
    for (int r = 1; r <= n; r++) {
        for (int l = 0; l < r; l++) {
            //cout << l << ' ' << r << " " << pref[r] - pref[l] - (f(r - l, k) * x) << endl;
            ans = std::max(pref[r] - pref[l] - (f(r - l, k) * x), ans);
        }
    }
    cout << ans << endl;
    return 0;
}
/*

6 3 8
1 -3 14 -2 9 4

5 5 5
-1 -2 -3 -4 -10

4 2 5
6 6 -9 7

*/