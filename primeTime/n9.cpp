#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    vector<int> ans = {};
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')' && count == 0) {
            s[i] = '(';
            ans.push_back(i);
            count++;
        } else if (s[i] == ')') {
            count--;
        } else {
            count++;
        }
    }
    count = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(' && count == 0) {
            s[i] = ')';
            ans.push_back(i);
            count++;
        } else if (s[i] == '(') {
            count--;
        } else {
            count++;
        }
    }
    // cout << s << endl;
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x + 1 << endl;
    return 0;
}