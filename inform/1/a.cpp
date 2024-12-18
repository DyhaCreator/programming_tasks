#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool f(char ch, string s) {
    for (auto &x : s)
        if (ch == x) return true;
    return false;
}

int main() {
    string str;
    getline(cin, str);
    string con = "AEIOUY";
    int ans = 0;
    for (auto &x : str)
        if (f(x, con)) ans++;
    cout << ans << endl;
    return 0;
}