class Solution {
public:

    string encode(vector<string>& strs) {
        std::string out;
        for (const std::string& s : strs) {
            out += std::to_string(s.size());
            out += '|';
            out += s;
        }
        return out;
    }

    vector<string> decode(string s) {
        std::vector<std::string> out;
        size_t i = 0;

        while (i < s.size()) {
            std::string str_length;
            while (i < s.size() && s[i] != '|') {
                str_length += s[i];
                ++i;
            }
            int length = std::stoi(str_length);
            out.push_back(s.substr(i + 1, length));
            i += length + 1;
        }

        return out;
    }
};
