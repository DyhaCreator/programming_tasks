#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void sort(vector<int>&a) {
    for (int i = 0; i < a.size(); i++) {
        int index = i;
        while (index > 0 && a[index] < a[index - 1]) {
            int buffer = a[index];
            a[index] = a[index - 1];
            a[index - 1] = buffer;
            index--;
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