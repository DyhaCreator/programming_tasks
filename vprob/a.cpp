#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    if (K == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll res = N * (M - 1);
    if (K > M) {
        res += M * (N - 1);
    }
    cout << res << endl;

    return 0;
}