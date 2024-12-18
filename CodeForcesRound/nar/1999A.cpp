#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    cout << s[0] - '0' + s[1] - '0' << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}