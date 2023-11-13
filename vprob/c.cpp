#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int ans = 0;
int n;
vector<int>v;
vector<int>u;
vector<int>w;

void rec(int start, int th, vector<int>st, int xr) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == th && xr ^ w[i] != 0 && st[i] == 0) {
            st[i] = 1;
            rec(start, u[i], st, xr ^ w[i]);
            ans++;
            st[i] = 0;
            //cout << v[i] << " ";
        }
    }
    //cout << endl;
}

int main() {
    cin >> n;
    v = vector<int>(n - 1);
    u = vector<int>(n - 1);
    w = vector<int>(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i] >> u[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        ans = 0;
        rec(i, i, vector<int>(n), 0);
        cout << ans << endl;
    }
    return 0;
}
/*

5
1 2 1
2 3 2
3 4 3
4 5 0

*/