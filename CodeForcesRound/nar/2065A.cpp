#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string a;
    cin >> a;
    string b = "";
    for (int i = 0; i < a.size() - 2; i++)
        b.push_back(a[i]);
    cout << b + "i" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}