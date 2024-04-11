#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define INF 1000000007
using namespace std;

bool test(string &a, string &b) {
    for (int i = 0; i < int(b.size()); i++) {
        // cout << i << " " << a[i] << " " << b[i - start] << endl;
        if (a[i] == b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;
    string c = a;
    string d = a;
    int ans = INF;
    for (int i = 0; i <= a.size(); i++) {
        if (test(c, b)) {
            ans = i;
            break;
        }
        // cout << c << endl;
        char q = c[0];
        for (int j = 1; j < c.size(); j++) {
            c[j - 1] = c[j];
        }
        c[c.size() - 1] = q;
    }
    // cout << ans << endl;
    for (int i = 0; i <= a.size(); i++) {
        if (test(d, b)) {
            ans = min(i, ans);
            break;
        }
        // cout << d << endl;
        char q = d[d.size() - 1];
        for (int j = d.size() - 1; j > 0; j--) {
            d[j] = d[j - 1];
        }
        d[0] = q;
    }
    cout << ans << endl;
    return 0;
}