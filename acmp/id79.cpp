#include <iostream>
#define ll long long
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans = (ans * a) % 10;
    }
    cout << ans << endl;
    return 0;
}