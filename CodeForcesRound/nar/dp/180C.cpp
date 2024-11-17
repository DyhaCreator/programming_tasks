#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (a[i] > 90) {
            b[i] = 1;
        }
    }
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    for (int i = 0; i < n; i++) {
        l[i + 1] = l[i];
        if (b[i] == 1)
            l[i + 1]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] = r[i + 1];
        if (b[i] == 0)
            r[i]++;
    }
    int ans = INF;
    for (int i = 0; i <= n; i++)
        ans = min(ans, l[i] + r[i]);
    cout << ans << endl;
    return 0;
}