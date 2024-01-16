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

bool comp(line &a, line &b) {
    if (a.l == b.l) {
        return a.r > b.r;
    }
    return a.l < b.l;
}

int main() {
    int n;
    cin >> n;
    vector<line>a = vector<line>(n);
    int index = 0;
    for (auto &[l, r, i] : a) {
        cin >> l >> r;
        i = index++;
    }
    sort(a.begin(), a.end(), comp);
    /*for (auto &[l, r, i] : a) {
        cout << l << " " << r << endl;
    }*/
    vector<int>ans(n, 0);

    index = 1;
    int last = 0;
    while (index < n) {
        if (a[index].l >= a[last].l && a[index].r <= a[last].r && ans[a[last].index] == 0) {
            ans[a[index].index] = a[last].index + 1;
        } else {
            last = index;
        }
        index++;
    }
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}