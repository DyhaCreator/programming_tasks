#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    set<char> st;
    vector<int> count(26, 0);
    for (auto &x : str) {
        st.insert(x);
        count[x - 'a']++;
    }
    string ans = "";
    while (true) {
        int sum = 0;
        for (auto &x : st) {
            if (count[x - 'a'] > 0) {
                ans.push_back(x);
                count[x - 'a']--;
                sum += count[x - 'a'];
            }

        }
        if (sum == 0) break;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}