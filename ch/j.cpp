#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    vector<int> a(10);
    for (auto &x : a)
        cin >> x;
    int count = 0;
    for (auto &x : a)
        count += x;
    // cout << count << endl;
    vector<int> ans(count);
    int last = 0;
    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < 10; j++) {
            if (j != last && a[j] > 0) {
                ans[i] = j;
                a[j]--;
                last = j;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            cout << "Impossible" << endl;
            // return 0;
        }
    }
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}