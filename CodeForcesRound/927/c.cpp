#include <iostream>
#include <vector>
#define ll long long
using namespace std;

/*ll f(vector<int> &a, int m, int start, int end) {
    ll all = 1;
    for (int i = start; i <= end; i++) {
        all = (all * a[i]) % m;
    }
    return all;
}*/

ll f(ll prev, int m, int del) {
    
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        string str;
        cin >> str;
        int l = 0;
        int r = n - 1;
        for (auto &x : str) {
            if (x == 'L') {
                cout << f(a, m, l, r) << " ";
                l++;
            } else {
                cout << f(a, m, l, r) << " ";
                r--;
            }
        }
        cout << endl;
    }
    return 0;
}