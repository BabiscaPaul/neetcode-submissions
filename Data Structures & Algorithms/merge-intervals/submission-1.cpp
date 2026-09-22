#include <algorithm>
#include <cstddef>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), 
        [](auto a, auto b){return a[0] < b[0];});
        std::vector<std::vector<int>> result{intervals[0]};

        for (std::size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = std::max(result.back()[1], intervals[i][1]);
            } else result.push_back(intervals[i]);
        }

        return result;
    }
};
