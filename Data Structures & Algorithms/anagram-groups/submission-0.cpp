#include <array>

struct ArrayHash {
    std::size_t operator()(const std::array<int, 26>& arr) const {
        std::size_t h = 0;
        for (int i : arr) {
            h ^= std::hash<int>{}(i) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

class Solution {
public:
    std::array<int, 26> get_encoded_word(const string& word) {
        std::array<int, 26> arr{0};
        for (const auto& ch: word) {
            arr[ch - 'a']++;
        }
        return arr;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::array<int, 26>, std::vector<string>, ArrayHash> map;
        std::vector<vector<string>> res;
        res.reserve(strs.size());

        for (const auto& word: strs) {
            map[get_encoded_word(word)].push_back(word);
        }
        
        for (auto it = map.begin(); it != map.end(); ++it) {
            res.push_back(it->second);
        }
        
        return res;
    }
};