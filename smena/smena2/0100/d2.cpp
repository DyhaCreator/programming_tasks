#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n;

int nod(int a, int b) {
    while (b > 0) {
        a %= b;
        int buff = a;
        a = b;
        b = buff;
    }
    return a;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    set<int> st;
    set<pair<int, int>> b;
    for (int i = 0; i < n; i++)
        st.insert(i);
    for (int i = 1; i < n; i++) {
        if (nod(a[i], a[i - 1]) == 1)
            b.insert({i - 1, i});
    }
    if (nod(a[0], a[n - 1]) == 1) b.insert({0, n - 1});
    for (auto &x : b)
        cout << x.F << " " << x.S << endl;
    cout << endl;
    while (b.size() != 0) {
        vector<int> nums = {};
        for (auto &x : st)
            nums.push_back(x);
        for (int i = 1; i < nums.size(); i++) {
            int ss = b.size();
            b.erase({nums[i - 1], nums[i]});
            if (b.size() < ss) {
                st.erase(nums[i]);
                ss = b.size();
                b.erase({nums[i - 1], nums[(i + 1) % n]});
                if (b.size() < ss) {
                    b.insert({nums[i - 1], nums[(i + 1) % n]});
                }
            }
        }
        for (auto &x : st)
            cout << x << " ";
        cout << endl;
        for (auto &x : b)
            cout << x.F << " " << x.S << endl;
        break;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}