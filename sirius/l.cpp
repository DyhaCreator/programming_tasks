#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int my_sort(vector<int> &a) {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        int count = 0;
        for (int j = 1; j < a.size(); j++) {
            if (a[j] < a[j - 1]) {
                count++;
                ans++;
                int buffer = a[j];
                a[j] = a[j - 1];
                a[j - 1] = buffer;
            }
        }
        if (count == 0) {
            break;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << my_sort(a) << endl;
    return 0;
}