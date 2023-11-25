#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n + 3);
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i < n + 3; i++) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    cout << a[n + 2] << endl;
    return 0;
}