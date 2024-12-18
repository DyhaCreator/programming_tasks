#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>x = vector<int>(n);
    for (auto &a : x)
        cin >> a;
    int s;
    cin >> s;
    vector<int>a = vector<int>(s + 1, 0);
    vector<int>l = vector<int>(s + 1, 0);
    for (int i = 1; i <= s; i++) {
        l[i] = i;
        for (int j = 0; j < n; j++) {
            if (i - x[j] >= 0 && l[i - x[j]] < l[i] - 1) {
                a[i] = x[j];
                l[i] = l[i - x[j]] + 1;
            }
        }
        /*for (auto y : a)
            cout << y << " ";
        cout << endl;
        for (auto y : l)
            cout << y << " ";
        cout << endl << endl;*/
    }
    vector<int>aaa = vector<int>();
    int i = s, ans = 0;
    while (a[i] > 0) {
        aaa.push_back(a[i]);
        ans += a[i];
        i -= a[i];
    }
    if (ans != s) {
        cout << "No solution" << endl;
    } else {
        reverse(aaa.begin(), aaa.end());
        for (auto y : aaa)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}