#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, r1;
    cin >> n >> r1;
    ll save = r1;
    ll rmin = 0;
    ll sum = 0;
    ll ans = 0;
    ll allSum = 0;
    r1 = (r1 * 1103515245 + 12345) % (1 << 31);
    for (int i = 0; i < n; i++) {
        allSum += r1 / (1 << 16) - (1 << 14);
        // cout << r1 / (1 << 16) - (1 << 14) << " ";
        sum += r1 / (1 << 16) - (1 << 14);
        r1 = (r1 * 1103515245 + 12345) % (1 << 31);
        if (sum < rmin) rmin = sum;
        ans = max(sum - rmin, ans);
    }
    // cout << endl;
    r1 = save;
    ll rmax = 0;
    sum = 0;
    ll ans2 = INF;
    r1 = (r1 * 1103515245 + 12345) % (1 << 31);
    for (int i = 0; i < n; i++) {
        sum += r1 / (1 << 16) - (1 << 14);
        r1 = (r1 * 1103515245 + 12345) % (1 << 31);
        if (sum > rmin) rmin = sum;
        ans2 = min(sum - rmin, ans2);
    }
    cout << max(ans, allSum - ans2) << endl;
    return 0;
}