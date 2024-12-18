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
    clock_t tStart = clock();
    sort(lines.begin(), lines.end(), comp);

    vector<int>ans(n);

    int max_end = 0;
    int max_end_index = -1;

    for (int i = 0; i < n; i++) {
        if (lines[i].r <= max_end) {
            ans[lines[i].index] = max_end_index + 1;
        } else {
            max_end = lines[i].r;
            max_end_index = lines[i].index;
            ans[lines[i].index] = 0;
        }
    }

    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
    printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}