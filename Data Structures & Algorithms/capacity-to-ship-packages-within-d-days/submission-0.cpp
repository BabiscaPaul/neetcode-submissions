#include <numeric>
#include <vector>
#include <algorithm>
using std::vector;

/*
    Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
    Output: 15

    Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
    1st day: 1, 2, 3, 4, 5
    2nd day: 6, 7
    3rd day: 8
    4th day: 9
    5th day: 10

    ship_capacity = [min(weights), sum(weights)]
*/

class Solution {
private:
    bool canShipAllPackages(const vector<int>& weights, int days, int givenCapacity) {
        int groupSum = 0, daysCount = 1;

        for (const auto& weight: weights) {
            if (groupSum + weight > givenCapacity) {
                groupSum = 0;
                ++daysCount;
            }
            groupSum += weight;
        }

        return daysCount <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lower = *std::max_element(weights.begin(), weights.end());
        int upper = std::accumulate(weights.begin(), weights.end(), 0);
        int result = upper;

        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if (canShipAllPackages(weights, days, mid)) {
                upper = mid - 1;
                result = mid;
            } else {
                lower = mid + 1;
            }
        }

        return result;
    }
};