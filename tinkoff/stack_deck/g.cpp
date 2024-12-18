#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

struct strc{
    vector<int>d;
    int size = 0;
    int start = 0;
    strc() {}
    void inc(int x) {
        d.push_back(x);
        size++;
    }
    void prev(int x) {
        d.insert(d.begin() + ((size + start + 1) >> 1), x);
        size++;
    }
    int dec() {
        int x = d[start];
        d[start] = 0;
        start++;
        return x;
    }
};

int main() {
    strc ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        if (a == '+') {
            int x;
            cin >> x;
            ans.inc(x);
        } else if (a == '*') {
            int x;
            cin >> x;
            ans.prev(x);
        } else if (a == '-') {
            cout << ans.dec() << endl;
        }
    }
    return 0;
}