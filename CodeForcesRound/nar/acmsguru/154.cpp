#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(int n) {
    int ans = 0;
    int st = 5;
    while (st <= n) {
        ans += n / st;
        st *= 5;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int l = n * 3;
    int r = n * 5;
    while (l < r) {
        int m = (l + r) / 2;
        if (f(m) < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (f(r) == n) {
        cout << r << endl;
    } else {
        cout << "No solution" << endl;
    }
    return 0;
}