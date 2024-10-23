#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string str;
    cin >> str;
    int n = str.size();
    int f = 0;
    for (int i = 0; i < 8; i++) {
        // cout << i << endl;
        stack<int> st;
        int found = 0;
        for (auto &x : str) {
            if (x == 'A') {
                if ((i & 0b100) > 0) {
                    st.push(1);
                } else {
                    if (!st.empty()) {
                        st.pop();
                    } else {
                        found = 1;
                        break;
                    }
                }
            }
            if (x == 'B') {
                if ((i & 0b10) > 0) {
                    st.push(1);
                } else {
                    if (!st.empty()) {
                        st.pop();
                    } else {
                        found = 1;
                        break;
                    }
                }
            }
            if (x == 'C') {
                if ((i & 0b1) > 0) {
                    st.push(1);
                } else {
                    if (!st.empty()) {
                        st.pop();
                    } else {
                        found = 1;
                        break;
                    }
                }
            }
        }
        if (!st.empty()) {
            found = 1;
        }
        if (!found) {
            f = 1;
            break;
        }
    }
    if (!f) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}