#include <cstddef>
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        std::unordered_set<int> seen{};
        std::vector<int> res{};

        for (const auto sublist: grid) {
            for (const int num: sublist) {
                if (seen.contains(num))
                    res.push_back(num);
                seen.insert(num);
            }
        }

        for (std::size_t num = 1; num <= grid.size() * grid.size(); ++num)
            if (!seen.contains(num)) {
                res.push_back(num);
                break;
        }

        return res;
    }
};