#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map;
        for (auto num : nums) {
            ++freq_map[num];
        }

        std::vector<int> unique_keys;
        unique_keys.reserve(freq_map.size());
        for (auto [key, _] : freq_map) {
            unique_keys.push_back(key);
        }

        std::sort(unique_keys.begin(), unique_keys.end(), [&freq_map](int a, int b) { return freq_map[a] > freq_map[b]; });

        unique_keys.resize(k);
        return unique_keys;
    }
};

