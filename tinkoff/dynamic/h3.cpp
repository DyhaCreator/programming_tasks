#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int >> a = vector<vector<int >> (n + 3, vector<int>(m + 3));
    int s = max(n, m);
    for (int sum = 2; sum <= s + s; sum++) {
        for (int x = max(sum - s, 1); x <= sum - max(sum - s, 1); x++) {
            int y = sum - x;
            if (x <= m && y <= n) {
                if (x + 1 == 2 && y + 1 == 2) {
                    a[y + 1][x + 1] = 1;
                } else {
                    a[y + 1][x + 1] = a[y + 1 - 2][x + 1 + 1] + a[y + 1 - 2][x + 1 - 1] + a[y + 1 - 1][x + 1 - 2] + a[y + 1 + 1][x + 1 - 2];
                }
            }
        }
    }
    cout << a[n + 1][m + 1] << endl;
    return 0;
}