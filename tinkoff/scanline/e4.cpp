#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

struct line{
    int start, end;
    line() {}
    line(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool comp(line &a, line &b) {
    if (a.end == b.end) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<line> lines(n);
    for (auto &x : lines)
        cin >> x.start >> x.end;
    sort(lines.begin(), lines.end(), comp);

    vector<int> ls(k, -1);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int indexOfMin = 0;
        for (int j = 0; j < k; j++) {
            if (ls[j] < ls[indexOfMin]) {
                indexOfMin = j;
                if (ls[indexOfMin] <= lines[i].start) {
                    ls[indexOfMin] = lines[i].end;
                    ans++;
                    break;
                }
            }
        }
        /*if (ls[indexOfMin] <= lines[i].start) {
            ans++;
            ls[indexOfMin] = lines[i].end;
        }*/
    }
    cout << ans << endl;
    return 0;
}