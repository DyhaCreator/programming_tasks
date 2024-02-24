#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#define ll long long
#define INF 1000000000000007
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

int main() {
    solveB();
    return 0;
}