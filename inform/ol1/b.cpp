#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        count[s[0] - 'A']++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}