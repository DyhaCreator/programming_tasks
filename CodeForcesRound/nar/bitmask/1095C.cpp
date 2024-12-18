#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(50);
    int index = 0;
    int save = n;
    int size = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            a[index]++;
            size++;
        }
        n /= 2;
        index++;
    }
    n = save;
    if (size > k || k > n) {
        cout << "NO" << endl;
        return 0;
    }
    while (size < k) {
        index = 1;
        while (index < 50 && a[index] == 0)
            index++;
        a[index]--;
        a[index - 1] += 2;
        size++;
    }
    cout << "YES" << endl;
    for (int i = 0; i < 50; i++) {
        if (a[i] > 0)
            while (a[i]--) cout << (1 << i) << " ";
    }
    cout << endl;
    return 0;
}