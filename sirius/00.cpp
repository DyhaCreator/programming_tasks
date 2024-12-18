#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ll long long
using namespace std;

/*struct sock{
    int start, end;
    sock() {}
    sock(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool comp(sock &a, sock &b) {
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}*/

int main() {
    int l, n, m;
    cin >> l >> n >> m;

    multiset<pair<int, int>> st;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        st.insert(pair(x, -2));
        st.insert(pair(y + 1, -1));
    }
    vector<int> ms;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        st.insert(pair(x, 0));
        ms.push_back(x);
    }
    map<int, int> mp;
    int h = 0;
    for (auto &x : st) {
        // cout << x.first << " " << x.second << endl;
        if (x.second == -2) {
            h += 1;
        } else if (x.second == -1) {
            h -= 1;
        } else if (x.second == 0) {
            // cout << h << endl;
            mp[x.first] = h;
        }
    }
    for (auto &x : ms)
        cout << mp[x] << "\n";
    return 0;
}