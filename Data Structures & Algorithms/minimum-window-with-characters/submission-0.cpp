#include <algorithm>
#include <exception>
#include <string>
#include <unordered_map>
using std::string;

using window = std::unordered_map<char, int>;

class Solution {
private:
    bool is_window_valid(const window& w1, const window& w2) {    
        for (const auto& [key, val]: w2) {
            try {
                auto freq = w1.at(key);
                if (freq < val) return false;
            } catch(std::exception exc) {
                return false;
            }
        }

        return true;
    }
public:
    string minWindow(string s, string t) {
        int l = 0, minimum = s.size();
        window s_window, t_window;
        string res;

        for (auto ch: t) {
            ++t_window[ch];
        }

        for (int r = 0; r < s.size(); ++r) {
            ++s_window[s[r]];

            while (is_window_valid(s_window, t_window)) {
                if (r - l + 1 <= minimum) {
                    minimum = r - l + 1;
                    res = s.substr(l, r - l + 1);
                }
                --s_window[s[l]];
                ++l;
            }
        }

        return res;
    }
};
