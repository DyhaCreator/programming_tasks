#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ll long long
using namespace std;

vector<int>p;
set<int>st;
map<int, int>mp;

int f(int n, map<int, int>mmm, int last) {
    if (n == p.size()) {
        //cout << endl;
        return 1;
    }
    int ans = 0;
    for (auto x : st) {
        if (mmm[x] < mp[x] && abs(x - last) == 1) {
            mmm[x]++;
            //cout << x << endl;
            ans += f(n + 1, mmm, x);
            mmm[x]--;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        mp = map<int, int>();
        st = set<int>();
        p = vector<int>(n);
        for (auto &x : p) {
            cin >> x;
            st.insert(x);
            mp[x]++;
        }
        map<int, int>mmm;
        cout << f(0, mmm, 0) << endl;
    }
    return 0;
}