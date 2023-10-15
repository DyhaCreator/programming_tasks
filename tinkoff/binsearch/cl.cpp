#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int>a = vector<int>(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int l = 0;
        int r = k;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] < x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int ind1 = l;
        if (a[l] == x) {
            l = 0;
            r = k;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (a[m] <= x) {
                    l = m;
                } else {
                    r = m;
                }
            }
            cout << l - ind1 + 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
