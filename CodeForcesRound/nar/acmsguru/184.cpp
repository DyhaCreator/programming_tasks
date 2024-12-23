#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int a, b, c;
    int d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    cout << min(min(a / d, b / e), c / f) << endl;
    return 0;
}