#include <iostream>
#define ll long long
using namespace std;

int x, y, w, s;
ll min_sum = 1e18 + 10;

void rec(int myx, int myy, ll sum) {
    if (myx == x && myy == y) {
        min_sum = min(sum, min_sum);
        //cout << sum << endl;
        return;
    } else if (myx != x && myy == y) {
        sum += (x - myx) * w;
        min_sum = min(sum, min_sum);
        return;
    } else if (myx == x && myy != y) {
        sum += (y - myy) * w;
        min_sum = min(sum, min_sum);
        return;
    }
    rec(myx + 1, myy, sum + w);
    rec(myx, myy + 1, sum + w);
    rec(myx + 1, myy + 1, sum + s);
}

int main() {
    cin >> x >> y >> w >> s;
    rec(0, 0, 0);
    cout << min_sum << endl;
    return 0;
}