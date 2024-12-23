#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (auto &x : st)
            cout << x << " ";
        cout << endl;
        cout << st.upper_bound(x) << endl;
        st.insert(x);
    }

    return 0;
}