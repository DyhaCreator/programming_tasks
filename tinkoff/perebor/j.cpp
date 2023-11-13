#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

void rec(int n, string str, stack<char>st) {
    int s = st.size();
    if (n == 0) {
        cout << str << endl;
        return;
    }
    if (s < n) {
        st.push('(');
        rec(n - 1, str + "(", st);
        st.pop();
        st.push('[');
        rec(n - 1, str + "[", st);
        st.pop();
    }
    if (!st.empty()) {
        if (st.top() == '(') {
            st.pop();
            rec(n - 1, str + ")", st);
        } else {
            st.pop();
            rec(n - 1, str + "]", st);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int nut;
    cin >> nut;
    if (nut % 2 == 0) {
        stack<char>st;
        rec(nut, "", st);
    }
    return 0;
}