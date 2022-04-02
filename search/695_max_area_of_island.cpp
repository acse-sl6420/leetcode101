#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> directions = {-1, 0, 1, 0, -1};
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int area = 0;
        int temp_area = 0;
        std::stack<std::pair<int, int>> temp;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // viewed
                    grid[i][j] = 0;
                    temp_area = 1;
                    temp.push({i, j});

                    while (!temp.empty()) {
                        int row = temp.top().first;
                        int col = temp.top().second;
                        temp.pop();

                        for (int k = 0; k < 4; k++) {
                            int temp_row = row + directions[k];
                            int temp_col = col + directions[k + 1];

                            if (temp_row >= 0 && temp_row < m && \
                                temp_col >= 0 && temp_col < n && grid[temp_row][temp_col] == 1) {
                                    grid[temp_row][temp_col] = 0;
                                    temp_area++;
                                    temp.push({temp_row, temp_col});
                                }
                        }
                    }
                    
                    area = (area > temp_area) ? area : temp_area;
                }
            }
        }

        return area;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution so;
    int result = so.maxAreaOfIsland(grid);
    std::cout << result << std::endl;
} 