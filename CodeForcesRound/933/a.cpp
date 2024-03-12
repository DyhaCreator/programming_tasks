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

        for (int i = 1; i < n - 1; i++) {
            int m = min(min(a[i] / 2, a[i - 1]), a[i + 1]);
            a[i] -= m * 2;
            a[i - 1] -= m;
            a[i + 1] -= m;
        }
        ll sum = 0;
        for (auto &x : a)
            sum += x;
        if (sum == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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

void solveD() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, index;
        cin >> n >> m >> index;
        index--;
        vector<int> a(n, 0);
        a[index] = 1;

        while (m--) {
            int r;
            char c;
            cin >> r >> c;
            if (c == '0') {
                vector<int> na(n);
                for (int i = 0; i < n; i++) {
                    if (a[i] == 1) {
                        na[(i + r) % n] = 1;
                    }
                }
                a = na;
            } else if (c == '1') {
                vector<int> na(n);
                for (int i = 0; i < n; i++) {
                    if (a[i] == 1) {
                        if (i < r) {
                            na[i - r + n] = 1;
                        } else {
                            na[i - r] = 1;
                        }
                    }
                }
                a = na;
            } else if (c == '?') {
                vector<int> na(n);
                for (int i = 0; i < n; i++) {
                    if (a[i] == 1) {
                        na[(i + r) % n] = 1;
                    }
                }
                for (int i = 0; i < n; i++) {
                    if (a[i] == 1) {
                        if (i < r) {
                            na[i - r + n] = 1;
                        } else {
                            na[i - r] = 1;
                        }
                    }
                }
                a = na;
            }
            /*for (auto &x : a)
                cout << x << " ";
            cout << endl;*/
        }
        int sum = 0;
        for (auto &x : a)
            sum += x;
        cout << sum << endl;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}

void solveE() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        vector<vector<int>> mp(n, vector<int> (m));
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> mp[y][x];
            }
        }

    }
}

int main() {
    solveB();
    return 0;
}