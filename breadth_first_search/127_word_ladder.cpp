#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet;
        bool isPresent = false;
        for (auto word : wordList) {
            if (word.compare(endWord)==0) {
                isPresent = true;
            }
            wordSet.insert(word);
        }
        
        // if endword is not in the wordList
        if (!isPresent) {
            return 0;
        }

        std::queue<std::string> q;
        int level = 0;
        q.push(beginWord);

        while (!q.empty()) {
            level++;
            int lsize = q.size();
            while (lsize--) {
                std::string cur = q.front();
                q.pop();
                
                for (int i = 0; i < cur.size(); i++) {
                    std::string temp = cur;
                    for (int j = 'a'; j <= 'z'; j++) {
                        temp[i] = j;

                        if (temp.compare(endWord) == 0) { // endword founded
                            return level + 1;
                        } else if (temp[i] == cur[i]) { // skip the same word
                            continue;
                        } else if (wordSet.find(temp) != wordSet.end()) {
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    std::string beginWord = "hit";
    std::string endWord = "cog";

    Solution so;
    int paths = so.ladderLength(beginWord, endWord, wordList);
    std::cout << paths << std::endl;
}