#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>A = vector<int>(n);
    vector<int>B = vector<int>(n);
    vector<int>C = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }
    vector<int>a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + A[i - 1];
        if (i > 1 && a[i - 2] + B[i - 2] < a[i]) {
            a[i] = a[i - 2] + B[i - 2];
        }
        if (i > 2 && a[i - 3] + C[i - 3] < a[i]) {
            a[i] = a[i - 3] + C[i - 3];
        }
    }
    cout << a[n] << endl;
    return 0;
}