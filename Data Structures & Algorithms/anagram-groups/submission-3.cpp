#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {    
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (std::string word: strs) {
            std::string copy = word;
            std::sort(copy.begin(), copy.end());
            groups[copy].push_back(word);
        }

        std::vector<std::vector<string>> res;

        for (const auto [key, val]: groups) {
            res.push_back(val);
        }

        return res;
    }
};
