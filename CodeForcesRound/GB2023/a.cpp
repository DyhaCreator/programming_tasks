#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>prime = {7, 17, 17};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        ll b = 1;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (b <= 2023) {
                b *= x;
            }
        }
        if (2023 % b != 0) {
            cout << "NO" << endl; 
        } else {
            cout << "YES" << endl;
            cout << 2023 / b << " ";
            for (int j = 0; j < k - 1; j++) {
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}