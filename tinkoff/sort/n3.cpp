#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int ans = 0;
int n, l;

struct skier{
    float time, kilo;
    skier() {}
    skier(int time, int kilo) {
        this->time = time;
        this->kilo = kilo;
    }
};

bool comp(skier a, skier b) {
    return a.kilo > b.kilo;
}

void sort(vector<skier>&a) {
    vector<skier>b = a;
    for (int j = 0; j < b.size(); j++) {
        b[j].kilo += 1.0/b[j].time * (b.size() - j);
    }
    do {
        for (int j = 0; j < b.size(); j++) {
            b[j].kilo += 1.0/b[j].time;
        }
        int last_ans = ans - 1;
        while (ans - last_ans > 0) {
            last_ans = ans;
            for (int k = 1; k <= b.size(); k++) {
                if (b[k].kilo > b[k - 1].kilo) {
                    auto buffer = b[k];
                    b[k] = b[k - 1];
                    b[k - 1] = buffer;
                    ans++;
                }
            }
        }
    } while (b[b.size() - 2].kilo < l);
}

int main() {
    cin >> n >> l;
    vector<skier>a = vector<skier>(n);
    for (auto &x : a) {
        cin >> x.time;
        x.kilo = 0.0;
    }
    sort(a);
    cout << ans << endl;
    return 0;
}