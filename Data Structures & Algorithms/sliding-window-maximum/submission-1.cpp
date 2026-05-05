#include <set>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        std::multiset<int> currWindow;
        int l = 0;
        
        for (int r = 0; r < nums.size(); ++r) {
            currWindow.insert(nums[r]);
            if (r - l + 1 == k) {
                result.push_back(*std::prev(currWindow.end()));
                currWindow.erase(currWindow.find(nums[l]));
                ++l;
            }
        }
        
        return result;
    }
};
