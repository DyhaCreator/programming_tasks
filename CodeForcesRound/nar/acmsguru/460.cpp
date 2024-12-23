#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string a;
    cin >> a;
    if (a.size() >= 2 && a[a.size() - 2] == 'c' && a[a.size() - 1] == 'h') {
        a += "es";
    } else if (a.back() == 'x' || a.back() == 's' || a.back() == 'o') {
        a += "es";
    } else if (a.back() == 'f') {
        a[a.size() - 1] = 'v';
        a += "es";
    } else if (a.size() >= 2 && a[a.size() - 2] == 'f' && a[a.size() - 1] == 'e') {
        a[a.size() - 2] = 'v';
        a += "s";
    } else if (a[a.size() - 1] == 'y') {
        a[a.size() - 1] = 'i';
        a += "es";
    } else {
        a.push_back('s');
    }
    cout << a << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}