#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int row = 0;
    int col = 0;
    std::queue<std::pair<int, int>> points;
    std::vector<int> directions = {-1, 0, 1, 0, -1};
    
    int shortestBridge(std::vector<std::vector<int>>& grid) {
        // dfs the grid to find out the first island
        row = grid.size();
        col = grid[0].size();
        bool flipped = false;

        for (int i = 0; i < row; i++) {
            if (flipped)
                break;
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    flipped = true;
                    break;
                }
            }
        }

        // for (int i = 0; i < row; i++) {
        //     for (int j = 0; j < col; j++) {
        //         std::cout << grid[i][j];
        //     }
        //     std::cout << std::endl;
        // }
        
        int level = 0;
        int x, y;

        while (!points.empty()) {
            level++;
            int n_size = points.size();
            while (n_size--) {
                auto temp = points.front();
                points.pop();
                
                for (int i = 0; i < 4; i++) {
                    x = temp.first + directions[i];
                    y = temp.second + directions[i + 1];

                    if (x >= 0 && y >= 0 && x < row && y < col) {
                        if (grid[x][y] == 2) {
                            continue;
                        }

                        if (grid[x][y] == 1) {
                            return level;
                        }

                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs (std::vector<std::vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i > row - 1 || j > col - 1 || grid[i][j] == 2) {
            return;
        }

        if (grid[i][j] == 0) {
            points.push({i, j});
            return;
        }
        
        grid[i][j] = 2;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);

    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0,1},{1,0}};
    Solution so;
    int result = so.shortestBridge(grid);
    std::cout << result << std::endl;
}