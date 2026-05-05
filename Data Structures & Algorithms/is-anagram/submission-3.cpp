class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> count;
        for (auto ch: s) {
            count[ch]++;
        }

        for (auto ch: t) {
            count[ch]--;
            if (count[ch] == 0)
                count.erase(ch);
        }   

        return count.empty();
    }
};
