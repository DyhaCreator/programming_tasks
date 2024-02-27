#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define INF 1000000007
#define prvec(vec) for(auto &x:vec)cout<<x<<" ";cout<<endl;
#define all(vec) vec.begin(),vec.end()
using namespace std;

void solveA() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += abs(x);
        }
        cout << sum << endl;
    }
}

void solveB() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        bool findO1 = false;
        ll sum = 0;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
            sum += x;
            if (x % 3 == 1) findO1 = true;
        }
        if (sum % 3 == 0) {
            cout << 0 << endl;
        } else if (sum % 3 == 2) {
            cout << 1 << endl;
        } else if (sum % 3 == 1) {
            if (findO1) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
        // cout << sum << endl;
    }
}

bool f(int a, int b) {
    int buffB = 1;
    while (buffB < a) {
        buffB *= b;
    }
    return buffB == a;
}

void solveC() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        ll a, b, l;
        cin >> a >> b >> l;
        ll buffMin = min(a, b);
        a = max(a, b);
        b = buffMin;
        // cout << a << " " << b << endl;
        if (f(a, b)) {
            int ans = 0;
            ll buffB = 1;

            for (int x = 0; buffB <= l; x++) {
                // cout << buffB << endl;
                if (buffB <= l) {
                    if (l % buffB == 0) {
                        ans++;
                    }
                }
                buffB *= b;
            }
            cout << ans << endl;
            // cout << -1 << endl;
        } else {
            int ans = 0;
            ll buffA = 1;
            ll buffB = 1;
            for (int x = 0; buffA <= l; x++) {
                buffB = 1;
                for (int y = 0; buffB <= l; y++) {
                    // cout << buffA << " " << buffB << endl;
                    if (buffB * buffA <= l) {
                        if (l % (buffA * buffB) == 0) {
                            ans++;
                        }
                    }
                    buffB *= b;
                }
                buffA *= a;
                // cout << buffA << " " << buffB << endl;
            }
            cout << ans << endl;
        }
    }
}

void solveD() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)   
            cin >> x;
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }
        sort(a.begin(), a.end());
        if (a[0] == a[1]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(NULL);
    solveC();
    return 0;
}