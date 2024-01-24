#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, m;
        cin >> n >> m;
        vector<ll>a(n);
        vector<ll>b(m);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        /*for (auto &x : b)
            cout << x << " ";
        cout << endl;
        for (auto &x : a)
            cout << x << " ";
        cout << endl;*/
        ll mmm = 0;
        for (int is = 0; is < m; is++) {
            ll ans = 0;
            for (int i = 0; i < n; i++) {
                ll index = (is + i) % m;
                ans += abs(a[i] - b[index]);
                //cout << index << " ";
            }
            //cout << endl;
            //cout << ans << endl;
            mmm = std::max(ans, mmm);
        }
        cout << mmm << endl;
    }
    return 0;
}