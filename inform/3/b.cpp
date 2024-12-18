#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    int num = 1;
    for (int i = 0; i <= n + n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < i; j++) {
                if (j < n && i - j - 1 < n) {
                    vec[j][i - j - 1] = num;
                    num++;
                }
            }
        } else {
            for (int j = i - 1; j >= 0; j--) {
                if (j < n && i - j - 1 < n) {
                    vec[j][i - j - 1] = num;
                    num++;
                }
            }
        }
    }
    for (auto &x : vec) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}