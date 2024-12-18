#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int>a = vector<int>(n);
        for (auto &x : a)
            cin >> x;
        a.push_back(1000000007);
        sort(a.begin(), a.end());
        /*for (auto x : a)
            cout << x << " ";
        cout << endl;*/
        ll ans = a[0];
        ll index = 0;
        ll w = 0;
        while (true) {
            while (index < n && a[index] <= ans) {
                index++;
            }
            if (w + (index * (a[index] - a[index - 1])) <= k) {
                w += (index * (a[index] - a[index - 1]));
                ans += (a[index] - a[index - 1]);
            } else {
                k -= w;
                ans += k / index;
                break;
            }
            //cout << ans << " " << w << endl;
        }
        cout << ans << endl;
    }
    return 0;
}