#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::priority_queue<Pair, std::vector<Pair>, ByFrequency> pq {};
        std::unordered_map<int, int> frequency_map {};
        std::vector<int> result {};

        // build the hashmap
        for (const int num: nums) {
            ++frequency_map[num];
        }
        // build the heap
        for (const auto [key, freq]: frequency_map) {
            pq.push({key, freq});
        }

        while (k > 0) {
            const int copy = pq.top().first;
            result.push_back(copy);
            pq.pop();
            --k;
        }

        return result;
    }

private:
    using Pair = std::pair<int, int>;

    struct ByFrequency {
        bool operator() (const Pair& a, const Pair& b) const {
            return a.second < b.second;
        }
    };
};
