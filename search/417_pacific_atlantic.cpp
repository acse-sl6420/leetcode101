#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> directions = {-1, 0, 1, 0, -1};

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        std::vector<std::vector<int>> ans = {};
        int m = heights.size();
        int n = heights[0].size();
        std::vector<std::vector<bool>> can_reach_p(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> can_reach_a(m, std::vector<bool>(n, false));

        // can reach pacific
        for (int i = 0; i < m; i++) {
            dfs(heights, can_reach_p, i, 0);
            dfs(heights, can_reach_a, i, n - 1);
        }

        // can reach atlantic
        for (int j = 0; j < n; j++) {
            dfs(heights, can_reach_p, 0, j);
            dfs(heights, can_reach_a, n - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (can_reach_a[i][j] && can_reach_p[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void dfs (std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& can_reach, int row, int col) {
        if (can_reach[row][col]) {
            return;
        }

        can_reach[row][col] = true;
        int temp_row;
        int temp_col;
        for (int i = 0; i < 4; i++) {
            temp_row = row + directions[i];
            temp_col = col + directions[i + 1];

            if (temp_row >= 0 && temp_row < heights.size() && \
                temp_col >= 0 && temp_col < heights[0].size() && \
                heights[temp_row][temp_col] >= heights[row][col]) {
                dfs(heights, can_reach, temp_row, temp_col);
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> heights = {{2,1},{1,2}};
    Solution so;
    std::vector<std::vector<int>> ans = so.pacificAtlantic(heights);
    
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }
}