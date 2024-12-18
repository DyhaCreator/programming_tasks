#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int la = 1e9 + 7;
        int lb = 1e9 + 7;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (la == 1e9 + 7 && lb == 1e9 + 7) {
                la = x;
            } else if (la == 1e9 + 7) {
                la = x;
            } else if (lb == 1e9 + 7) {
                lb = x;
            } else if (la >= x && lb >= x) {
                if (la - x < lb - x) {
                    la = x;
                } else {
                    lb = x;
                }
            } else if (la >= x && lb < x) {
                la = x;
            } else if (la < x && lb >= x) {
                lb = x;
            } else if (la < x && lb < x) {
                if (x - la > x - lb) {
                    la = x;
                } else {
                    lb = x;
                }
                ans++;
            }
            //cout << la << " " << lb << endl;
        }
        cout << ans << endl;
    }
    return 0;
}