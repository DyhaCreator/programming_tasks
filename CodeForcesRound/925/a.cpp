#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#define ll long long
#define INF 1000000007
#define prvec(vec) for(auto &x:vec)cout<<x<<" ";cout<<endl;
#define all(vec) vec.begin(),vec.end()
using namespace std;

void solveA() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string str;
        bool find = false;
        for (int a = 1; a <= 26; a++) {
            for (int b = 1; b <= 26; b++) {
                for (int c = 1; c <= 26; c++) {
                    if (a + b + c == n && find == false) {
                        str.push_back('a' - 1 + a);
                        str.push_back('a' - 1 + b);
                        str.push_back('a' - 1 + c);
                        find = true;
                    }
                }
            }
        }
        cout << str << endl;
    }
}

void solveB() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        ll sum = 0;
        for (auto &x : a) {
            cin >> x;
            sum += x;
        }
        ll av = sum / n;
        // cout << av << endl;
        ll ss = 0;
        bool find = false;
        for (int j = 0; j < n; j++) {
            ss += a[j] - av;
            if (ss < 0) {
                cout << "NO" << endl;
                find = true;
                break;
            }
        }
        if (!find) {
            cout << "YES" << endl;
        }
    }
}

void solveC() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> map(n);
        for (auto &x : map)
            cin >> x;
        vector<int> a(n + 1);
        for(auto &x : map)
            a[x]++;
        int ans = INF;
        bool find = false;
        for (int j = 0; j <= n; j++) {
            if (a[j] > 0) {
                // cout << j << endl;
                int sindex = 0;
                while (sindex < n && map[sindex] == j) {
                    sindex++;
                }
                if (sindex == n) {
                    cout << 0 << endl;
                    find = true;
                    break;
                }
                int findex = n - 1;
                while (findex > sindex && map[findex] == j) {
                    findex--;
                }
                // cout << sindex << " " << findex << endl;
                ans = std::min(ans, findex - sindex + 1);
            }
        }
        if (!find) cout << ans << endl;
        // cout << endl;
    }
}

int main() {
    solveC();
    return 0;
}