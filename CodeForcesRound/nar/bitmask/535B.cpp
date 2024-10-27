#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string n;
    cin >> n;
    int ans = 0;
    for (auto &x : n) {
        ans *= 2;
        if (x == '7')
            ans++;
    }
    int save = ans;
    for (int i = 0; i < n.size(); i++)
        ans += (1 << i);
    cout << ans << endl;
    return 0;
}