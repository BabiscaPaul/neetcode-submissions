#include <algorithm>
#include <vector> 
using std::vector;



class Solution {
private:
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = static_cast<int>(matrix.size()) - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            const auto& currVec = matrix[mid];
            
            bool found = std::binary_search(currVec.begin(), currVec.end(), target);
            if (found) return true;

            if (target < currVec.front()) r = mid - 1;
            else l = mid + 1;
        }

        return false;
    }
};
