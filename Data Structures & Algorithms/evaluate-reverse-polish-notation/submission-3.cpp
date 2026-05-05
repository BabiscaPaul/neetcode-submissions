#include <optional>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::vector;
using std::unordered_set;

class Solution {
private:
    std::optional<int> compute(char op, int x, int y) {
        switch (op) {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
        }
        return std::nullopt;
    }
    vector<int> stack;
    unordered_set<string> opcodes{"+", "-", "/", "*"};
public:
    int evalRPN(vector<string>& tokens) {
        for (auto& token: tokens) {
            if (!opcodes.contains(token))
                stack.push_back(std::stoi(token));
            else {
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();

                stack.push_back(compute(token[0], x, y).value());
            }
        }
        return stack.back();
    }
};
