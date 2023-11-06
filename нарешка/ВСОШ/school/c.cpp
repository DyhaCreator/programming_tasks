#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int a2;
    cin >> a2;
    ll r1, g1, t1;
    ll r2, g2, t2;
    ll r3, g3, t3;
    ll r4, g4, t4;
    cin >> r1 >> g1 >> t1;
    cin >> r2 >> g2 >> t2;
    cin >> r3 >> g3 >> t3;
    cin >> r4 >> g4 >> t4;
    ll min_time = 1e18;
    if (a2 == 34) {
            if (t1 <= g1 && t4 <= g4) {
        ll time = r1;
        time += t1;
        ll a = (g4 + r4) - (time - (g4 + r4) * (time / (g4 + r4)));
        //cout << (g4 + r4) - (time - (g4 + r4) * (time / (g4 + r4))) << endl;
        if (a > g4) {
            time += r4 - ((g4 + r4) - a);
        }
        if (a >= t4) {
            time += t4;
            min_time = min(time, min_time);
        } else {
            time += a + r4;
        }
        //cout << time << endl;
    }
    ll time = r2;
    time += t2;
    ll a = (g3 + r3) - (time - (g3 + r3) * (time / (g3 + r3)));
    //cout << (g4 + r4) - (time - (g4 + r4) * (time / (g4 + r4))) << endl;
    if (a > g3) {
        time += r3 - ((g3 + r3) - a);
    }
    if (a >= t3) {
        time += t3;
        min_time = min(time, min_time);
    } else {
        time += a + r3;
    }
    //cout << time << endl;
    cout << min_time << endl;
    } else if (a2 == 23) {
        cout << r2 + t2 << endl;
    } else {
        cout << r1 + t1 << endl;
    }
    return 0;
}

/*

34
80 15 12
120 20 14
60 22 10
90 18 14

*/