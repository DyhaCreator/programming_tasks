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
        int index = 0;
        while (a[index] < 0 && index < k && index < n) {
            a[index] = 0;
            index++;
        }
        index = n - 1;
        int count = 0;
        while (a[index] > 0 && count < m && index >= k) {
            a[index] = -a[index];
            count++;
            index--;
        }
        int ans = 0;
        for (auto &x : a) {
            ans += x;
            cout << x << endl;
        }
        cout <<"ans - "<< ans << endl;
    }
    return 0;
}