#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(string s) {
    stack<int> ind;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            ind.push(i);
        } else {
            ans += i - ind.top();
            ind.pop();
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int count = 0;
    for (auto &x : a) {
        if (x == '_') {
            if (count > 0) {
                x = ')';
            } else {
                x = '(';
            }
        }
        if (x == '(') {
            count++;
        } else if (x == ')') {
            count--;
        }
    }
    cout << f(a) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}