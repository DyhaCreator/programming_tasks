#include <iostream>
#include <vector>
#include <set>

int main(){
    std::vector<int>v = std::vector<int>();
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    std::cout << n << " ";

    for(int i = 2; i <= n; i++){
        long col = 0;
        for(int j = 0; j <= n - i; j++){
            std::set<int>st;
            for(int k = j; k < j + i; k++){
                st.insert(v[k]);
            }
            col += st.size();
        }
        printf("%d ", col);
    }
    std::cout << std::endl;
    return 0;
}