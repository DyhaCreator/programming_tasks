#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] - a[j] > 5) {
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << endl;
    return 0;
}