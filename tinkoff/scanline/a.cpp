#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct line{
    int start, end;
    line() {}
    line(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool comp(const line &a, const line &b) {
    if (a.start == b.start) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;
    vector<line>lines = vector<line>(n);
    for (auto &[a, b] : lines) {
        cin >> a >> b;
    }

    sort(lines.begin(), lines.end(), comp);
    
    int newStart = lines[0].start;
    int newEnd = lines[0].end;
    vector<line>ans = vector<line>();
    for (int i = 1; i < n; i++) {
        if (lines[i].start <= newEnd) {
            newEnd = lines[i].end;
        } else {
            ans.push_back(line(newStart, newEnd));
            newStart = lines[i].start;
            newEnd = lines[i].end;
        }
    }
    ans.push_back(line(newStart, newEnd));
    cout << ans.size() << endl;
    for (auto &[a, b] : ans) {
        cout << a << " " << b << endl;
    }
    return 0;
}