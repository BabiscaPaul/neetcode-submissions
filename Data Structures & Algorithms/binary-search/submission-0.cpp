class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (static_cast<int>(nums.size()) == 1) {
            if (nums.front() == target) return 0;
            return -1;
        }

        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                l = mid + 1;
            } else r = mid - 1;
        }

        return -1;
    }
};
