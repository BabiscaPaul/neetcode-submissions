#include <algorithm>
#include <unordered_map>
#include <string> 

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int l = 0, res = 0;
        int maj_elem_count = 0;
        std::unordered_map<char, int> frequency;

        for (int r = 0; r < static_cast<int>(s.size()); ++r){
            frequency[s[r]]++;
            int curr_window_size = r - l + 1;
            auto it = std::max_element(frequency.begin(), frequency.end(), [](const auto& a, const auto& b){return a.second < b.second;});
            maj_elem_count = it->second;

            while (curr_window_size - maj_elem_count > k) {
                frequency[s[l]]--;
                l++;
                curr_window_size--;
                auto it = std::max_element(frequency.begin(), frequency.end(), [](const auto& a, const auto& b){return a.second < b.second;});
                maj_elem_count = it->second;
            }

            res = std::max(res, curr_window_size);
        }

        return res;
    }
};
