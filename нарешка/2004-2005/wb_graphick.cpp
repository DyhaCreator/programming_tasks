#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<int>pic1 = std::vector<int>();
    std::vector<int>pic2 = std::vector<int>();
    int m, h;
    std::cin >> m >> h;
    for(int i = 0; i < h; i++){
        std::string a;
        std::cin >> a;
        for(int j = 0; j < a.size(); j++){
            int b = a[j] - '0';
            pic1.push_back(b);
        }
    }
    for(int i = 0; i < h; i++){
        std::string a;
        std::cin >> a;
        for(int j = 0; j < a.size(); j++){
            int b = a[j] - '0';
            pic2.push_back(b);
        }
    }
    int a, b, c, d;
    std::string s;
    std::cin >> s;
    a = s[0] - '0';
    b = s[1] - '0';
    c = s[2] - '0';
    d = s[3] - '0';
    for(int i = 0; i < pic1.size(); i++){
        if(pic1[i] == 0 && pic2[i] == 0)std::cout << a;
        else if(pic1[i] == 0 && pic2[i] == 1)std::cout << b;
        else if(pic1[i] == 1 && pic2[i] == 0)std::cout << c;
        else if(pic1[i] == 1 && pic2[i] == 1)std::cout << d;
        if(i % m == m - 1)std::cout << std::endl;
    }
    return 0;
}

/*

5 3
01000
11110
01000
10110
00010
10110
0110

*/