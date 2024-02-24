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

void solveD() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> mp(n);
        for (auto &x : mp)
            cin >> x;
        int ans = 0;
        for (int y = 0; y < n - 1; y++) {
            for (int x = y + 1; x < n; x++) {
                if (abs(mp[y] + mp[x]) % a == 0 && abs(mp[y] - mp[x]) % b == 0) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

void solveE() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n, m;
        cin >> n >> m;
        vector<string> vec(n);
        for (auto &x : vec)
            cin >> x;
        int indexA = 0;
        for (int i = 0; i < n - 1; i++) {
            while (indexA < n && vec[indexA][vec[indexA].size() - 1] != 0) {
                indexA++;
            }

            if (indexA == n) indexA--;
            cout << indexA << endl;

            string str = vec[indexA];
            // cout << str << endl;
            int j = 1;
            while (str[n - j] == '0') {
                j++;
            }
            
            string newStr = "";
            for (int k = 0; k < n - j; k++) {
                newStr.push_back(str[k]);
            }
            vec[indexA] = newStr;


            string el1 = vec[0], el2 = vec[1];
            
        }
    }
}

int main() {
    solveE();
    return 0;
}