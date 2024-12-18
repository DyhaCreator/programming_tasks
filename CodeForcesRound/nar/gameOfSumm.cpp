#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, l;
        cin >> n >> k >> l;
        vector<int>a(n);
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        int sum = 0;
        int ans = 0;
        for (auto &x : a)
            sum += x;
        for (int K = 0; K <= k; K++) {
            if (K > 0) {
                sum -= a[K - 1];
            }
            int mmin = 1000000000;
            int thisSum = sum;
            for (int L = 0; L <= l; L++) {
                if (L > 0) {
                    thisSum -= a[n - L] * 2;
                }
                mmin = std::min(thisSum, mmin);
                cout << thisSum << endl;
            }
            cout << ans << endl << endl;
        }
    }
    return 0;
}