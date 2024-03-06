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
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        int y = 1;
        while (y <= n) {
            y *= 2;
        }
        cout << y / 2 << endl;
    }
}

/*bool comp(string &a, string &b, int start) {
    for (int i = start; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool comp2(string &a, string &b, int start) {
    for (int i = start; i < a.size(); i++) {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
    }
    return false;
}*/

void solveB() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        // cout << n << endl;
        string mp1;
        string mp2;
        cin >> mp1;
        cin >> mp2;
        string th = mp1[0] + mp2;
        string minS = th;
        int c = 0;
        int ans = 1;
        // cout << minS << endl;
        for (int i = 1; i < n; i++) {
            th[i] = mp1[i];
            // cout << minS << " " << th << " " << comp2(th, minS, c) << endl;
            if (comp2(th, minS, c)) {
                minS = th;
                ans = 1;
                // cout << 'a' << endl;
            } else if (comp(th, minS, c)) {
                ans++;
                // cout << 'b' << endl;
            }
            c = i;
            // cout << minS << endl;
            // cout << ans << endl;
        }
        cout << minS << endl;
        cout << ans << endl;
    }
}

void solveB2() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        string mp1, mp2;
        cin >> mp1 >> mp2;
        string th = mp1[0] + mp2;
        
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(NULL);
    solveB2();
    return 0;
}