#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        int mina = INF;
        for (int j = 0; j < n; j++) {
            if (i != j && abs(a[i] - mina) > abs(a[i] - a[j]))
                mina = a[j];
        }
        cout << mina << " ";
    }
    cout << endl;
    return 0;
}