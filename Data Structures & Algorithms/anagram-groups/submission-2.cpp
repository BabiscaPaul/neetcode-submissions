#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        std::vector<std::vector<std::string>> res;

        for (const auto& word: strs) {
            auto wordCopy = word;
            std::sort(wordCopy.begin(), wordCopy.end());
            map[wordCopy].push_back(word);
        }

        for (const auto& [key, val]: map) {
            res.push_back(val);
        }

        return res;
    }
};

