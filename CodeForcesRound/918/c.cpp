#include <iostream>
#include <cmath>
#define ll long long
using namespace std;



int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            sum += x;
        }
        if (sqrt(sum) - int(sqrt(sum)) == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}