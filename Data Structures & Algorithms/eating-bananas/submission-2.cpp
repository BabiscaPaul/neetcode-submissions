#include <algorithm>
#include <cmath>
#include <vector> 
using std::vector;

class Solution {
private:
    bool check(const vector<int>& piles, int rate, int h) {
        int total = 0;

        for (const int pile: piles) {
            int time = std::ceil(static_cast<double>(pile) / rate);
            total += time;
            
            if (total > h) {
                return false;
            }
        }

        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *std::max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (check(piles, mid, h)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};