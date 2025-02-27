#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int col = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            int y = 1;
            while (y * i <= n) {
                if (a[y * i] == 0) a[y * i] = col;
                y++;
            }
            col++;
        }
    }
    for (int i = 2; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}