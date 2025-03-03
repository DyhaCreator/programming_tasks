#include <iostream>
#include <cmath>

long long NOD(long long n1, long long n2)
{
    long long div;
    if (n1 == n2)  return n1;
    long long d = n1 - n2;
    if (d < 0) {
        d = -d;  
        div = NOD(n1, d);
    } else
        div = NOD(n2, d); 
    return div;
}

long long NOK(long long n1, long long n2) 
{ 
    return n1 * n2 / NOD(n1, n2); 
}

int main(){
    long long a, b, c, t, d;
    std::cin >> a >> b >> c >> t >> d;
    long long A = NOK(a, NOK(b, c));
    //std::cout << A << std::endl;
    
    long long l = ceil((double)(t * (d - 1)) / (double)A);
    long long f = ceil((double)(t * d) / (double)A);
    std::cout << f - l << std::endl;
    return 0;
}

