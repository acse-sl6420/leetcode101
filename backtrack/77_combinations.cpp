#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> comb(k, 0);
        backtrack(result, comb, 0, 1, n, k);
        return result;
    }

    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& comb, int count, int pos, int n, int k) {
        if (count == k) {
            result.push_back(comb);
            return;
        }

        for (int i = pos; i <= n; i++) {
            comb[count++] = i;
            backtrack(result, comb, count, i + 1, n, k);
            count--;
        }
    }
};

int main () {
    int n = 4;
    int k = 2;

    Solution so;
    std::vector<std::vector<int>> result = so.combine(n, k);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            std::cout << result[i][j] << " ";
        }

        std::cout << std::endl;
    }
}