#include <algorithm>
#include <cmath>
#include <vector>
using std::vector;

class Solution {
private:
    bool check(const vector<int>& vec, int rate, int h) {
        int count = 0;

        for (auto pile: vec) {
            count += std::ceil(pile / static_cast<double>(rate));
            if (count > h)  
                return false;
        }

        return count <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *std::max_element(piles.begin(), piles.end());
        int result = left;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(piles, mid, h)) {
                right = mid - 1;
                result = mid;
            }
            else 
                left = mid + 1;
        }

        return result;
    }
};
