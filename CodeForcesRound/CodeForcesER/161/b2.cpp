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
        sort(a.begin(), a.end());
        int ans = 0;
        for (int x = 2; x < n; x++) {
            int j = x - 1;
            while (j > 0 && (a[j] == a[x])) {
                if (a[j] == a[x]) {
                    ans += j;
                }
                j--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}