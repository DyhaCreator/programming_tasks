#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, m;
        cin >> n >> k >> m;
        vector<int>a(n);
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        a.push_back(0);
        ll sum = 0;
        for (auto &x : a)
            sum += x;
        //cout << sum << endl;
        ll mmm = -100000;
        for (int j = n; j >= n - k; j--) {
            // cout << a[j] << " ";
            sum -= a[j];
            ll newSum = sum;
            //cout << newSum << " ";
            for (int l = j - 1; l >= 0 && l >= j - m; l--) {
                newSum -= a[l] * 2;
                //cout << a[l] << " ";
            }
            mmm = std::max(newSum, mmm);
            // cout << newSum << endl;
        }
        //cout << endl;
        cout << mmm << endl;
    }
    return 0;
}