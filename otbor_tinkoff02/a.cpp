#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2 {
    int x = 0, y = 0;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int2>v = vector<int2>(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = int2(x, y);
    }
    
    return 0;
}