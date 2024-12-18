#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int>a = std::vector<int>();
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        a.push_back(c);
    }
    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        int m = a[0];
        for (int i = 1; i < n; i++) {
            if (abs(m - x) > abs(a[i] - x)) {
                m = a[i];
            } else if (abs(m - x) == abs(a[i] - x) && a[i] < m) {
                m = a[i];
            }
        }
        std::cout << m << std::endl;
    }
    return 0;
}