#include <iostream>
using namespace std;
int main() {
    char ch;
    int ans = 0;
    const char* a = "6255456376";
    while (cin>>ch)
        ans += a[ch - 48] - 48;
    printf("%d\n", ans);
    return 0;
}