#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct line{
    int l, r, index;
    int cld = -1;
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
    vector<line>lines(n);
    int index = 0;
    for (auto &[l, r, i, a] : lines) {
        cin >> l >> r;
        i = index++;
    }
    sort(lines.begin(), lines.end(), comp);
    for (auto &x : lines) {
        cout << x.l << " " << x.r << endl;
    }
    vector<int>ans(n);
    index = 1;
    int last = 0;
    while (index < n) {
        if (lines[index].l >= lines[last].l && lines[index].r <= lines[last].r && lines[last].cld == -1) {
            lines[last].cld = index;
            ans[lines[index].index] = lines[last].index + 1;
            index++;
        } else if (last < index - 1) {
            last++;
        } else {
            index++;
        }
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}