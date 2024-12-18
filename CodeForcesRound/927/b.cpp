#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll f(ll a, ll b) {
    return ((a / b) + 1) * b;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;
        ll year = 0;
        for (int j = 0; j < n; j++) {
            year = f(year, a[j]);
            // cout << year << " " << a[j] << endl;
        }
        cout << year << endl;
    }
    return 0;
}