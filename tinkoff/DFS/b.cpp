#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x]++;
        g[y]++;
    }
    for (auto &x : g)
        cout << x << " ";
    cout << endl;
    return 0;
}