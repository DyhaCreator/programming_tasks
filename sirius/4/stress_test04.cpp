#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n = 8, c = 40;

int solveA(vector<int> &a) {
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (a[m] < a[i] + a[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            ans += r - 1 - j;
            // cout << i << " " << j << " " << r << " " << r - (j + 1) << endl;
        }
    }
    return ans;
}

int solveB(vector<int> &a) {
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] > a[k] && a[k] + a[i] > a[j] && a[k] + a[j] > a[i]) {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int f(vector<int> &a, int index, int last) {
    if (index >= n) {
        int ans1 = solveB(a);
        int ans2 = solveA(a);
        if (ans1 != ans2) {
            for (auto &x : a)
                cout << x << " ";
            cout << endl;
            cout << ans1 << " " << ans2 << endl;
        }
        return 0;
    }
    for (int i = last; i <= c; i++) {
        a[index] = i;
        f(a, index + 1, i);
    }
    return 0;
}

int main() {
    vector<int> a(n);
    f(a, 0, 1);
    return 0;
}