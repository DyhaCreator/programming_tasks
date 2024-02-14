#include <algorithm>
#include <iostream>
#include <string>
#define ll long long
using namespace std;

ll f(string num, ll x) {
    ll ans = 0;
    ll n = 1;
    reverse(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
        if (num[i] < 58) {
            ans += (ll)(num[i] - '0') * n;
        } else {
            ans += (ll)(num[i] - 'A' + 10) * n;
        }
        n *= x;
    }
    return ans;
}

int main() {
    string str;
    ll b;
    cin >> str >> b;
    ll c = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] < 58) {
            c = std::max(c, (ll)(str[i] - '0'));
        } else {
            c = std::max(c, (ll)(str[i] - 'A' + 10));
        }
    }
    // cout << c << endl;
    ll x = c + 1;
    while (f(str, x) != b && x <= 36) {
        // cout << f(str, x) << endl;
        x++;
    }
    if (x != 37 && f(str, x) == b) {
        cout << x << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}