#include <unordered_map>
#include <string> 
using std::string;
using std::unordered_map;

using permutation = unordered_map<char, int>;


class Solution {
private:
    bool is_permutation(permutation a, permutation b) {
        for (const auto [key, val]: b) {
            if (val == 0) continue;
            if (a[key] != val)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        permutation perm_s1, perm_s2;
        
        for (char ch: s1) {
            ++perm_s1[ch];
        }

        int l = 0;

        for (int r = 0; r < s2.size(); ++r) {
            ++perm_s2[s2[r]];
            
            if (r - l + 1 == s1.size()) {
                if (is_permutation(perm_s1, perm_s2)) return true;
                --perm_s2[s2[l]];
                ++l;
            }
        }

        return false;
    }
};
