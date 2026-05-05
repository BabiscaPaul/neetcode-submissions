#include <algorithm>
#include <unordered_map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> frequency;
        int longest = 0;
        int l = 0;

        for (int r = 0; r < s.size(); ++r) {
            char ch = s[r];
            frequency[ch]++;
            
            while (frequency[ch] > 1) {
                frequency[s[l]]--;
                if (frequency[s[l]] == 0) frequency.erase(s[l]);
                l++;
            }

            longest = std::max(longest, r - l + 1);
        }

        return longest;
    }
};