#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> frequency{};
        
        for (char ch: s) {
            ++frequency[ch];
        }

        for (char ch: t) {
            --frequency[ch];
        }

        for (const auto [key, val]: frequency) {
            if (val != 0)
                return false;
        }

        return true;
    }
};
