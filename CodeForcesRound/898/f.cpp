#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int>a = vector<int>(n);
        vector<int>h = vector<int>(n);
        vector<bool>prefH = vector<bool>(n + 1);
        for (auto &x : a)
            cin >> x;
        for (auto &x : h)
            cin >> x;
        for (int j = 0; j < n - 1; j++) {
            prefH[j] = (h[j] % h[j + 1] == 0);
        }
        for (auto x : prefH)
            cout << x << " ";
        cout << endl;
        int ans = 0;
        int j = 0;
        int sum = 0;
        int len = 0;
        while (j < n) {
            cout << j << " " << len << endl;
            if (prefH[j] == false) {
                sum++;
                if (len > 0) {
                    int l = j - len;
                    int r = j;
                    for (int i = 0; )
                }
                len = 0;
            } else {
                len++;
            }
            j++;
        }
    }
    return 0;
}