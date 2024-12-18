#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

vector<char>v;
string str;

void rec(int n, vector<char> &vars) {
    if (n == vars.size()) {
        int index = 0;
        for (auto &x : str) {
            if (x == '*') {
                cout << vars[index];
                index++;
            } else {
                cout << x;
            }
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        vars[n] = v[i];
        rec(n + 1, vars);
    }
}

int main() {
    int n;
    cin >> n;
    cin >> str;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '*') {
            count++;
        }
    }
    int m;
    cin >> m;
    v = vector<char>(m);
    for (auto &x : v)
        cin >> x;
    vector<char>vars(count);
    rec(0, vars);
    return 0;
}