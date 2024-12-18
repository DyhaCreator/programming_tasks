#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct line{
    ll start, end;
    line() {}
    line(ll start, ll end) {
        this->start = start;
        this->end = end;
    }
};

bool comp(const line &a, const line &b) {
    if (a.start == b.start) {
        return a.end > b.end;
    }
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;
    vector<line>a(n);
    for (auto &[a, b] : a)
        cin >> a >> b;
    sort(a.begin(), a.end(), comp);
    vector<line>b = vector<line>();
    b.push_back(line(a[0].start, a[0].end));
    for (int i = 1; i < n; i++) {
        if (a[i].start <= a[i - 1].end) {
            b[b.size() - 1].end = a[i].end;
        } else {
            b.push_back(a[i]);
        }
    }
    cout << b.size() << endl;
    for (auto &x : b)
        cout << x.start << " " << x.end << endl;
    return 0;
}