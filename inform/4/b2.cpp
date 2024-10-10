#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int ans = INF;

void gen(string &s, int k, int num) {
    if (num >= k) {
        ans = min(ans, num);
        return;
    }
    for (auto &x : s) {
        if (x - '0' != num % 10) {
            gen(s, k, num * 10 + x - '0');
        }
    }
}

int main() {
    string str;
    getline(cin, str);
    int k;
    cin >> k;
    if (str.size() <= 1) {
        cout << -1 << endl;
        return 0;
    } else {
        gen(str, k, 0);
        cout << ans << endl;
    }
    return 0;
}