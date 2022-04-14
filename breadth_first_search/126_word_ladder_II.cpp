#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
public:
    std::vector<std::vector<std::string>> ans;

    void dfs(std::vector<std::string>& path, std::unordered_map<std::string, std::unordered_set<std::string>>& adj, std::string& beginWord, std::string& endWord) {
        path.push_back(beginWord);

        if (beginWord == endWord) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for (auto temp : adj[beginWord]) {
            dfs(path, adj, temp, endWord);
        }

        path.pop_back();
    }

    std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        std::unordered_map<std::string, std::unordered_set<std::string>> adj;

        std::unordered_map<std::string, int> visited;

        std::queue<std::string> q;
        q.push(beginWord);
        visited[beginWord] = 0;

        while (!q.empty()) {
            std::string cur = q.front();
            q.pop();
            std::string temp = cur;

            // find all the transformation of this word
            for (int i = 0; i < cur.size(); i++) {
                for (int j = 'a'; j <= 'z'; j++) {
                    temp[i] = j;

                    // skip if this word is same as the original word
                    if (temp[i] == cur[i]) {
                        continue;
                    }

                    // if this new word is present in the wordList
                    if (dict.count(temp) > 0) {
                        // if this new word is not visited
                        if (visited.count(temp) == 0) {
                            visited[temp] = visited[cur] + 1;
                            q.push(temp);
                            adj[cur].insert(temp);
                        } else if (visited[temp] == visited[cur] + 1) { // if this new word is visited, and is the child of the current word
                            adj[cur].insert(temp);
                        }
                    }
                }
                temp[i] = cur[i];
            }
        }

        // here we have the adjacency list, then we use dfs to find out all the combinations with shortest path
        std::vector<std::string> path;

        dfs(path, adj, beginWord, endWord);

        return ans;
    }
};

int main() {
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    std::string beginWord = "hit";
    std::string endWord = "cog";
    Solution so;
    std::vector<std::vector<std::string>> result = so.findLadders(beginWord, endWord, wordList);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}