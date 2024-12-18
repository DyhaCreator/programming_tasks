#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<int>a(n);
        vector<int>b(m);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;
        for (auto &x : b)   
            cout << x << " ";
        cout << endl;*/
        if (n % 2 == 0) {
            int index = m - n / 2;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += abs(b[(index + i) % m] - a[i]);
            }
            cout << ans << endl;
        } else {
            int index = m - (n + 1) / 2;
            int ans1 = 0;
            for (int i = 0; i < n; i++) {
                ans1 += abs(b[(index + i) % m] - a[i]);
            }
            //cout << ans1 << endl;
            index = m - n / 2;
            int ans2 = 0;
            for (int i = 0; i < n; i++) {
                ans2 += abs(b[(index + i) % m] - a[i]);
            }
            cout << std::max(ans2, ans1) << endl;
        }
    }
    return 0;
}