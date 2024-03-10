#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll pow(ll a, ll b) {
    ll ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}

int main() {
    // cout << pow(6, 8) << endl;
    for (int a = 0; a < 100000000; a++) {
        int ans = 0;
        vector<vector<ll>> table(7, vector<ll>(5));
        for (int y = 0; y < 7; y++) {
            for (int x = 0; x < 5; x++) {
                ll A = a % pow(x + 2, y + 2);
                ll B = a / pow(x + 2, y + 2);
                if (A == 0) table[y][x] = B;
                else table[y][x] = A;
                //cout << table[y][x] << " ";
                if (table[y][x] == a) ans++;
            }
            //cout << endl;
        }
        //cout << ans << endl;
        // cout << endl;

        if (ans == 5) {
            cout << a << endl;
            /*for (int y = 0; y < 7; y++) {
                for (int x = 0; x < 5; x++) {
                    cout << table[y][x] << " ";
                }
                cout << endl;
            }*/
            // break;
        }
    }
    return 0;
}