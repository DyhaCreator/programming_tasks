#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b)
        cin >> x;
    vector<int> used(m, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(a[i] - b[j]) <= 1 && used[j] == 0) {
                used[j] = 1;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}