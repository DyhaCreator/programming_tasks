#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int >> a = vector<vector<int >> (n + 1, vector<int>(1, 0));
    a[0] = {1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            a[i].push_back(a[i].back() + a[i - j][min(int(a[i - j].size() - 1), j - 1)]);
        }
    }
    cout << a[n].back() << endl;
    return 0;
}