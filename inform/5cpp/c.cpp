#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cout << (i + 1) * (j + 1) << " ";
        }
        cout << endl;
    }
    return 0;
}