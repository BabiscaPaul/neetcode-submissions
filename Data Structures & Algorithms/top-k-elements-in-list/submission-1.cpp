class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency;
        
        for (int num: nums) {
            ++frequency[num];
        }

        std::vector<std::pair<int, int>> values;
        std::vector<int> res;

        for (auto [key, val]: frequency) {
            values.push_back({key, val});
        }

        std::sort(values.begin(), values.end(),[](const auto a, const auto b){return a.second > b.second;});

        for (int i = 0; i < k; ++i)
            res.push_back(values[i].first);
        
        return res;
    }
};
