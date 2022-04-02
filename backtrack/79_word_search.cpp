#include <iostream>
#include <vector>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        bool result = false;
        int pos = 0;

        int m = board.size();
        int n = board[0].size();
        
        std::vector<std::vector<bool>> isVisted(board.size(), std::vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                backtrack(board, i, j, 0, result, isVisted, word);
            }
        }

        return result;
    }

    void backtrack(std::vector<std::vector<char>>& board, int i, int j, int pos, bool& result,\
                   std::vector<std::vector<bool>>& isVisted, std::string& word) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }

        if (isVisted[i][j] || board[i][j] != word[pos] || result) {
            return;
        }

        if (pos == word.size() - 1) {
            result = true;
            return;
        }

        isVisted[i][j] = true;

        // backtrace four directions
        backtrack(board, i - 1, j, pos + 1, result, isVisted, word);
        backtrack(board, i + 1, j, pos + 1, result, isVisted, word);
        backtrack(board, i, j - 1, pos + 1, result, isVisted, word);
        backtrack(board, i, j + 1, pos + 1, result, isVisted, word);
        isVisted[i][j] = false;
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    Solution so;
    bool result = so.exist(board, "ABCCED");
    if (result) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
}