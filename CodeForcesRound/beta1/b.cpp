#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

string itos(int a) {
    string str = "";
    a--;
    while (a >= 0) {
        str.push_back(char(a % 26 + 65));
        a /= 26;
        a--;
    }
    reverse(str.begin(), str.end());
    return str;
}

int f(string str) {
    ll ans = 0;
    ll st = 1;
    for (int i = 0; i < str.size(); i++) {
        ans += (str[str.size() - i - 1] - 64) * st;
        st *= 26;
    }
    return ans;
}

int solve() {
    string str;
    cin >> str;
    if (str[0] == 'R') {
        int index = 1;
        while (str[index] < 60) {
            index++;
        }
        int a = stoi(str.substr(1, index - 1));
        // cout << stoi(str.substr(1, index - 1)) << endl;
        int b = stoi(str.substr(index + 1));
        // cout << a << " " << b << endl;
        cout << itos(b) << a << endl;
    } else {
        int index = 0;
        while (str[index] > 60) {
            index++;
        }
        int b = stoi(str.substr(index));
        cout << "R" << b << "C" << f(str.substr(0, index)) << endl;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}