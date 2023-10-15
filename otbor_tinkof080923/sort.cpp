#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int>arr = std::vector<int>();
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        arr.push_back(a);
    }
    std::sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }

    return 0;
}