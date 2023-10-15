#include <iostream>
#include <stack>
#include <deque>
#define ll long long
using namespace std;

int main() {
    int N;
    cin >> N;
    deque<ll>pos;
    ll time = 0;
    for (int i = 0; i < N; i++) {
        ll h, m, n;
        cin >> h >> m >> n;
        if (n < pos.size()) {
            cout << h << " " << m;
        } else {
            m += h * 60;
            pos.push_back(m);
        }
    }
    return 0;
}