#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    set<pair<int, int>> st;
    st.insert({a[0], 0});
    for (int i = 1; i < n; i++) {
        if (st.rbegin()->F - a[i] >= 2)
            st.erase(*st.rbegin());
        st.insert({a[i], i});
    }
    cout << st.size() << endl;
    return 0;
}