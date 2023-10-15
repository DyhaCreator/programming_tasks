#include <iostream>
#include <vector>

int main(){
    std::vector<int>a = std::vector<int>();
    std::vector<int>b = std::vector<int>();
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        int c;
        std::cin >> c;
        a.push_back(c);
    }
    for(int i = 0; i < n; i++){
        int c;
        std::cin >> c;
        b.push_back(c);
    }
    int key;
    key = b[0];
    b.erase(b.begin());
    a.erase(a.begin());
    int new_index_key = b.size();
    for(int j = 0; j < a.size(); j++){
        if(a[j] == key){
            new_index_key = j;
            break;
        }
    }
    b.emplace(b.begin() + new_index_key, key);

    for(int i = 0; i < a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < b.size(); i++){
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*

4 5
4 1 2 4 4
4 3 2 1

*/