#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        cout << a[x] << " ";
    }
    cout << endl;
    return 0;
}