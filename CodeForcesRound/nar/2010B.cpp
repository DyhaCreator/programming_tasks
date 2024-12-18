#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        int buff = b;
        b = a;
        a = buff;
    }
    if (a == 1 && b == 2) cout << 3 << endl;
    if (a == 1 && b == 3) cout << 2 << endl;
    if (a == 2 && b == 3) cout << 1 << endl;
    return 0;
}