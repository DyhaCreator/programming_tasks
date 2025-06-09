#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    set<int> st;
    map<int, int> th;
    map<int, int> mx;
    for (int i = 0; i < n; i++) {
        char ch;
        int id;
        cin >> ch >> id;
        st.insert(id);
        if (ch == '+') {
            th[id]++;
        } else {
            if (th[id] == 0) {
                mx[id]++;
            } else {
                th[id]--;
            }
        }
        mx[id] = max(mx[id], th[id]);
    }
    for (auto &x : st)
        cout << x << " " << mx[x] << endl;
    return 0;
}