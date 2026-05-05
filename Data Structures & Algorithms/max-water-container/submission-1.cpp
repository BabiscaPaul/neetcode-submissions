class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int max_area = 0;

        while (l < r) {
            int curr_area = std::min(heights[l], heights[r]) * (r - l);
            max_area = std::max(max_area, curr_area);

            if (heights[l] <= heights[r])
                l++;
            else 
                r--;
        }

        return max_area;
    }
};
