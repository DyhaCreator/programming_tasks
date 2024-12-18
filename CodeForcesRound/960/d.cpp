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
        int ans = 0;
        vector<int>a = vector<int>(n);
        vector<int>b = vector<int>(n);
        vector<int>c = vector<int>(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        for (auto &x : c)
            cin >> x;

        int maxA = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] > a[maxA]) {
                maxA = j;
            }
        }
        int maxB = 0;
        for (int j = 0; j < n; j++) {
            if (b[j] > b[maxB]) {
                maxB = j;
            }
        }
        int maxC = 0;
        for (int j = 0; j < n; j++) {
            if (c[j] > c[maxC]) {
                maxC = j;
            }
        }
        int maxDay = maxA;
        int GGG = 0;
        if (b[maxB] > a[maxDay]) {
            maxDay = maxB;
            GGG = 1;
            if (c[maxC] > b[maxDay]) {
                maxDay = maxC;
                GGG = 2;
            }
        } else if (c[maxC] > a[maxDay]) {
            maxDay = maxC;
            GGG = 2;
        }
        ans += max(max(a[maxDay], b[maxDay]), c[maxDay]);
        a.erase(a.begin() + maxDay);
        b.erase(b.begin() + maxDay);
        c.erase(c.begin() + maxDay);

        if (GGG == 0) {
            for (auto &x : a)
                x = 0;
        } else if (GGG == 1) {
            for (auto &x : b)
                x = 0;
        } else {
            for (auto &x : c)
                x = 0;
        }

        maxA = 0;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[maxA]) {
                maxA = j;
            }
        }
        maxB = 0;
        for (int j = 0; j < n - 1; j++) {
            if (b[j] > b[maxB]) {
                maxB = j;
            }
        }
        maxC = 0;
        for (int j = 0; j < n - 1; j++) {
            if (c[j] > c[maxC]) {
                maxC = j;
            }
        }
        maxDay = maxA;
        GGG = 0;
        if (b[maxB] > a[maxDay]) {
            maxDay = maxB;
            GGG = 1;
            if (c[maxC] > b[maxDay]) {
                maxDay = maxC;
                GGG = 2;
            }
        } else if (c[maxC] > a[maxDay]) {
            maxDay = maxC;
            GGG = 2;
        }
        ans += max(max(a[maxDay], b[maxDay]), c[maxDay]);
        a.erase(a.begin() + maxDay);
        b.erase(b.begin() + maxDay);
        c.erase(c.begin() + maxDay);
        if (GGG == 0) {
            for (auto &x : a)
                x = 0;
        } else if (GGG == 1) {
            for (auto &x : b)
                x = 0;
        } else {
            for (auto &x : c)
                x = 0;
        }

        maxA = 0;
        for (int j = 0; j < n - 2; j++) {
            if (a[j] > a[maxA]) {
                maxA = j;
            }
        }
        maxB = 0;
        for (int j = 0; j < n - 2; j++) {
            if (b[j] > b[maxB]) {
                maxB = j;
            }
        }
        maxC = 0;
        for (int j = 0; j < n - 2; j++) {
            if (c[j] > c[maxC]) {
                maxC = j;
            }
        }
        //cout << maxA << " " << maxB << " " << maxC << endl;
        maxDay = maxA;
        GGG = 0;
        if (b[maxB] > a[maxDay]) {
            maxDay = maxB;
            GGG = 1;
            if (c[maxC] > b[maxDay]) {
                maxDay = maxC;
                GGG = 2;
            }
        } else if (c[maxC] > a[maxDay]) {
            maxDay = maxC;
            GGG = 2;
        }
        ans += max(max(a[maxDay], b[maxDay]), c[maxDay]);
        a.erase(a.begin() + maxDay);
        b.erase(b.begin() + maxDay);
        c.erase(c.begin() + maxDay);
        if (GGG == 0) {
            for (auto &x : a)
                x = 0;
        } else if (GGG == 1) {
            for (auto &x : b)
                x = 0;
        } else {
            for (auto &x : c)
                x = 0;
        }

        cout << ans << endl;
    }
    return 0;
}