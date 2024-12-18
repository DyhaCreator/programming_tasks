#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string s, f;
        cin >> s >> f;
        int ans = 0;
        int sSum = 0;
        int fSum = 0;
        int correct = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                sSum++;
            }
            if (f[j] == '1') {
                fSum++;
            }
        }
        ans += abs(fSum - sSum);
        //cout <<"ans - "<< ans << endl;
        if (fSum - sSum > 0) {
            int a = fSum - sSum;
            for (int j = 0; j < n; j++) {
                if (s[j] == '1' && f[j] == '1') {
                    correct++;
                } else if (s[j] == '0' && f[j] == '1' && a > 0) {
                    correct++;
                    a--;
                }
            }
        } else {
            int a = fSum - sSum;
            for (int j = 0; j < n; j++) {
                if (s[j] == '1' && f[j] == '1') {
                    correct++;
                } else if (s[j] == '1' && f[j] == '0' && a < 0) {
                    //correct++;
                    a++;
                }
            }
        }
        //cout << correct << endl;
        ans += fSum - correct;
        cout << ans << endl;
    }
    return 0;
}