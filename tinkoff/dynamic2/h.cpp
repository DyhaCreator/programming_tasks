#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>v = vector<int>(n);
    for (auto &x : v)
        cin >> x;
    vector<int>a = vector<int>(n + 1);
    a[0] = 0;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        int g = 0;
        for (int j = 1; j <= i; j++) {
            if (v[j - 1] < v[i - 1] && a[j] > a[g]) {
                g = j;
            }
        }
        a[i] = a[g] + 1;
        max = std::max(max, a[i]);
    }
    cout << max << endl;
    return 0;
}