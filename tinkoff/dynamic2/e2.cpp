#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>m = vector<int>();
    m.push_back(0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        m.push_back(x);
    }
    int w;
    cin >> w;
    vector<int>a = vector<int>(w + 1);
    vector<int>l = vector<int>(w + 1, 1000000000);
    l[0] = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - m[j] >= 0) {
                if (l[i - m[j]] < l[i - m[a[i]]]) {
                    a[i] = j;
                    l[i] = l[i - m[j]] + 1;
                }
            }
        }
    }
    int i = w;
    vector<int>ans = vector<int>();
    while (l[i] != 0 && l[i] < 1000000000) {
        ans.push_back(m[a[i]]);
        i -= m[a[i]];
    }
    if (l[i] == 0) {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}