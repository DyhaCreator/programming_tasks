#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (auto &x : a)
            cin >> x;
        vector<int2>p = vector<int2>();
        int size = 1;
        int last = a[0];
        for (int j = 1; j < n; j++) {
            if (a[j] == last) {
                size++;
            } else {
                p.push_back(int2(last, size));
                last = a[j];
                size = 1;
            }
        }
        for (int i = 0; i < )
    }
    return 0;
}