#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
private:
    bool check(const vector<int>& vec, int capacity, int days) {
        int curr = 0;
        int count_days = 1;
        
        for (auto weight: vec) {
            if (curr + weight > capacity) {
                ++count_days;
                curr = 0;
            }

            curr += weight;
        }

        return count_days <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *std::max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(), weights.end(), 0);
        int result = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(weights, mid, days)) {
                right = mid - 1;
                result = mid;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};