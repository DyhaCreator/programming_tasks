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
    int cnt1 = 0;
    int cnt2 = 0;
    for (auto &x : a)
        if (x == 1) cnt1++;
        else cnt2++;
    if (cnt2 > 0) {
        cout << 2 << " ";
        cnt2--;
    }
    if (cnt1 > 0) {
        cout << 1 << " ";
        cnt1--;
    }
    while (cnt2 > 0) {
        cout << 2 << " ";
        cnt2--;
    }
    while (cnt1 > 0) {
        cout << 1 << " ";
        cnt1--;
    }
    cout << endl;
    return 0;
}