#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>a = vector<int>();
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int>sum = vector<int>(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        sum[i] = sum[i - 1] + ((a[i] > a[i - 1])?1:0);
    }
    int min = 1e9 + 10;
    for (int i = 0; i + k <= n + 1; i++) {
        if (sum[i + k - 1] - sum[i] < min) {
            min = sum[i + k - 1] - sum[i];
        }
    }
    cout << min << endl;
    return 0;
}