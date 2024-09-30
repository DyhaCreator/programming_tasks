#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1 >> s2;
    // cout << s1 << endl << s2 << endl;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s1[i - 1] == 'x' && s1[i] == '.' && s1[i + 1] == 'x' &&
            s2[i - 1] == '.' && s2[i] == '.' && s2[i + 1] == '.') {
            ans++;
        } else if (s2[i - 1] == 'x' && s2[i] == '.' && s2[i + 1] == 'x' &&
            s1[i - 1] == '.' && s1[i] == '.' && s1[i + 1] == '.') {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}