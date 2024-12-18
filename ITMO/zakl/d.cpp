#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool boi(int y, int x, int my, int mx) {
    // if (y == my - 1 && x == mx - 2) return true;
    if (y > my && x > mx) {
        if (y - my == x - mx) return true;
    }
    if (y > my && x < mx) {
        if (y - my == abs(x - mx)) return true;
    }
    if (y < my && x < mx) {
        if (2 * abs(y - my) == abs(x - mx)) return true;
    }
    if (y < my && x >= mx) {
        if (2 * abs(y - my) == x - mx) return true;
    }
    return false;
}

bool inP(int y, int x) {
    if ((x == 3 && y == 5) || boi(y, x, 5, 3)) return false;
    if (x == 3 + 2 && y == 5 - 1) return false;

    if (x == 4 && y == 8 || boi(y, x, 8, 4)) return false;
    if (x == 8 && y == 5 || boi(y, x, 5, 8)) return false;
    if (y <= x + 5 && y <= (10 - x) + 5 && x >= 0 && y >= 0 && x < 11 && y < 11) {
        return true;
    }
    return false;
}

void f(vector<vector<int>> &visited, int y, int x) {
    /*if (y == 4 && x == 5) {
        cout << "NO" << endl;
        return;
    }*/
    visited[y][x] = 1;
    int nx, ny;
    nx = x - 1;
    ny = y - 3;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x - 2;
    ny = y - 3;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x - 3;
    ny = y - 2;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x - 3;
    ny = y - 1;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x - 2;
    ny = y + 1;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x - 1;
    ny = y + 2;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x + 1;
    ny = y + 2;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x + 2;
    ny = y + 1;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x + 3;
    ny = y - 1;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x + 3;
    ny = y - 2;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x + 2;
    ny = y - 3;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
    nx = x + 1;
    ny = y - 3;
    if (inP(ny, nx) && visited[ny][nx] == 0) {
        f(visited, ny, nx);
    }
}

int main() {
    vector<vector<int>> visited(11, vector<int>(11));
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 11; x++) {
            if (inP(y, x) == false) {
                visited[y][x] = 2;
            }
        }
    }
    f(visited, 5, 4);
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 11; x++) {
            cout << visited[y][x] << " ";
        }
        cout << endl;
    }
    return 0;
}