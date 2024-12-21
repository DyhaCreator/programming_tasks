#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int iNF = 1e9 + 7;

ll pw(ll a, ll b) {
    ll ans = 1;
    for (int i = 0; i < b; i++)
        ans *= a;
    return ans;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << pw(a, b) << endl;
    return 0;
}