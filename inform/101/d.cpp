#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int t, k;
    cin >> t >> k;
    for (int i = 0; i < k; i++) {
        if (i + t == 8 || i + t == 13 || i + t == 18) {
            k++;
        }
    }
    cout << t + k << endl;
    return 0;
}