#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int nod(int a, int b) {
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    while (a % b != 0) {
        a = a % b;
        int t = a;
        a = b;
        b = t;
    }
    return b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++)
        b[i] = nod(a[i], a[i + 1]);
    /*for (auto &x : b)
        cout << x << " ";
    cout << endl;*/
    int f = 0;
    for (int i = 1; i < n - 2; i++) {
        if (b[i] > b[i + 1]) {
            f = 1;
            break;
        }
    }
    if (!f) {
        cout << "YES" << endl;
        return;
    }
    // cout << f << endl;
    f = 0;
    for (int i = 0; i < n - 3; i++) {
        if (b[i] > b[i + 1]) {
            f = 1;
            break;
        }
    }
    if (!f) {
        cout << "YES" << endl;
        return;
    }
    // cout << f << endl;
    for (int i = 0; i < n - 2; i++) {
        int nd = nod(a[i], a[i + 2]);
        int found = 0;
        int last = 1;
        for (int j = 0; j < n - 1; j++) {
            if (j == i) {
                if (last > nd) {
                    found = 1;
                    // break;
                }
                // cout << nd << " ";
                j++;
                last = nd;
            } else {
                if (last > b[j]) {
                    found = 1;
                    // break;
                }
                // cout << b[j] << " ";
                last = b[j];
            }
        }
        if (found == 0) {
            cout << "YES" << endl;
            return;
        }
        // cout << endl;
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}