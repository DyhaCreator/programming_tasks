#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nut, ans = 0;

bool in(int a, int b, vector<int>c, vector<int>d) {
    for (int i = 0; i < c.size(); i++) {
        if (a == c[i] && b == d[i]) {
            return true;
        }
    }
    return false;
}

bool f(vector<int>posx, vector<int>posy, int x, int y) {
    for (int i = 0; i < posx.size() - 1; i++) {
        if (abs(x - posx[i]) == abs(y - posy[i])) {
            return false;
        }
    }
    return true;
}

void rec(int n, vector<int>posx, vector<int>posy, vector<int>used) {
    /*for (auto x : used)
        cout << x << " ";
    cout << endl;
    if (n == 0) {cout << "--" << endl;
    for (int y = 0; y < nut; y++) {
        for (int x = 0; x < nut; x++) {
            if (in(x, y, posx, posy)) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }}*/
    if (n == 0) {
        ans++;
        return;
    }
    posx.push_back(0);
    posy.push_back(0);
    for (int y = 0; y < nut; y++) {
        for (int x = posx[posx.size() - 2] + 1; x < nut; x++) {
            if (used[y] == 0 && f(posx, posy, x, y)) {
                posx[posx.size() - 1] = x;
                posy[posy.size() - 1] = y;
                used[y] = y + 1;
                rec(n - 1, posx, posy, used);
                used[y] = 0;
            }
        }
    }
}

int main() {
    cin >> nut;
    clock_t tStart = clock();
    vector<int>posx = vector<int>();
    vector<int>posy = vector<int>();
    vector<int>used = vector<int>(nut, 0);
    posx.push_back(0);
    posy.push_back(0);
    for (int y = 0; y < nut; y++) {
        int x = 0;
        posx[posx.size() - 1] = x;
        posy[posy.size() - 1] = y;
        used[y] = y + 1;
        rec(nut - 1, posx, posy, used);
        used[y] = 0;
    }
    cout << ans << endl;

    printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}