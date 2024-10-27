#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (auto &x : a)
        cin >> x;
    int b;
    cin >> b;
    int ans = 0;
    for (auto &x : a) {
        int xxx = (x ^ b);
        int count = 0;
        while (xxx > 0) {
            if (xxx % 2 == 1) count++;
            xxx /= 2;
        }
        if (count <= k) ans++;
    }
    cout << ans << endl;
    return 0;
}