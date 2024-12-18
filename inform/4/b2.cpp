#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int ans = INF;
string s;

void gen(int k, int num) {
    if (num >= k) {
        ans = min(ans, num);
        return;
    }
    for (auto &x : s)
        if (x - '0' != num % 10)
            gen(k, num * 10 + x - '0');
}

int main() {
    getline(cin, s);
    int k;cin >> k;
    if (s.size() < 2) {
        cout << -1 << endl;
        return 0;
    }
    gen(k, 0);
    cout << ans << endl;
    return 0;
}