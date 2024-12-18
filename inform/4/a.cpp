#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    for (int i = 100; i < n; i++) {
        if (i % 10 != i / 10 % 10 && i % 10 != i / 100 % 10 && i / 10 % 10 != i / 100 % 10) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}