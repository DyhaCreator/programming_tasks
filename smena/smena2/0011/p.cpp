#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a = {1};
    int y = 1;
    int last_x = 1;
    while (y < n) {
        a.push_back((1 << (y - 1)) ^ (1 << y) ^ x);
        y++;
    }
    cout << a.size() << endl;
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}