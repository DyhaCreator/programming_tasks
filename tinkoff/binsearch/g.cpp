#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int>a = std::vector<int>();
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    int l = 0;
    int r = 20000000;
    while (l < r) {
        int m = (l + r) / 2;
        if (m == 0) {
            std::cout << 0 << std::endl;
            return 0;
        }
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += a[i] / m;
        }
        if (k <= x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    std::cout << l - 1 << std::endl;
    return 0;
}

/*

4 11
802
743
457
539

*/