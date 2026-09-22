#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::vector;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen{};
        
        for (const int num: nums) {
            if (seen.contains(num)) return true;
            seen.insert(num);
        }

        return false;
    }
};