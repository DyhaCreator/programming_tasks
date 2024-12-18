#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nut, k;

void rec(int n, vector<int>ans) {
    if (n <= 1) {
        for (int i = 0; i < ans.size() - 1; i++) {
            cout << ans[i] << "*";
        }
        cout << ans[ans.size() - 1] << endl;
        return;
    }
    ans.push_back(0);
    for (int i = ans[ans.size() - 2]; n / i >= 1 && i <= n; i++) {
        if (n % i == 0) {
            ans[ans.size() - 1] = i;
            rec(n / i, ans);
        }
    }
}

int main() {
    cin >> nut >> k;
    vector<int>ans = vector<int>();
    ans.push_back(0);
    for (int i = k; i <= nut; i++) {
        if (nut % i == 0) {
            ans[ans.size() - 1] = i;
            rec(nut / i, ans);
        }
    }
    return 0;
}