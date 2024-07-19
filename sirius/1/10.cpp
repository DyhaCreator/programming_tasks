#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> st1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st1.insert(x);
    }
    int m;
    cin >> m;
    set<int> st2;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        st2.insert(x);
    }
    cout << ((st1 == st2)?"YES\n":"NO\n");
    return 0;
}