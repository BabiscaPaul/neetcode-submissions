#include <algorithm>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, max = 0;
        unordered_map<char, int> count;
        
        for (int right = 0; right < s.size(); ++right) {
            ++count[s[right]];

            while (count.at(s[right]) > 1) {
                --count[s[left]];
                ++left;
            }

            max = std::max(max, right - left + 1);
        }

        return max;
    }
};
