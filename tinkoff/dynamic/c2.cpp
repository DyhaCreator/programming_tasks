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
    vector<int>a = vector<int>(n + 2);
    a[0] = 0;
    a[1] = map[0];
    for (int i = 2; i < n + 1; i++) {
        a[i] = min(a[i - 1], a[i - 2]) + map[i - 1];
    }
    cout << a[n] << endl;
    return 0;
}