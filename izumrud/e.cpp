#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

void rec(vector<int>prog, int n, bool nis20) {
    if (n == 58 && nis20) {
        //cout << nis20 << endl;
        ans++;
        for (auto x : prog)
            cout << x;
        cout << endl;
        return;
    } else if (n > 58) {
        return;
    }
    prog.push_back(1);
    if (n + 3 == 20) {
        rec(prog, n + 3, true);
    } else {
        rec(prog, n + 3, nis20);
    }
    prog[prog.size() - 1] = 2;
    if (n * 2 == 20) {
        rec(prog, n * 2, true);
    } else {
        rec(prog, n * 2, nis20);
    }
}

int main() {
    for (int i = 1; i <= 20; i++) {
        //cout << i << endl;
        rec(vector<int>(), i, (i == 20));
    }
    cout << ans << endl;
    return 0;
}