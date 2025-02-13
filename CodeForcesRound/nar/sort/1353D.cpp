#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
    inline bool operator<(const int2 &b) const{
        if (y - x == b.y - b.x)
            return x < b.x;
        return y - x > b.y - b.x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    set<int2> st;
    st.insert(int2(0, n - 1));
    int i = 0;
    while (st.size() > 0) {
        i++;
        int l = st.begin()->x;
        int r = st.begin()->y;
        st.erase(int2(l, r));
        a[(l + r) / 2] = i;
        if (l <= (l + r) / 2 - 1) st.insert(int2(l, (l + r) / 2 - 1));
        if ((l + r) / 2 + 1 <= r) st.insert(int2((l + r) / 2 + 1, r));
    }
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}