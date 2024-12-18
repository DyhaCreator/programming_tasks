#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    int imin = 0;
    int ibest = 0;
    int jbest = 1;
    for (int j = 2; j < n; j++) {
        if (a[j - 1] < a[imin])
            imin = j - 1;
        if (k / a[imin] * b[j] + k % a[imin] > k / a[ibest] * b[jbest] + k % a[ibest]) {
            jbest = j;
            ibest = imin;
        }
    }
    if (k / a[ibest] * b[jbest] + k % a[ibest] <= k) {
        cout << k << endl;
        cout << "-1 -1" << endl;
        return 0;
    }
    cout << k / a[ibest] * b[jbest] << endl;
    cout << ibest + 1 << " " << jbest + 1 << endl;
    return 0;
}