#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void f(int a, int xx) {
    vector<vector<int>> v(20, vector<int>(13));
    v[0][0] = a;
    //cout << a << " ";
    for (int i = 1; i < 13; i++) {
        v[0][i] = v[0][i - 1] + 1;
        //cout << v[0][i] << " ";
    }
    //cout << endl;
    for (int y = 1; y < 20; y++) {
        for (int x = 0; x < 13; x++) {
            v[y][x] = (v[y - 1][x] % xx) * (v[y - 1][x] % xx);
            //cout << v[y][x] << " ";
        }
        //cout << endl;
    }
    if (v[1][4] == 3364) {
        int count = 0;
        for (int i = 1; i < 20; i++) {
            if (v[i][4] != 1) {
                count++;
            }
        }
        if (count == 1) {
            cout << a << " " << xx << " ";
            for (int i = 0; i < 20; i++) {
                cout << v[i][4] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    for (int a = 1; a < 100; a++) {
        for (int x = 1; x < 100; x++) {
            f(a, x);
        }
    }
    return 0;
}