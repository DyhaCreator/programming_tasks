#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    cout << (a - n) * (b - m) << endl;
    return 0;
}