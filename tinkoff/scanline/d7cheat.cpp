#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct line{
    int start, end;
    int index;
    line() {}
    line(int start, int end, int index) {
        this->start = start;
        this->end = end;
        this->index = index;
    }
};

bool comp(line &a, line &b) {
    if (a.start == b.start) {
        return a.end > b.end;
    }
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;

    vector<line> lines = {};
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lines.push_back(line(a, b, i));
    }

    sort(lines.begin(), lines.end(), comp);
    // for (auto &x : lines)
    //     cout << x.start << " " << x.end << " " << x.index << endl;
    int maxEnd = lines[0].end;
    vector<int> ans(n, -1);
    for (int i = 1; i < n; i++) {
        if (lines[i].end > maxEnd) {
            maxEnd = lines[i].end;
        } else {
            int index = i - 1;
            while (index >= 0 && !(lines[index].end >= lines[i].end)) {
                index--;
            }
            if (index != -1) {
                ans[lines[i].index] = lines[index].index;
            }
        }
    }
    for (auto &x : ans)
        cout << x + 1 << " ";
    cout << endl;
    return 0;
}