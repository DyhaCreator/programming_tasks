#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int k = 0;
    for (auto &x : str) if (x == '1') k++;
    // cout << k << endl;
    ll ans = 0;
    while (k != 0) {
        // cout << str[k - 1] << endl;
        if (str[k - 1] == '0') {
            ll len = 0;
            while (str[k - 1 + len] == '0') {
                len++;
            }
            str[k - 1 + len] = '0';
            // cout << str << " " << len << endl;
            ans += len * 2 + 1;
            k--;
        } else {
            ll len = 0;
            while (k - 1 - len >= 0 && str[k - 1 - len] == '1') {
                str[k - 1 - len] = '0';
                // cout << k - 1 - len << endl;
                len++;
            }
            k -= len;
            // cout << k << endl;
            ans += len;
            // cout << str << " " << len << endl;
        }
        // cout << k << endl;
    }
    cout << ans << endl;
    return 0;
}