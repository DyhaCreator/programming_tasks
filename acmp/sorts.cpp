#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void solveA() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int buffer = a[j];
                a[j] = a[j + 1];
                a[j + 1] = buffer;
                ans++;
            }
        }
    }
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    cout << ans << endl;
}

void solveB() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = n - 1; i >= 0; i--) {
        int index = 0;
        for (int j = 0; j <= i; j++) {
            if (a[j] > a[index]) {
                index = j;
            }
        }
        cout << index << " ";
        int buffer = a[index];
        a[index] = a[i];
        a[i] = buffer;
    }
    cout << endl;
}

void solveC() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = n / 2; i < n; i++) {
        ans += a[i];
    }
    for (int i = 0; i < n / 2; i++) {
        ans -= a[i];
    }
    cout << ans << endl;
}

struct Time{
    int h, m, s;
    Time() {}
    Time(int h, int m, int s) {
        this->h = h;
        this->m = m;
        this->s = s;
    }
};


bool compTime(Time &a, Time &b) {
    if (a.h == b.h) {
        if (a.m == b.m) {
            return a.s < b.s;
        }
        return a.m < b.m;
    }
    return a.h < b.h;
}

void solveD() {
    int n;
    cin >> n;
    vector<Time> a(n);
    for (auto &x : a)
        cin >> x.h >> x.m >> x.s;
    sort(a.begin(), a.end(), compTime);
    for (auto &x : a)
        cout << x.h << " " << x.m << " " << x.s << endl;
}

void solveE() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < ((n + 2) / 2); i++) {
        ans += (a[i] + 2) / 2;
        //cout << (a[i] + 2) / 2 << " ";
    }
    //cout << endl;
    cout << ans << endl;
}

void solveF() {
    int n;
    cin >> n;
    vector<float> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    float money = 0;
    cin >> money;
    for (int i = 0; i < n; i++) {
        if (a[i] >= money) {
            money = (a[i] + money) / 2;
        }
        //cout << money << endl;
    }
    printf("%.6f\n", money);
}

int main() {
    solveF();
    return 0;
}