#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a, b;
    cin >> a >> b;
    int ans1 = 0;
    int ans2 = 0;
    vector<int> count(10);
    for (auto &x : b)
        count[x - '0']++;
    for (int i = 0; i < 4; i++) {
        if (a[i] == b[i]) {
            ans1++;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (count[a[i] - '0'] > 0) {
            ans2++;
            count[a[i]]--;
        }
    }
    cout << ans1 << " " << ans2 - ans1 << endl;
    return 0;
}