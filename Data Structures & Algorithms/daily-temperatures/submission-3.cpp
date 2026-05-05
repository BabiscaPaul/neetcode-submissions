// Example 1:
// Input: temperatures = [30,38,30,36,35,40,28]
//                        0. 1. 2. 3. 4. 5. 6. 
// Output: [1,4,1,2,1,0,0]
// result = [_, _, _, _, _, _, 0]
// store a std::pair <temperature, index> in the stack
// !! monotonically decreasing stack !!
// stack = [(40, 5)]

// Example 2:
// Input: temperatures = [22,21,20]
// Output: [0,0,0]

#include <stack>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<std::pair<int, int>> decr_stack;
        std::vector<int> result(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!decr_stack.empty() && temperatures[i] >= decr_stack.top().first) {
                decr_stack.pop();
            }
            if (!decr_stack.empty()) result[i] = decr_stack.top().second - i;
            decr_stack.push({temperatures[i], i});
        }

        return result;
    }
};
