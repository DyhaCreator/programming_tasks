#include <iostream>
#define ll long long
using namespace std;

int main() {
    int k, m, t, x;
    cin >> k >> m >> t >> x;
    clock_t tStart = clock();
    int day = 1;
    while (x < m) {
        x += k;
        if (day % 7 == 0) {
            x -= t;
        }
        day++;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    cout << day - 1 << endl;
    return 0;
}