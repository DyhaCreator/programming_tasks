#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<int> dp_ab(n);
    vector<int> dp_ba(n);
    int f_ab = 0;
    int f_ba = 0;
    int f = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == 'A' && a[i] == 'B') {
            dp_ab[i] = 1;
            if (f_ba) {
                f = 1;
                break;
            }
        } else if (a[i - 1] == 'B' && a[i] == 'A') {
            dp_ba[i] = 1;
            if (f_ab) {
                f = 1;
                break;
            }
        }
        f_ab = max(f_ab, dp_ab[i - 1]);
        f_ba = max(f_ba, dp_ba[i - 1]);
    }
    if (f) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}