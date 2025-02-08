#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    for (int i = 0; i < n; i++)
        if (9 - (a[i] - '0') < a[i] - '0' && !(9 - (a[i] - '0') == 0 && i == 0))
            a[i] = 9 - (a[i] - '0') + '0';
    cout << a << endl;
    return 0;
}