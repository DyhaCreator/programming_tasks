#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a) 
        cin >> x;
    vector<int>b = vector<int>();
    int min = 1e9 + 10;
    for (int i = 0; i < n; i++) {
        min = std::min(a[i], min);
    }
    cout << min << " ";
    int k = 2;
    deque<int>d;
    for (int j = 0; j < n; j++) {
        while (!d.empty() && a[d.back()] <= a[j]) {
            d.pop_back();
        }
        d.push_back(j);
        if (d.front() <= j - k) {
            d.pop_front();
        }
        if (j >= k - 1) {
            //cout << a[d.front()] << endl;
            b.push_back(a[d.front()]);
        }
    }
    sort(b.begin(), b.end());
    for (auto x : b)
        cout << x << " ";
    cout << endl;
    return 0;
}
/*

7
1 5 4 2 3 7 6

*/