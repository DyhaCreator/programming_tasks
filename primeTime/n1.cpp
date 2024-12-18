#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int p, s;
    cin >> p >> s;
    vector<int> a(p);
    for (auto &x : a)
        cin >> x;
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    vector<int> b(p, 0);
    int ans = 0;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < 5; j++) {
            int index;
            cin >> index;
            index--;
            if (b[index] < a[index]) {
                b[index]++;
                ans++;
            }
        }
        /*for (auto &x : b)
            cout << x << " ";
        cout << endl;*/
    }
    cout << ans << endl;
    return 0;
}