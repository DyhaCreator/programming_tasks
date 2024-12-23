#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    cout << n / 3 * 2 + ((n % 3 == 2)?1:0) << endl;
    return 0;
}