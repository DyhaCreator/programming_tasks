#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int save = a[k];
    for (auto &x : a)
        cout << x + save << " ";
    cout << endl;
    return 0;
}