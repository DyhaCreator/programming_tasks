#include <iostream>
#include <vector>
#include <deque>
#define ll long long
using namespace std;

vector<int>a = vector<int>();

int min_index(int start, int end) {
    int mini = start;
    for (int i = start; i < end; i++) {
        if (a[i] < a[mini]) {
            mini = i;
        }
    }
    return mini;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    deque<int>d;

    vector<int>ans = vector<int>();

    for (int i = 0; i < n; i++) {
        while (!d.empty() && a[d.back()] >= a[i]) {
            d.pop_back();
        }
        d.push_back(i);
        if (d.front() <= i - k) {
            d.pop_front();
        }
        if (i >= k - 1) {
            cout << a[d.front()] << endl;
        }
    }

    return 0;
}
/*

7 3
1 3 2 4 5 3 1

*/