#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (auto &x : a)
            cin >> x;
        vector<int>left(n);
        vector<int>right(n);
        for (int j = 0; j < n - 1; j++) {
            if (j > 0  && abs(a[j + 1] - a[j]) < abs(a[j - 1] - a[j])) {
                left[j + 1] = left[j] + 1;
            } else if (j > 0) {
                left[j + 1] = left[j] + (a[j + 1] - a[j]);
            } else {
                left[j + 1] = 1;
            }
            //cout << left[j + 1] << " ";
        }
        //cout << endl;
        reverse(a.begin(), a.end());
        for (int j = 0; j < n - 1; j++) {
            if (j > 0  && abs(a[j + 1] - a[j]) < abs(a[j - 1] - a[j])) {
                right[j + 1] = right[j] + 1;
            } else if (j > 0) {
                right[j + 1] = right[j] + abs(a[j + 1] - a[j]);
            } else {
                right[j + 1] = 1;
            }
            //cout << right[j + 1] << " ";
        }
        //cout << endl;
        //reverse(right.begin(), right.end());
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (l < r) {
                cout << left[r] - left[l] << endl;
            } else {
                cout << abs(right[n - (l + 1)] - right[n - (r + 1)]) << endl;
            }
        }
    }
    return 0;
}