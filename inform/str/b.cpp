#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool in(char ch, string a) {
    for (auto &x : a)
        if (x == ch) return 1;
    return 0;
}

int main() {
    string a;
    cin >> a;
    string al = "eyuioa";
    stack<char> st;
    for (auto &x : a) {
        if (in(x, al) && (!st.empty() && in(st.top(), al)))
            st.pop();
        st.push(x);
    }
    string b = "";
    while (!st.empty()) {
        b.push_back(st.top());
        st.pop();
    }
    reverse(b.begin(), b.end());
    cout << b << endl;
    return 0;
}