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
    string start = str;
    int k = 0;
    for (auto &x : str) if (x == '1') k++;
    int ans = 0;
    while (k != 0) {
        if (str[k - 1] == '0') {
            str[k - 1] = '1';
            k++;
        } else {
            str[k - 1] = '0';
            k--;
        }
        ans++;
        // cout << k << endl;
    }
    cout << ans << endl;
    return 0;
}