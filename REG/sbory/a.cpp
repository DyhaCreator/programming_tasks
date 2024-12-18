#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct ch{
    int w, f, index;
    ch() {}
    ch(int w, int f, int index) {
        this->w = w;
        this->f = f;
        this->index = index;
    }
};

bool comp(ch &a, ch &b) {
    return a.w < b.w;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ch>w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i].w;
        w[i].index = i;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        w[x].f = 1;
    }

    sort(w.begin(), w.end(), comp);

    vector<int>ans(n);

    for (int i = 0; i < k; i++) {
        if (w[i].w )
    }

    return 0;
}