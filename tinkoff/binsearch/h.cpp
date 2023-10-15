#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll count_cows(vector<int>a, int size, int l) {
    ll last = a[0], ans = 1;
    for (int i = 1; i < size; i++) {
        if (a[i] - last >= l) {
            last = a[i];
            ans++;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 1;
    ll r = a[n - 1] - a[0] + 1;
    while (l < r - 1) {
        ll m = (l + r) / 2;
        if (count_cows(a, n, m) >= k) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
    return 0;
}

/*

6 3
2 5 7 11 15 20

*/