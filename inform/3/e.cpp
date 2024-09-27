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
    int mini = 0;
    int minj = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(a[i] - a[j]) < abs(a[mini] - a[minj])) {
                mini = i;
                minj = j;
            }
        }
    }
    cout << abs(a[mini] - a[minj]) << endl;
    return 0;
}