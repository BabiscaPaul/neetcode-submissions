#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::vector;

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagrams; // sorted_word -> vector of anagrams

        for (const std::string& word: strs) {
            std::string copy {word};
            std::sort(copy.begin(), copy.end()); // N x Log(N)
            anagrams[copy].push_back(word);
        }

        std::vector<std::vector<std::string>> result {};

        for (const auto& [key, val]: anagrams)
            result.push_back(val);
        
        return result;
    }
};
