#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int l, n;
    cin >> l >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    sort(a.begin(), a.end());
    int ansI = 0;
    int ansPos = 0;
    for (int i = 0; i < n; i++) {
        int save = a[i].S;
        a[i].S /= 2;
        int pos = 0;
        int f = 0;
        for (int j = 0; j < n; j++) {
            if (a[j].S > 3) {
                pos = a[j].F;
                break;
            } else {
                if (a[j].F - pos >= a[j].S) {
                    pos = a[j].F - 3 + a[j].S;
                } else {
                    pos = a[j].F;
                    break;
                }
            }
            if (j == n - 1) {
                f = 1;
            }
        }
        if (f == 1) pos = l;
        a[i].S = save;
        if (pos >= ansPos) {
            ansPos = pos;
            ansI = i;
        }
    }
    cout << a[ansI].F << endl;
    cout << ansPos << endl;
    return 0;
}