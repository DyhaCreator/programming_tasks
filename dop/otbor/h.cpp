#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &x : a)
        cin >> x;
    vector<int> b(n);
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (b[a[i] - 1] == 0) {
            count++;
        }
        b[a[i] - 1]++;
        if (count == n) {
            cout << 1;
            count = 0;
            for (auto &x : b) {
                x--;
                if (x > 0) {
                    count++;
                }
            }
        } else {
            cout << 0;
        }
        /*for (auto &x : b)
            cout << x << " ";
        cout << endl;*/
    }
    cout << endl;
    return 0;
}