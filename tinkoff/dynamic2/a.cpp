#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int>m = vector<int>(n);
    for (auto &x : m) 
        cin >> x;
    vector<int>a = vector<int>(w + 1, 0);
    vector<vector<int >> index = vector<vector<int >> (w + 1, vector<int>());
    a[0] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 0; j < n; j++) {
            if (i - m[j] >= 0 && a[i - m[j]] == 1 && find(index[i - m[j]].begin(), index[i - m[j]].end(), j) == index[i - m[j]].end()) {
                a[i] = a[i - m[j]];
                index[i] = index[i - m[j]];
                index[i].push_back(j);
                break;
            }
        }
    }
    cout << ((a[w] == 1)?"yes":"no") << endl;
    return 0;
}