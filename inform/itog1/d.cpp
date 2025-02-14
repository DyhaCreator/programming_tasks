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
    vector<int> tails = {};
    for (auto &x : a) {
        if (tails.size() == 0 || x > tails[tails.size() - 1]) {
            tails.push_back(x);
        } else {
            int l = 0;
            int r = tails.size() - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if(tails[m] < x) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            tails[l] = x;
        }
    }
    cout << n - tails.size() << endl;
    return 0;
}