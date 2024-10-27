#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int count = 0;
    for (auto &x : s)
        if (x == '?') count++;
    // cout << count << endl;
    int ans = 9;
    for (int k = 0; k < (1 << count); k++) {
        // cout << k << endl;
        int a = 0;
        int b = 0;
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            // cout << s[i] << endl;
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    a++;
                } else if (s[i] == '?') {
                    if ((k & (1 << c)) > 0) {
                        a++;
                    }
                    c++;
                }
            } else {
                if (s[i] == '1') {
                    b++;
                } else if (s[i] == '?') {
                    if ((k & (1 << c)) > 0) {
                        b++;
                    }
                    c++;
                }
            }
            // cout << a << " " << b << " " << (10 - i) / 2 << endl;
            if (b - a > (10 - i - (i % 2 == 0)) / 2 || a - b > (10 - i - (i % 2 == 1)) / 2) {
                // cout << a << " " << b << " " << (10 - i) / 2 << endl;
                ans = min(ans, i);
                break;
            }
        }
    }
    cout << ans + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}