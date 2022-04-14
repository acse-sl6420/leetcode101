#include <iostream>
#include <vector>

class Solution {
public:
    int n;
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> nQueen(n, std::string(n, '.'));
        this->n = n;
        backtrack(res, nQueen, 0);
        return res;
    }

    void backtrack(std::vector<std::vector<std::string>>& res, std::vector<std::string>& nQueen, int row) {
        if (row == this->n) {
            res.push_back(nQueen);
            return;
        }

        // backtrack
        for (int i = 0; i < this->n; i++) {
            if (isValid(nQueen, row, i)) {
                nQueen[row][i] = 'Q';
                backtrack(res, nQueen, row + 1);
                nQueen[row][i] = '.';
            }
        }
    }

    bool isValid(std::vector<std::string>& nQueen, int row, int col) {
        for (int i = row; i >= 0; i--) {
            if (nQueen[i][col] == 'Q') {
                return false;
            }
        }

        // 45 degrees
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (nQueen[i][j] == 'Q') {
                return false;
            }
        }

        // 135 degrees
        for (int i = row - 1, j = col + 1; i >= 0 && j < this->n; i--, j++) {
            if (nQueen[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main () {
    int n = 4;
    Solution so;
    std::vector<std::vector<std::string>> ans = so.solveNQueens(4);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                std::cout << ans[i][j][k];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}