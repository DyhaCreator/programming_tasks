#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nut;

int a[100] = {0};

void gen(int n, int pos, vector<int>nums) {
    if (n == 0) {
        for (int i = 0; i < nut; i++) {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= nut; i++) {
        if (nums[i] == 0) {
            a[pos] = i;
            nums[i] = 1;
            gen(n - 1, pos + 1, nums);
            nums[i] = 0;
        }
    }
    return;
}

int main() {
    cin >> nut;
    gen(nut, 0, vector<int>(nut + 1));
    return 0;
}