#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a) 
        cin >> x;
    for (int k = 1; k <= n; k++) {
        vector<int>b = vector<int>();
        deque<int>d;
        int ans = 1e9 + 10;
        for (int j = 0; j < n; j++) {
            while (!d.empty() && a[d.back()] <= a[j]) {
                d.pop_back();
            }
            d.push_back(j);
            if (d.front() <= j - k) {
                d.pop_front();
            }
            if (j >= k - 1) {
                b.push_back(a[d.front()]);
                if (a[d.front()] < ans) {
                    ans = a[d.front()];
                }
            }
        }
        //sort(b.begin(), b.end());
        for (auto x : b)
            cout << x << " ";
        cout << endl;
        //cout << ans << " ";
    }
    cout << endl;
    return 0;
}