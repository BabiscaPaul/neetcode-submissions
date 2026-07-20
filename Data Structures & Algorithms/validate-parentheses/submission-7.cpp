#include <unordered_map>
#include <stack>
#include <string>
using std::string;

class Solution {
public:
bool isValid(string s) {
        std::unordered_map<char, char> hashmap = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        std::stack<char> stack;
        size_t i = 0;
        
        while (i < s.size()) {

            if (hashmap.contains(s[i])) {
                stack.push(s[i]);
            } else {
                if (!stack.empty() && hashmap.at(stack.top()) == s[i])
                    stack.pop();
                else return false;
            }
            ++i;
        }

        return stack.empty();
    }
};
