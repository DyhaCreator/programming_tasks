#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int>a = std::vector<int>(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] < x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (a[l] == x) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}