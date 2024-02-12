#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    ll ans = n;
    for (int k = 1; k < n / str.size(); k++) {
        ans *= n - (str.size() * k);
    }
    cout << ans << endl;
    return 0;
}