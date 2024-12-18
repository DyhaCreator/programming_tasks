#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int min = 0;
        int max = 1000000000;
        vector<int>v = vector<int>();
        for (int j = 0; j < n; j++) {
            int a, x;
            cin >> a >> x;
            if (a == 1) {
                if (x > min) {
                    min = x;
                }
            } else if (a == 2) {
                if (x < max) {
                    max = x;
                }
            } else if (a == 3) {
                v.push_back(x);
            }
        }
        int ans = max - min + 1;
        if (ans > 0) {
            for (auto &x : v) {
                if (x >= min && x <= max) {
                    ans--;
                }
            }
        } else {
            ans = 0;
        }
        cout << ans << endl;
    }
}