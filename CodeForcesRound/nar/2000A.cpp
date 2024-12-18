#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string str;
    cin >> str;
    if (str[0] == '1' &&
        str[1] == '0' &&
        (str[2] > '1' || 
        (str[2] == '1' && str.size() > 3))
    ) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}