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
    map.push_back(0);
    vector<int>a = vector<int>(n + 1);
    a[0] = map[0];
    a[1] = map[0] + map[1];
    for (int i = 2; i <= n; i++) {
        a[i] = min(a[i - 1], a[i - 2]) + map[i];
    }
    cout << a[n] << endl;
    return 0;
}