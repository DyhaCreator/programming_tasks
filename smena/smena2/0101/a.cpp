#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    map<string, int> mp;
    set<string> st;
    while (cin >> a) {
        int cnt = 0;
        for (auto &x : a)
            if (x == '#') cnt++;
        if (cnt == 1 && a[0] == '#' && a.size() > 1) {
            mp[a]++;
            st.insert(a);
        }
    }
    cout << st.size() << endl;
    for (auto &x : st)
        cout << x << " " << mp[x] << endl;
    return 0;
}