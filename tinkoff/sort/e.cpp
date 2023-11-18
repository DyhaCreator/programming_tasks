#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void sort(vector<int>&a) {
    int count[30000] = {0};
    for (auto &x : a) {
        count[x + 15000]++;
        x = 0;
    }
    int index = 0;
    for (int i = 0; i < 30000; i++) {
        while (count[i] > 0) {
            count[i]--;
            a[index] = i - 15000;
            index++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    sort(a);
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}