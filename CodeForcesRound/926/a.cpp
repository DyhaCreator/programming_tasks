#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)   
            cin >> x;
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int j = 1; j < n; j++) {
            ans += a[j] - a[j - 1];
        }
        cout << ans << endl;
    }
    return 0;
}