#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> sort(vector<int>a) {
    if (a.size() == 1) {
        return a;
    }
    int middle = (a.size() / 2);
    vector<int>l(a.begin(), a.begin() + middle);
    vector<int>r(a.begin() + middle, a.end());
    l = sort(l);
    r = sort(r);
    int l_it = 0;
    int r_it = 0;
    a = vector<int>();
    while (l_it < l.size()) {
        while (l[l_it] >= r[r_it] && r_it < r.size()) {
            a.push_back(r[r_it]);
            r_it++;
        }
        a.push_back(l[l_it]);
        l_it++;
    }
    while (r_it < r.size()) {
        a.push_back(r[r_it]);
        r_it++;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    a = sort(a);
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}