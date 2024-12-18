#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int>a = vector<int>(n);
        for (auto &x : a)
            cin >> x;
        int ans = 0;
        int w = 0;
        while (w <= k) {
            for (int j = 0; j < n; j++) {
                //cout << a[j] << " ";
                if (a[j] < ans) {
                    w++;
                }
            }
            /*cout << endl;
            cout << w << endl;*/
            ans++;
        }
        cout << ans - 2 << endl;
    }
    return 0;
}