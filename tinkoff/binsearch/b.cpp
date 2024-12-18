#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int>a = std::vector<int>(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        int l = 0;
        int r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] < x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l > 0 && a[l] != x && abs(a[l - 1] - x) <= abs(a[l] - x)) {
            std::cout << a[l - 1] << std::endl;
        } else {
            std::cout << a[l] << std::endl;
        }
    }

    return 0;
}