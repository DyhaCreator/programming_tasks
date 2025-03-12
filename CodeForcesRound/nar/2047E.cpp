#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(3);
    a[0] = rand() % n + 1;
    a[1] = rand() % n + 1;
    a[2] = rand() % n + 1;
    while (a[1] == a[0]) a[1] = rand() % n + 1;
    while (a[2] == a[0] || a[2] == a[1]) a[2] = rand() % n + 1;
    int col = 1;
    int index = 0;
    while (col > 0) {
        cout << "? ";
        for (auto &x : a)
            cout << x << " ";
        cout << endl;
        cin >> col;
        if (col == 0) {
            cout << "! ";
            for (auto &x : a)
                cout << x << " ";
            cout << endl;
            break;
        }
        vector<int> b(3);
        cout << "? " << col << " " << a[1] << " " << a[2] << endl;
        cin >> b[0];
        cout << "? " << a[0] << " " << col << " " << a[2] << endl;
        cin >> b[1];
        cout << "? " << a[0] << " " << a[1] << " " << col << endl;
        cin >> b[2];
        if (b[0] == 0) {
            cout << "! " << col << " " << a[1] << " " << a[2] << endl;
            break;
        }
        if (b[1] == 0) {
            cout << "! " << a[0] << " " << col << " " << a[2] << endl;
            break;
        }
        if (b[2] == 0) {
            cout << "! " << a[0] << " " << a[1] << " " << col << endl;
            break;
        }
        if (col != 0) {
            a[index % 3] = col;
            index++;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}