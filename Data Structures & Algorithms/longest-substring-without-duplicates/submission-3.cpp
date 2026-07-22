#include <algorithm>
#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, res = 0;
        unordered_set<char> char_set;
        
        for (int right = 0; right < s.size(); ++right) {
            while (char_set.find(s[right]) != char_set.end()) {
                char_set.erase(s[left]);
                ++left;
            }
            
            char_set.insert(s[right]);
            res = std::max(res, right - left + 1);
        }

        return res;
    }
};
