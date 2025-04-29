#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (auto &x : s) {
        if (x != '*') {
            st.push(x);
        } else {
            cout << st.top();
            st.pop();
        }
    }
    cout << endl;
    return 0;
}