#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    vector<ll>pref = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
        //cout << pref[i] << " ";
    }
    //cout << endl;
    ll min = 1e18 + 10;
    for(int i = k; i <= n; i++) {
        ll max = -1;
        for (int j = k; j <= n; j++) {
            if (j - k + 1 > i || j < i - k + 1) {
                //cout << j << endl;
                if (pref[j] - pref[j - k] > max) {
                    max = pref[j] - pref[j - k];
                }
            }
        }
        //cout << "++" << i << endl;
        if (max < min) {
            min = max;
        }
    }
    cout << min << endl;

    return 0;
}
/*

10 2
1 2 4 5 2 4 2 2 1 6

6 2
4 2 2 3 1 3

*/