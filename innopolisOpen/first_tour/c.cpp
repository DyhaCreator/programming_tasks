#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#define ll long long
using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    vector<int>b = vector<int>(n);
    for (int i = 0; i < n; i++) {
        if (a[i] < a[n - i - 1]) {
            b[i] = a[n - i - 1] - a[i];
        }
    }
    int ans = 0;
    ll sum = 1;
    while (sum != 0) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] >= k) {
                b[i] -= k;
                sum += k;
            } else if (b[i] == 0 && sum > 0) {
                ans++;
                sum = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == 2) {
                b[i] -= 2;
                sum += 2;
            } else if (b[i] == 0 && sum > 0) {
                ans++;
                sum = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) {
                b[i] -= 1;
                sum += 1;
            } else if (b[i] == 0 && sum > 0) {
                ans++;
                sum = 0;
            }
        }
        //cout << sum << endl;
        for (auto x : b)
            cout << x << " ";
        cout << endl;
    }
    cout << ans - 1 << endl;
    return 0;
}