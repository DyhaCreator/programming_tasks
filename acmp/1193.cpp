#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int a = (n - 1) * 3;
    int b = (n - 2);
    cout << a - b << endl;
    return 0;
}