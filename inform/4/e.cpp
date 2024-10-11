#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            if (!st.empty()) {
                if (s[i] == '}' && st.top() == '{') st.pop();
                else if (s[i] == ']' && st.top() == '[') st.pop();
                else if (s[i] == ')' && st.top() == '(') st.pop();
                else {cout << i + 1 << endl;return 0;}
            } else {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    if (!st.empty()) cout << -1 << endl;
    else cout << 0 << endl;
    return 0;
}