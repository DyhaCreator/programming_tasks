#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    double mx, my, ax, ay, bx, by;
    std::cin >> mx >> my >> ax >> ay >> bx >> by;
    if ((mx - ax) * (by - ay) == (bx - ax) * (my - ay)) {
        if (std::min(ay, by) <= my && (std::max(ay, by) >= my) && std::min(ax, bx) <= mx && std::max(ax, bx) >= mx){
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
}