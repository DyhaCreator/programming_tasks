#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += k % n;
        k -= k % n;
        k -= k / n;
    }
    ans += k % n;
    cout << ans << endl;
    return 0;
}