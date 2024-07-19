#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int k;
    cin >> k;
    vector<int> b(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        b[x - 1]++;
    }

    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}