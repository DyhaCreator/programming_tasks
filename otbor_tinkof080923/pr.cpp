#include <iostream>
#include <vector>
#include <string>

std::vector<int>h = std::vector<int>();
int yearSize;

int per(int n, std::vector<int> d){
    std::cout << n << std::endl;
    for(int i = 0; i < d.size(); i++){
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;
    if(n > yearSize)
        return 0;
    d.push_back(0);
    per(n + 1, d);
    d[n + 1] = 1;
    per(n + 1, d); 
    return 0;
}

int main(){
    std::vector<int>d = std::vector<int>();
    int year, startDay, N;
    std::cin >> year >> startDay;
    if(year % 4 != 0)
        yearSize = 365;
    else
        yearSize = 366;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        int dd, mm, day = 0;
        std::string str;
        std::cin >> str;
        dd = std::stoi(str.substr(0, 2));
        mm = std::stoi(str.substr(3, 2));
        for(int j = 1; j < mm; j++){
            if(year % 4 == 0 && j == 2)
                day += 29;
            else if(j == 2)
                day += 28;
            else if(j < 8 && j % 2 == 1)
                day += 31;
            else if(j < 8 && j % 2 == 0)
                day += 30;
            else if(j % 2 == 0)
                day += 31;
            else if(j % 2 == 1)
                day += 30;
        }
        h.push_back(day + dd);
    }
    d.push_back(0);
    per(0, d);
    d[0] = 1;
    per(0, d);

    return 0;
}