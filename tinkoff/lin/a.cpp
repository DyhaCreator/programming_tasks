#include <iostream>
#include <vector>
using namespace std;

int n;

int min_index(vector<int>&a, int l) {
    for(int i = l + 1; i < n; i++) {
        if(a[i] < a[l]) {
            return i;
        }
    }
    return -1;
}

int main() {
    cin >> n;
    vector<int>a = vector<int>();
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++) {
        cout << min_index(a, i) << " ";
    }
    return 0;
}