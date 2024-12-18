#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a) 
        cin >> x;
    vector<int>b = vector<int>(n, 1e9 + 10);
    for (int i = 0; i < n; i++) {
        int max = 0;
        for (int j = 0; j < n - i; j++) {
            if (a[i + j] > max) {
                max = a[i + j];
            }
            if (max < b[j]) {
                b[j] = max;
            }
        }
    }
    for (auto x : b)
        cout << x << " ";
    cout << endl;
    //reverse(b.begin(), b.end());
    return 0;
}
/*

7
1 5 4 2 3 7 6

*/