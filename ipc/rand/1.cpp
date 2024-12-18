#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

inline bool operator<(const int2 &a, const int2 &b) {
    if ((double)a.x / (double)a.y == (double)b.x / (double)b.y) {
        return a.x < b.x;
    }
    return (double)a.x / (double)a.y < (double)b.x / (double)b.y;
}

int nod(int a, int b) {
    if (a == 1 || b == 1) return 1;
    while (b > 0) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    set<int2> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int ss = nod(j + 1, i + 1);
            st.insert({(j + 1) / ss, (i + 1) / ss});
        }
    }
    for (auto &x : st)
        cout << x.x << "/" << x.y << endl;
    return 0;
}