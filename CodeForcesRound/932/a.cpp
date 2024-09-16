#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    string strr = str;
    reverse(strr.begin(), strr.end());

    if (str <= strr) {
        if (n % 2 == 1) {
            cout << str + strr << endl;
        } else {
            cout << str << endl;;
        }
    } else {
        if (n % 2 == 0) {
            cout << strr + str << endl;
        } else {
            cout << strr << endl;
        }
    }

    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}