#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#define ll long long
#define INF 1000000007
#define prvec(vec) for(auto &x:vec)cout<<x<<" ";cout<<endl;
#define all(vec) vec.begin(),vec.end()
using namespace std;

void solveA() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        sort(all(a));
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (i != j) {
                    ans = max(ans, abs(a[0] - a[i]) + abs(a[i] - a[j]) + abs(a[j] - a[n - 1]) + abs(a[0] - a[n - 1]));
                }
            }
        }
        cout << ans << endl;
        //cout << endl;
    }
}

void solveB() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        if (n > 15 * 2) {
            ans += (n / 15) - 1;
            n -= ans * 15;
        }
        //cout << n << endl;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            int m = INF;
            if (i >= 1) {
                m = min(m, a[i - 1] + 1);
            }
            if (i >= 3) {
                m = min(m, a[i - 3] + 1);
            }
            if (i >= 6) {
                m = min(m, a[i - 6] + 1);
            }
            if (i >= 10) {
                m = min(m, a[i - 10] + 1);
            }
            if (i >= 15) {
                m = min(m, a[i - 15] + 1);
            }
            a[i] = m;
        }
        // prvec(a)
        cout << a[n] + ans << endl;
    }
}

int main() {
    solveB();
    return 0;
}