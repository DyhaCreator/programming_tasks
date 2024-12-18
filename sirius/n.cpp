#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> last = a;
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                int buffer = a[j];
                a[j] = a[j - 1];
                a[j - 1] = buffer;
            }
        }
        if (last != a) {
            for (auto &x : a)
                cout << x << " ";
            cout << endl;
        }
        last = a;
    }
    return 0;
}