#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encodedStr;

        for (const auto& s: strs) {
            encodedStr += std::to_string(s.size()) + '#' + s;
        }

        return encodedStr;
    }

    vector<string> decode(string s) {
        std::vector<string> res;
        int i = 0;

        while (i < static_cast<int>(s.size())) {
            int j = s.find('#', i);
            int len = std::stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }

        return res;
    }
};
