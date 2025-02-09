#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b = "", c = "";
    int f = 0;
    int f2 = 0;
    for (auto &x : a) {
        if (x == '0') {
            b.push_back('0');
            c.push_back('0');
        } else if (x == '1') {
            if (f == 0) {
                b.push_back('1');
                c.push_back('0');
                f = 1;
                f2 = 1;
            } else {
                b.push_back('0');
                c.push_back('1');
            }
        } else {
            if (f2 == 0) {
                b.push_back('1');
                c.push_back('1');
            } else {
                b.push_back('0');
                c.push_back('2');
            }
        }
    }
    cout << b << endl;
    cout << c << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}