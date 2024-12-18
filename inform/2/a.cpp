#include <iostream>
#include <vector>
using namespace std;
using ll= long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index = 0;
    while (n > 0) {
        n -= month[index];
        index++;
    }
    cout << n + month[index - 1] << " " << index << endl;

    return 0;
}