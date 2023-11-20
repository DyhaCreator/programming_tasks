#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, l;
int ans = 0;

struct skier{
    float time, kilo;
    skier() {}
    skier(int time, int kilo) {
        this->time = time;
        this->kilo = kilo;
    }
};

void sort(vector<skier>&a) {
    for (int i = 0; i < a.size(); i++) {
        a[i].kilo += 1.0/a[i].time * (a.size() - i);
    }
    float min = l + 10;
    do {
        min = l + 10;
        for (int i = 0; i < a.size(); i++) {
            a[i].kilo += 1.0/a[i].time;
        }
        for (int i = 0; i < a.size(); i++) {
            if (min > a[i].kilo) {
                min = a[i].kilo;
            }
        }
        for (auto x : a)
            cout << x.time << " " << x.kilo << endl;
        cout << "---" << endl;
    } while (min < l);
    for (int j = 0; j < a.size(); j++) {
        for (int k = 1; k < a.size(); k++) {
            if (a[k].kilo > a[k - 1].kilo) {
                auto buffer = a[k];
                a[k] = a[k - 1];
                a[k - 1] = buffer;
                ans++;
            }
        }
    }
}

int main() {
    cin >> n >> l;
    vector<skier>a = vector<skier>(n);
    for (auto &x : a) {
        cin >> x.time;
        x.kilo = 0;
    }
    sort(a);
    cout << ans << endl;
    return 0;
}