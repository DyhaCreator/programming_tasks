#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll sum = 0;
    while (sum < n) {
        ans++;
        sum += ans;
    }
    cout << ans << " " << sum << endl;
    return 0;
}