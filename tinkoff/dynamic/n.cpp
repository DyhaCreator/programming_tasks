#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int >> a = vector<vector<int >> (n + 2, vector<int>());
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1];
        a[i].push_back(1);
        if (i % 2 == 0 && a[i / 2].size() + 1 < a[i].size()) {
            a[i] = a[i / 2];
            a[i].push_back(2);
        }
        if (i % 3 == 0 && a[i / 3].size() + 1 < a[i].size()) {
            a[i] = a[i / 3];
            a[i].push_back(3);
        }
    }
    for (auto x : a[n])
        cout << x;
    cout << endl;
    return 0;
}