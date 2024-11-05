#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << (1 << (n / 2)) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}