#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
using ll = long long;

int main() {
    string a = "22";
    string b = "33";
    string c = "44";
    int ans = 0;
    for (int x = 2; x <= 16; x++) {
        for (int y = x + 1; y <= 16; y++) {
            for (int z = y + 1; z <= 16; z++) {
                if (all_to_t(a, x) + all_to_t(b, y) == all_to_t(c, z)) {
                    cout << x << " " << y << " " << z << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}