#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// int sizeT = 211;
vector<ll>ans = {};
ll x;
bool code = false;
int maximum = 0;

void rec(ll x2, vector<ll>a, int min, int max) {
    if (x2 >= x) {
        if (x2 == x && a.size() <= 200) {
            // cout << x2 << endl;
            cout << a.size() << endl;
            for (auto &x : a)
                cout << x << " ";
            cout << endl;
            /*if (a.size() > maximum) {
                maximum = a.size();
            }*/
            code = true;
        }
        return;
    }
    if (code == false) {
        a.push_back(max + 1);
        rec(x2 * 2, a, min, max + 1);
    } if (code == false) {
        a[a.size() - 1] = min - 1;
        rec(x2 + 1, a, min - 1, max);
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x;
        //x = i;
        vector<ll>a = {0};
        int min = 0;
        int max = 0;
        code = false;
        rec(1, a, min, max);
    }
    //cout << maximum << endl;
    return 0;
}