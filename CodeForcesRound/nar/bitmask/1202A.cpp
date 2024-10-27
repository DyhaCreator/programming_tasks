#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // cout << a << " " << b << endl;
    int index = 0;
    while (index < b.size() && b[index] == '0')
        index++;
    int secIndex = index;
    while (secIndex < a.size() && a[secIndex] == '0')
        secIndex++;
    cout << secIndex - index << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}