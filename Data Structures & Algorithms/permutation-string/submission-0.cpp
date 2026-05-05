#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int window_size = static_cast<int>(s1.size()), l = 0;
        std::unordered_map<char, int> s1_freq, s2_freq;

        for (char ch: s1) {
            s1_freq[ch]++;
        }

        for (int r = 0; r < static_cast<int>(s2.size()); ++r) {
            s2_freq[s2[r]]++;
            if (r - l + 1 == window_size) {
                if (s2_freq == s1_freq) return true;
                s2_freq[s2[l]]--;
                if (s2_freq[s2[l]] == 0) s2_freq.erase(s2[l]);
                l++;
            }
        }

        return false;
    }
};
