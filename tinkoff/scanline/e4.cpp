#include <algorithm>
#include <iostream>
#include <set>
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
        return a.start > b.start;
    }
    return a.end < b.end;
}

int main() {
    int n, k;
    cin >> n >> k;
    // k = 1;
    vector<line> lines(n);
    for (auto &x : lines)
        cin >> x.start >> x.end;
    sort(lines.begin(), lines.end(), comp);

    multiset<int> ms;
    for (int i = 0; i < k; i++) {
        ms.insert(0);
    }

    vector<int> v(k);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        /*for ( auto &x : ms)
            cout << x << " ";
        cout << endl;*/
        if (*ms.begin() <= lines[i].start) {
            ms.erase(ms.begin());
            ms.insert(lines[i].end);
            ans++;
        }
        /*for (auto &x : v) {
            if (x <= lines[i].start) {
                ans++;
                x = lines[i].end;
                break;
            }
        }
        for (auto &x : v)
            cout << x << " ";
        cout << endl;*/
    }
    cout << ans << endl;
    return 0;
}