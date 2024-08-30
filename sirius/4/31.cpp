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
    vector<int> b(k);
    int cnt = k;
    int l = -1, r = INF;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (b[a[i] - 1] == 0) cnt--;
        b[a[i] - 1]++;
        for (auto &x : b)
            cout << x << " ";
        cout << endl;
        while (cnt == 0) {
            b[a[j] - 1]--;
            if (b[a[j] - 1] == 0) cnt++;
            j++;
        }
        cout << j << " " << i << endl;
        if (j - i < r - l) {
            l = j;
            r = i;
        }
    }
    cout << l << " " << r << endl;
    return 0;
}