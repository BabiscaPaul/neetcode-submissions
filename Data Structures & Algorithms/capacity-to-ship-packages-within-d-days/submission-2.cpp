#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
private:
    bool check(vector<int>& weights, int days, int capacity) {
        int group = 0, running_days = 1;

        for (const int weight: weights) {
            group += weight;
            
            if (group > capacity) {
                group = weight;
                running_days++;
            }
        }

        return running_days <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *std::max_element(weights.begin(), weights.end());
        int r = std::accumulate(weights.begin(), weights.end(), 0);
        int res = r;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (check(weights, days, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};