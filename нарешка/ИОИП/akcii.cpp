#include <iostream>
#include <vector>

int main(){
    int n, x;
    std::cin >> n >> x;
    std::vector<int>a = std::vector<int>();
    for(int i = 0; i < n; i++){
        int c;
        std::cin >> c;
        a.push_back(c);
    }
    std::vector<int>b = std::vector<int>();
    for(int i = 0; i < n; i++){
        int c;
        std::cin >> c;
        b.push_back(c);
    }

    int oa = -2, ob = -2, ox = 1000;
    int q;
    for(int i = 0; i < a.size() - 1; i++){
        q = (x / a[i]);
        for(int j = i + 1; j < b.size(); j++){
            int z = x - a[i] * q + b[j] * q;
            if(z >= ox){
                oa = i;
                ob = j;
                ox = z;
            }
        }
    }
    std::cout << ox << std::endl << oa + 1 << " " << ob + 1 << std::endl;
    return 0;
}