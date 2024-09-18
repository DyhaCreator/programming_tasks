#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(vector<int> &a) {
    int b = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (b + i != a[i] && a[i] != -1) return 1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    int ans1 = 0, ans2 = 0;
    vector<int> a = {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        if (x == -1) {
            ans1++;
            ans2 += f(a);
            a = {};
        }
        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;
        cout << ans2 << " " << f(a) << endl;*/
    }
    cout << ans1 << "\n" << ans2 << endl;
    return 0;
}