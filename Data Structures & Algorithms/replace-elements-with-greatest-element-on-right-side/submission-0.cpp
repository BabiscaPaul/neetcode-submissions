class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::vector<int> res = arr;
        int curr_max = -1;
        for (int i = static_cast<int>(res.size() - 1); i >= 0; i--) {
            int curr_num = res[i];
            res[i] = curr_max;
            curr_max = std::max(curr_max, curr_num);
        }
        return res;
    }
};