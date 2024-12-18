#include <iostream>
#include <string>
#include <stack>
#define ll long long

using namespace std;

int main() {
    stack<char>st;
    string str;
    cin >> str;
    int n = str.size();
    bool b = true;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } else if ((str[i] == ')' || str[i] == '}' || str[i] == ']') && st.empty()) {
            b = false;
            break;
        } else if ((str[i] == ')' && st.top() == '(') || (str[i] == '}' && st.top() == '{') || (str[i] == ']' && st.top() == '[')) {
            st.pop();
        } else {
            b = false;
            break;
        }
    }
    if (b && st.empty()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}