#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int >> a = vector<vector<int >> (n, vector<int>(10));
    a[0] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1};
    for (int i = 1; i < n; i++) {
        a[i] = {a[i - 1][4] + a[i - 1][6], 
                a[i - 1][8] + a[i - 1][6],
                a[i - 1][9] + a[i - 1][7],
                a[i - 1][8] + a[i - 1][4],
                a[i - 1][9] + a[i - 1][3] + a[i - 1][0],
                0,
                a[i - 1][0] + a[i - 1][1] + a[i - 1][7],
                a[i - 1][2] + a[i - 1][6],
                a[i - 1][1] + a[i - 1][3],
                a[i - 1][2] + a[i - 1][4]};
    }
    cout << a[n - 1][0] + 
            a[n - 1][1] + 
            a[n - 1][2] + 
            a[n - 1][3] + 
            a[n - 1][4] + 
            a[n - 1][5] + 
            a[n - 1][6] + 
            a[n - 1][7] + 
            a[n - 1][8] + 
            a[n - 1][9] << endl;
    return 0;
}