#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll>vec(n + 1);
    ll ans = 0;
    for (int i = 1; i < n + 1; i++) {
        int x;
        cin >> x;
        vec[i] = vec[i - 1] ^ x;
    }
    cout << vec.back() << endl;
    
    return 0;
}
/*

7
5 7 4 8 5 8 7

*/