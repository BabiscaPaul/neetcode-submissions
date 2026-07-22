#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
private:
    bool check(const vector<int>& chocolate_bar, int groups, int threshold) {
        int running_sweetness = 0;
        int total = 0;

        for (auto bar: chocolate_bar) {
            running_sweetness += bar;

            if (running_sweetness >= threshold) {
                ++total;
                running_sweetness = 0;
            }
        }

        return total >= groups;
    }
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = *std::min_element(sweetness.begin(), sweetness.end());
        int right = std::accumulate(sweetness.begin(), sweetness.end(), 0);
        int res = right;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (check(sweetness, k + 1, mid)) {
                left = mid + 1;
                res = mid;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};
