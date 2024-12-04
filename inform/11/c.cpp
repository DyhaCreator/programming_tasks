#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

string f(string a) {
    setlocale(LC_ALL, "ru");
    int n = a.size();
    n -= 2;
    int mn = n;
    string maxb = "";
    int max_sum = 0;
    for (int i = 0; i < 100; i++) {
        string b = "";
        vector<int> used(n);
        for (int j = 0; j < n; j++) {
            int rindex = rand() % n;
            while (used[rindex] == 1)
                rindex = rand() % n;
            used[rindex] = 1;
            b += {a[rindex + 1]};
        }
        cout << b << endl;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (b[j] != a[j + 1]) sum++;
        }
        if (sum >= max_sum) {
            max_sum = sum;
            maxb = b;
        }
    }
    cout << a[0] << maxb << a[n + 1] << endl;
    return a[0] + maxb + a[n + 1];
}

int main() {
    setlocale(LC_ALL, "ru");
    string s;
    while (getline(cin, s)) {
        vector<string> a = {};
        int index = 0;
        while (index < s.size()) {
            string b = "";
            while (index < s.size() && s[index] != ' ') {
                b.push_back(s[index]);
                index++;
            }
            a.push_back(b);
            index++;
        }
        for (auto &x : a) {
            x = f(x);
        }
        for (auto &x : a)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}