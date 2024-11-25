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
    vector<int> b = {-1, -1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (((a[i] - '0') * 100 + (a[j] - '0') * 10 + (a[k] - '0')) % 8 == 0) {
                    b = {i, j, k};
                }
            }
        }
    }
    if (b[0] == -1) {
        int f = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (((a[i] - '0') * 10 + (a[j] - '0')) % 8 == 0 && f == 0) {
                    f = 1;
                    cout << "YES" << endl;
                    cout << a[i] << a[j] << endl;
                    break;
                }
            }
        }
        if (f == 0) {
            for (auto &x : a) {
                if (x == '0' || x == '8') {
                    f = 1;
                    cout << "YES" << endl;
                    cout << x << endl;
                }
            }
            if (f == 0) cout << "NO" << endl;
        }
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < b[0]; i++) cout << a[i];
    cout << a[b[0]] << a[b[1]] << a[b[2]] << endl;
    return 0;
}