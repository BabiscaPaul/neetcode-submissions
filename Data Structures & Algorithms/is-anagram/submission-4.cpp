#include <unordered_map>
#include <string>
using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> map;

        for (char ch: s) {
            map[ch]++;
        }

        for (char ch: t) {
            map[ch]--;
            if (map[ch] == 0)
                map.erase(ch);
        }

        return map.empty();
    }
};
