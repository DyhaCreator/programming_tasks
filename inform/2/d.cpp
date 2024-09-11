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
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        a[x - 1]--;
    }
    for (auto &x : a)
        if (x >= 0) cout << "no" << endl;
        else cout << "yes" << endl;
    return 0;
}