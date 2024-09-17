#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int ans = 1;
    string last;
    cin >> last;
    for (int i = 0; i < n - 1; i++) {
        string th;
        cin >> th;
        if (th[0] == last[1]) {
            ans++;
        }
        last = th;
    }
    cout << ans << endl;
    return 0;
}