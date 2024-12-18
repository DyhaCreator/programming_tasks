#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void f(vector<int>&p1, vector<int>&p2, int n) {
    for (int y = 1; y < n + 1; y++) {
        for (int x = 0; x < y; x++) {
            int sum1 = p1[y] - p1[x];
            int sum2 = p2[y] - p2[x];
            if (sum1 == sum2) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int>a = vector<int>(n);
        for (auto &x : a)
            cin >> x;
        vector<int>p1 = vector<int>(n + 1);
        vector<int>p2 = vector<int>(n + 1);
        for (int j = 1; j <= n; j++) {
            if (j % 2 == 0) {
                p1[j] = p1[j - 1] + a[j - 1];
                p2[j] = p2[j - 1];
            } else {
                p1[j] = p1[j - 1];
                p2[j] = p2[j - 1] + a[j - 1];
            }
        }
        f(p1, p2, n);
    }
    return 0;
}