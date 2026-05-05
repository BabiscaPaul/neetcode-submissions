#include <unordered_map>
#include <string>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> parantheses{
            {'(', ')'}, 
            {'[', ']'}, 
            {'{', '}'}
        };

        std::vector<char> stack;

        for (auto ch: s) {
            if (parantheses.contains(ch))
                stack.push_back(ch);
            else {
                if (!stack.empty() && ch == parantheses[stack.back()]) {
                    stack.pop_back();
                    continue;
                }
                return false;
            }
        }

        return stack.empty();
    }
};
