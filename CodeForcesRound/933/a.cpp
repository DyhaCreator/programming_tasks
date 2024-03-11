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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] + b[j] <= k) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

void solveB() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        if (a[0] * 2 > a[1] || a[a.size() - 1] * 2 > a[a.size() - 2]) {
            cout << "NO" << endl;
            continue;
        }
        int m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, a[i]);
        }
        int countMax = 0;
        for (int i = 1; i < n; i++) {
            
        }
    }
}

void solveC() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (str[i] == 'm' && str[i + 1] == 'a' && str[i + 2] == 'p') {
                if (i < n - 4 && str[i + 3] == 'i' && str[i + 4] == 'e') {
                    ans++;
                    i += 4;
                } else {
                    ans++;
                    i += 2;
                }
            } else if (str[i] == 'p' && str[i + 1] == 'i' && str[i + 2] == 'e') {
                ans++;
                i += 2;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    solveC();
    return 0;
}