class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> map_s, map_t;
        for (auto ch: s) map_s[ch] += 1;
        for (auto ch: t) map_t[ch] += 1;
        return map_s == map_t;
    }
};