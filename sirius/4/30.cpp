#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b)
        cin >> x;
    int min_a = a[0];
    int min_b = b[0];
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (b[j] < a[i] && j < m)
            j++;
        if (abs(b[j] - a[i]) < abs(min_b - min_a)) {
            min_b = b[j];
            min_a = a[i];
        }
        if (j > 0 && abs(b[j - 1] - a[i]) < abs(min_b - min_a)) {
            min_b = b[j - 1];
            min_a = a[i];
        }
        if (j < m - 1 && abs(b[j + 1] - a[i]) < abs(min_b - min_a)) {
            min_b = b[j + 1];
            min_a = a[i];
        }
    }
    cout << min_a << " " << min_b << endl;
    return 0;
}