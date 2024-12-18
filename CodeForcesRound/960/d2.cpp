#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int>a = vector<int>(n);
        vector<int>b = vector<int>(n);
        vector<int>c = vector<int>(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        for (auto &x : c)
            cin >> x;
        int max = 0;
        //int maxX, maxY, maxZ;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                for (int z = 0; z < n; z++) {
                    if (!((x == y && y == z) || (x == y) || (x == z) || (y == z))) {
                        max = std::max(a[x] + b[y] + c[z], max);
                        //maxX = x;
                        //maxY = y;
                        //maxZ = z;
                    }
                }
            }
        }
        cout << max << endl;
        //cout << maxX << " " << maxY << " " << maxZ << endl;
    }
    return 0;
}