#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int f1 = 0;
    int f2 = 1;
    int b = 1;
    for (int i = 1; i < n; i++) {
        int b = f1 + f2;
        f1 = f2;
        f2 = b;
        cout << f1 << " " << f2 << " " << b << endl;
    }
    cout << b << endl;
    return 0;
}