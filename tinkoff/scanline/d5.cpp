#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct line{
    int l, r, index;
    line() {}
    line(int l, int r) {
        this->l = l;
        this->r = r;
    }
};

bool comp(const line &a, const line &b) {
    if (a.l == b.l) {
        return a.r > b.r;
    }
    return a.l < b.l;
}

int main() {
    int n;
    cin >> n;
    vector<line>lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i].l >> lines[i].r;
        lines[i].index = i;
    }
    //clock_t tStart = clock();
    sort(lines.begin(), lines.end(), comp);
    vector<int>ans(n);
    for (int i = 1; i < n; i++) {
        int last = i - 1;
        while (last >= 0 && !(lines[i].l >= lines[last].l && lines[i].r <= lines[last].r)) {
            last--;
        }
        if (last >= 0) {
            ans[lines[i].index] = lines[last].index + 1;
        }
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
    //printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}