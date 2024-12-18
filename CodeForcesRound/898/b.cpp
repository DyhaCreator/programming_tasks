#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<ll>a = vector<ll>(n);
        ll maxout = 1;
        bool b = false;
        for (auto &x : a) {
            cin >> x;
            if (x == 0 && b == false) {
                b = true;
            } else {
                maxout *= x;
            }
        }
        ll oldmaxout = maxout;
        if (b) {
            cout << maxout << endl;
        } else {
            //cout <<maxout << endl;
            for (auto x : a) {
                //cout << x << " " << (oldmaxout / x) * (x + 1) << endl;
                maxout = std::max(maxout, oldmaxout / x * (x + 1));
            }
            cout << maxout << endl;
        }
    }
    return 0;
}