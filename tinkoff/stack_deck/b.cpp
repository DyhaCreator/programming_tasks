#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define ll long long
using namespace std;

int main() {
    vector<string>tokens = vector<string>();
    string token;
    while (cin >> token) {
        tokens.push_back(token);
    }
    stack<int>st;
    for (int i = 0; i < tokens.size(); i++) {
        string sym = "+-*/";
        if (sym.find(tokens[i]) != string::npos) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int ans;
            if (tokens[i] == "+") ans = b + a;
            if (tokens[i] == "-") ans = b - a;
            if (tokens[i] == "*") ans = b * a;
            if (tokens[i] == "/") ans = b / a;
            st.push(ans);
        } else {
            st.push(stoi(tokens[i]));
        }
    }
        
    cout << st.top() << endl;
    return 0;
}