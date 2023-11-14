#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nut, ans = 0;

bool in(int a, vector<int>b) {
    for (int i = 0; i < nut + 1; i++) {
        if (a == b[i]) {
            return true;
        }
    }
    return false;
}

bool f(vector<int>pos, int a) {
    int s = pos.size();
    for (int i = 0; i < s - 1; i++) {
        int x1 = (pos[i] - 1) % nut;
        int y1 = (pos[i] - 1) / nut;
        int x2 = (a - 1) % nut;
        int y2 = (a - 1) / nut;
        if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
            return false;
        }
    }
    return true;
}

void rec(int n, vector<int>pos) {
    if (n == 0) {
    cout << "--" << endl;
    for (int i = 0; i < nut; i++) {
        for (int j = 0; j < nut; j++) {
            //cout << (i * nut) + j + 1 << " " << in((i * nut) + j + 1, pos) << endl;
            if (in((i * nut) + j + 1, pos)) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }}
    if (n == 0) {
        ans++;
        return;
    }
    pos.push_back(-1);
    for (int i = pos[pos.size() - 2] + 1; i <= nut * nut; i++) {
        if (f(pos, i)) {
            pos[pos.size() - 1] = i;
            rec(n - 1, pos);
        }
    }
}

int main() {
    cin >> nut;
    if (nut == 1) {
        cout << 1 << endl;
        return 0;
    }
    clock_t tStart = clock();
    vector<int>pos = vector<int>();
    pos.push_back(-1);
    for (int i = 1; i < nut * nut; i++) {
        pos[pos.size() - 1] = i;
        rec(nut - 1, pos);
    }
    cout << ans << endl;
    printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}