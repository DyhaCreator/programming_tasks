#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int >> a = vector<vector<int >> (n + 1, vector<int>(10, 0));
    a[1] = vector<int>(10, 1);
    for (int i = 2; i <= n; i++) {
        a[i] = {
            a[i - 1][0] + a[i - 1][1],
            a[i - 1][0] + a[i - 1][1] + a[i - 1][2],
            a[i - 1][1] + a[i - 1][2] + a[i - 1][3],
            a[i - 1][2] + a[i - 1][3] + a[i - 1][4],
            a[i - 1][3] + a[i - 1][4] + a[i - 1][5],
            a[i - 1][4] + a[i - 1][5] + a[i - 1][6],
            a[i - 1][5] + a[i - 1][6] + a[i - 1][7],
            a[i - 1][6] + a[i - 1][7] + a[i - 1][8],
            a[i - 1][7] + a[i - 1][8] + a[i - 1][9],
            a[i - 1][8] + a[i - 1][9]
        };
    }
    cout << a[n][1] + a[n][2] + a[n][3] + a[n][4] + a[n][5] + a[n][6] + a[n][7] + a[n][8] + a[n][9] << endl;
    return 0;
}