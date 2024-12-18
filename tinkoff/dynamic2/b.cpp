#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<ll>m = vector<ll>(n);
    for (auto &x : m)
        cin >> x;
    m.push_back(0);
    vector<ll>a = vector<ll>(w + 1, 0);
    vector<vector<int >> index = vector<vector<int >> (w + 1, vector<int>());
    for (int i = 1; i <= w; i++) {
        int ind = n;
        for (int j = 0; j < n; j++) {
            if (i - m[j] >= 0 && find(index[i - m[j]].begin(), index[i - m[j]].end(), j) == index[i - m[j]].end()) {
                if (a[i - m[j]] + m[j] > a[i - m[ind]] + m[ind]) {
                    ind = j;
                }
            }
        }
        if (m[ind] != 0) {
            a[i] = a[i - m[ind]] + m[ind];
            index[i] = index[i - m[ind]];
            index[i].push_back(ind);
        } else {
            a[i] = a[i - 1];
            index[i] = index[i - 1];
        }
    }
    cout << a[w] << endl;
    return 0;
}