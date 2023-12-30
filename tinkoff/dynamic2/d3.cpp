#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < 5000LL * 5000LL * 50LL; i++) {
        if (i % 2 == 0) {
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}