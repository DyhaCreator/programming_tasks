#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int ans = 0;

bool f1(ll n) {
    while (n > 0) {
        if (n % 10 > 5 || n % 10 < 1) {
            return 0;
        }
        n /= 10;
    }
    return 1;
}

bool f2(ll n) {
    vector<ll> a = {};
    while (n > 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    for (int i = 2; i < a.size(); i++) {
        if (a[i] + a[i - 1] + a[i - 2] != 8) {
            return 0;
        }
    }
    return 1;
}

void gen(ll num, ll len) {
    if (len >= 10) {
        // cout << num << endl;
        if (f1(num) && f2(num)) {
            ans++;
            cout << num << endl;
        }
        return;
    }
    num *= 10;
    for (ll i = 1; i <= 5; i++) {
        num++;
        gen(num, len + 1);
    }
}

int main() {
    gen(0, 0);
    cout << ans << endl;
    return 0;
}