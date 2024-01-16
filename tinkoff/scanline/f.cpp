#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct qw{
    int time, deadline;
    qw() {}
    qw(int time, int deadline) {
        this->time = time;
        this->deadline = deadline;
    }
};

bool comp(qw &a, qw &b) {
    if (a.time == b.time) {
        return a.deadline < b.deadline;
    }
    return a.time < b.time;
}

int main() {
    int n;
    cin >> n;
    vector<qw>a = vector<qw>();
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        a.push_back(qw(t, d));
    }
    sort(a.begin(), a.end(), comp);
    ll time = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        time += a[i].time;
        ans += a[i].deadline - time;
    }
    cout << ans << endl;
    return 0;
}