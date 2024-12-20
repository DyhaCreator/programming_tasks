#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    if (k == 2) {
        int ans0 = 0;
        int ans1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 + 'A' != a[i]) ans0++;
            if ((i + 1) % 2 + 'A' != a[i]) ans1++;
        }
        if (ans0 < ans1) {
            cout << ans0 << endl;
            for (int i = 0; i < n; i++) cout << char(i % 2 + 'A');
            cout << endl;
        } else {
            cout << ans1 << endl;
            for (int i = 0; i < n; i++) cout << char((i + 1) % 2 + 'A');
            cout << endl;
        }
    } else {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                if (i < n - 1) {
                    while (a[i] == a[i - 1] || a[i] == a[i + 1])
                        a[i] = rand() % k + 'A';
                    ans++;
                } else {
                    a[i] = (a[i] - 'A' + 1) % k + 'A';
                    ans++;
                }
            }
        }
        cout << ans << endl;
        cout << a << endl;
    }
    return 0;
}