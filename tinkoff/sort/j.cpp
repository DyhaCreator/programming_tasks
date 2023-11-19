#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>map = vector<int>(n * m);
    for (auto &x : map)
        cin >> x;
    int k;
    cin >> k;
    vector<int>a = vector<int>(k);
    for (auto &x : a)
        cin >> x;
    sort(map.begin(), map.end());
    sort(a.begin(), a.end());
    reverse(map.begin(), map.end());
    reverse(a.begin(), a.end());
    int it_map = 0;
    int ans = 0;
    for (int i = 0; i < k && it_map < n * m; i++) {
        if (map[it_map] >= a[i]) {
            ans++;
            it_map++;
        }
    }
    cout << ans << endl;
    return 0;
}