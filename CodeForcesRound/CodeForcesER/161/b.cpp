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
        vector<ll>a(n);
        for (auto &x : a)
            cin >> x;
        //sort(a.begin(), a.end());
        ll ans = 0;
        for (int x = 0; x < n - 2; x++) {
            for (int y = x + 1; y < n - 1; y++) {
                for (int z = y + 1; z < n; z++) {
                    if (a[x] + a[y] > a[z] && a[x] + a[z] > a[y] && a[y] + a[z] > a[x]) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}