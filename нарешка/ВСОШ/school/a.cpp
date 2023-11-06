#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll>a(n - 1);
    for (auto &x : a)
        cin >> x;
    ll max_r = 0;
    ll max_l = 0;
    ll max_curSum = 0;
    ll curSum = 0;
    ll l = 0;
    for (ll r = 0; r < n - 1; r++) {
        curSum += a[r];
        while (curSum * 2 > t) {
            curSum -= a[l];
            l++;
        }
        if (max_curSum < curSum) {
            max_curSum = curSum;
            max_l = l;
            max_r = r;
        }
    }
    if (max_curSum == 0) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    cout << max_l + 1 << " " << max_r + 2 << endl; 
    return 0;
}

/*

7
20
2
5
3
3
2
4

*/