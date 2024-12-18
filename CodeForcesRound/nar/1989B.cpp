#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(string &a, string &b, int s) {
    int len = 0;
    int index = 0;
    for (int i = s; i < b.size(); i++) {
        while (index < a.size() && a[index] != b[i]) index++;
        if (index < a.size()) len++;
        index++;
    }
    return len;
}

void solve() {
    string a, b;
    cin >> a >> b;
    int max_len = 0;
    for (int i = 0; i < b.size(); i++)
        max_len = max(f(a, b, i), max_len);
    cout << a.size() + (b.size() - max_len) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}