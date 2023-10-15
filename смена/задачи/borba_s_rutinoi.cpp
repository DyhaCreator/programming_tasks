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
    
    int b[20000];
    for(int i = 0; i < n; i++){
        std::set<int>st;
        for(int j = i; j < n; j++){
            st.insert(v[j]);
            b[j - i] += st.size();
        }
    }
    for(int i = 0; i < n; i++){
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}