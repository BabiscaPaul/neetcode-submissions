#include <cctype>
#include <string>
using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        string new_s;
        
        for (char ch: s) {
            if (isalnum(ch))
                new_s += tolower(ch);
        }

        int i = 0, j = static_cast<int>(new_s.size()) - 1;
        while (i < j) {
            if (new_s[i] != new_s[j]) return false;
            ++i;
            --j;
        }

        return true;
    }
};
