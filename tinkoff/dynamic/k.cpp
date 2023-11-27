#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>map = vector<int>(n);
    for (auto &x : map)
        cin >> x;
    sort(map.begin(), map.end());
    vector<int>a = vector<int>(n - 1);
    a[0] = 1;
    a[a.size() - 1] = 1;
    for (int i = 1; i < n - 1; i++) {
        if (map[i] - map[i - 1] < map[i + 1] - map[i]) {
            a[i - 1] = 1;
        } else if (map[i] - map[i - 1] == map[i + 1] - map[i]) {
            if (a[i - 1] != 1 && a[i] != 1) {
                a[i - 1] = 1;
            }
        } else {
            a[i] = 1;
        }
        /*for (auto x : a)
            cout << x << " ";
        cout << endl;*/
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (map[i + 1] - map[i]) * a[i];
    }
    cout << ans << endl;
    return 0;
}