#include <iostream>
#include <cmath>

int sq(int a){
    int i = 0;
    while(i * i * i <= a){
        i++;
    }
    return i - 1;
}

int main(){
    int n;
    std::cin >> n;
    int a[n + 1] = {0};
    a[1] = 1;
    for(int i = 1; i < n + 1; i++){
        a[i] = n + 2;
        int k = sq(i);
        for(int j = 1; j <= k; j++){
            //std::cout << a[i] << " " << a[i - int(pow(j, 3))] << std::endl;
            int g = j * j * j;
            if(a[i] > a[i - g] + 1){
                a[i] = a[i - g] + 1;
            }
        }
    }
    std::cout << a[n] << std::endl;
    return 0;
}