class Solution {
public:
    bool isPalindrome(string s) {
        string copy = "";
        for (auto ch: s) {
            if (std::isalnum(ch))
                copy += std::tolower(ch);
        }

        int i = 0, j = static_cast<int>(copy.size()) - 1;
        while (i < j) {
            if (copy[i] != copy[j])
                return false;
            ++i;
            --j;
        }

        return true;
    }
};
