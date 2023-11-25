#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<ll >> a = vector<vector<ll >> (n, vector<ll>(3));
    a[0][0] = 1;
    a[0][1] = 1;
    a[0][2] = 1;
    for (int i = 1; i < n; i++) {
        a[i][0] = a[i - 1][1] + a[i - 1][2];
        a[i][1] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2];
        a[i][2] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2];
    }
    cout << a[n - 1][0] + a[n - 1][1] + a[n - 1][2] << endl;
    return 0;
}