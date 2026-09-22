#include <unordered_map>
#include <string> 
using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> char_freq;

        for (const char ch: s) {
            ++char_freq[ch];
        }

        for (const char ch: t) {
            --char_freq[ch];
        }

        for (const auto [_, val]: char_freq)
            if (val != 0)
                return false;
        
        return true;
    }
};
