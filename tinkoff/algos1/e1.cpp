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
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j = 0;
    int ansI = 0;
    int ansJ = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && a[i] > b[j]) {
            if (abs(a[ansI] - b[ansJ]) > abs(a[i] - b[j])) {
                ansI = i;
                ansJ = j;
            }
            j++;
        }
        if (abs(a[ansI] - b[ansJ]) > abs(a[i] - b[j])) {
            ansI = i;
            ansJ = j;
        }
    }
    cout << a[ansI] << " " << b[ansJ] << endl;
    return 0;
}