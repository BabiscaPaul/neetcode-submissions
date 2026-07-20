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
        
        for (char ch : s) {
            if (hashmap.contains(ch)) {
                stack.push(ch);
            } else {
                if (!stack.empty() && hashmap.at(stack.top()) == ch)
                    stack.pop();
                else return false;
            }
        }

        return stack.empty();
    }
};
