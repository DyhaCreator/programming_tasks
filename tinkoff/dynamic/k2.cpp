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
    vector<int>a = vector<int>(n);
    a[0] = 1e9;
    a[1] = map[1] - map[0];
    for (int i = 2; i < n; i++) {
        a[i] = min(a[i - 1], a[i - 2]) + (map[i] - map[i - 1]);
    }
    cout << a[n - 1] << endl;
    return 0;
}