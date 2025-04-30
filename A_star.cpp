#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
// follow the step

struct Cell {
    int x, y, cost, heuristic;
    vector<pair<int, int>> path;

    bool operator>(const Cell& other) const {
        return (cost + heuristic) > (other.cost + other.heuristic);
    }
};

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y, int n, int m, const vector<vector<int>>& grid) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0;
}

void aStarSearch(vector<vector<int>>& grid, int sx, int sy, int gx, int gy) {
    int n = grid.size(), m = grid[0].size();
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    pq.push({sx, sy, 0, manhattan(sx, sy, gx, gy), {{sx, sy}}});
    visited[sx][sy] = true;

    int dx[] = {-1, 1, 0, 0};  // up, down, left, right
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        Cell curr = pq.top();
        pq.pop();

        if (curr.x == gx && curr.y == gy) {
            cout << "Path found:\n";
            for (auto [x, y] : curr.path)
                cout << "(" << x << "," << y << ") ";
            cout << endl;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i], ny = curr.y + dy[i];
            if (isValid(nx, ny, n, m, grid) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                vector<pair<int, int>> newPath = curr.path;
                newPath.push_back({nx, ny});
                pq.push({nx, ny, curr.cost + 1, manhattan(nx, ny, gx, gy), newPath});
            }
        }
    }

    cout << "No path found.\n";
}

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid (0 = free, 1 = obstacle):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int sx, sy, gx, gy;
    cout << "Enter start (x y): ";
    cin >> sx >> sy;
    cout << "Enter goal (x y): ";
    cin >> gx >> gy;

    aStarSearch(grid, sx, sy, gx, gy);

    return 0;
}
