#include <iostream>

int main()
{
    unsigned long long a, k, b, m, x, l = 0, r, n;
    std::cin >> a >> k >> b >> m >> x;
    r = x;
    while(r - l > 1){
        n = (l + r) / 2;
        if(a * (n - n / k) + b * (n - n / m) >= x){
            r = n;
        }
        else {
            l = n;
        }
    }
    std::cout << r << std::endl;
}