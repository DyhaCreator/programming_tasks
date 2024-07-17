#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    char ch;
    vector<int> nums(10);
    string str;
    getline(cin, str);
    // cout << str << endl;
    for (auto &x : str)
        if (x <= 57 && x >= 48) nums[x - 48]++;
    /*for (auto &x : nums)
        cout << x << " ";
    cout << endl;*/
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < nums[i]; j++) {
            cout << i;
        }
    }
    cout << endl;
    return 0;
}