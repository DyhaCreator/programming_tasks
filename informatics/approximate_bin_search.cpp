#include <iostream>

int main() {
    int a[100001], b[100001];
    int N, K;
    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < K; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < K; i++) {
        int l = 0;
        int r = N;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (a[m] >= b[i]) {
                r = m;
            } else {
                l = m;
            }
        }
        if (abs(a[l] - b[i]) <= abs(a[r] - b[i])) {
            std::cout << a[l] << std::endl;
        } else {
            std::cout << a[r] << std::endl;
        }
    }
}