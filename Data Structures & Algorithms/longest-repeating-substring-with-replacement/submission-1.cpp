#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::unordered_map<char, int> count_map;
        int l = 0, max_window = 0;

        for (int r = 0; r < s.size(); ++r) {
            ++count_map[s[r]];
            auto it = std::max_element(count_map.begin(), count_map.end(), [](auto a, auto b){return a.second < b.second;});
            int most_freq = it->second;

            while (r - l + 1 - most_freq > k) {
                --count_map[s[l]];
                ++l;
                auto it = std::max_element(count_map.begin(), count_map.end(), [](auto a, auto b){return a.second < b.second;});
                most_freq = it->second;
            }

            max_window = std::max(max_window, r - l + 1);
        }

        return max_window;
    }
};
