#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int b, n;
    cin >> b >> n;
    vector<int>l = vector<int>(n);
    for (auto &x : l)
        cin >> x;
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    if (n == 0 || l[0] < b) {
        cout << 0 << endl;
        return 0;
    }
    int last = l[0];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (last - l[i] >= 3 && l[i] >= b) {
            ans++;
            last = l[i];
        }
    }
    cout << ans + 1 << endl;
    return 0;
}