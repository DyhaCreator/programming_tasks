#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool f(vector<int>pos) {
    int s = pos.size();
    for (int i = 0; i < s - 1; i++) {
        int x1 = pos[s - 1];
        int y1 = s - 1;
        int x2 = pos[i];
        int y2 = i;
        if (abs(x1 - x2) == abs(y1 - y2)) {
            return false;
        }
    }
    return true;
}

int nut, ans = 0;

void rec(int y, vector<int>posx, vector<int>a) {
    if (y == nut) {
        ans++;
        return;
    }
    posx.push_back(-1);
    for (int x = 0; x < nut; x++) {
        posx[posx.size() - 1] = x;
        if (a[x] == 0 && f(posx)) {
            a[x] = 1;
            rec(y + 1, posx, a);
            a[x] = 0;
        }
    }
}

int main() {
    cin >> nut;
    rec(0, vector<int>(), vector<int>(nut));
    cout << ans << endl;
    return 0;
}