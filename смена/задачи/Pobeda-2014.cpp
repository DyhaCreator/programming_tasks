#include <cstdio>
#include <algorithm>
#include <cmath>

int main(){
    long long a1, a2, a3, a4;
    scanf("%lld %lld %lld %lld", &a1, &a2, &a3, &a4);
    printf("%lld", (long long)std::sqrt((long double)std::min(a1,a2) + (long double)std::min(a3,a4)));
    return 0;
}