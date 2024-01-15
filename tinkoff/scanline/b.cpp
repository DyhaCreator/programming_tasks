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
    } else {
        return a.start < b.start;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<line>lines(n);
    for (auto &[x, y] : lines)
        cin >> x >> y;
    vector<int>points(m);
    for (auto &x : points)
        cin >> x;
    //vector<int>points = enterPoints;
    sort(lines.begin(), lines.end(), comp);

    lines.push_back(line(1000000000, 1000000007));
    int indexStart = 0;
    int indexEnd = 0;
    int h = 0;
    int last = 0;
    
    vector<int>ans(m);

    while (indexEnd < n) {
        if (lines[indexStart].start < lines[indexEnd].end) {
            for (int i = 0; i < m; i++) {
                if (points[i] >= last && points[i] <= lines[indexStart].start) {
                    ans[i] = h;
                }
            }
            last = lines[indexStart].start;
            indexStart++;
            h++;
        } else {
            for (int i = 0; i < m; i++) {
                if (points[i] >= last && points[i] <= lines[indexEnd].end) {
                    ans[i] = h;
                }
            }
            last = lines[indexEnd].end;
            indexEnd++;
            h--;
        }
    }
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
/*

5 1
1 4
6 10
3 7
2 5
3 8
3

3 2
0 5
-3 2
7 10
1 6

1 3
-10 10
-100 100 0


*/