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
    vector<int> count(100000 + 7);
    int index = 0;
    for (int i = 0; i < 100000 + 7; i++) {
        while (index < n && a[index] <= i)
            index++;
        count[i] = index;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        if (m > 100000) {
            cout << n << endl;
            continue;
        }
        cout << count[m] << endl;
    }
    return 0;
}