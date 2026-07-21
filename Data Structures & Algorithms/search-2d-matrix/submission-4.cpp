#include <vector> 
using std::vector;

// Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 10

// Output: true

class Solution {
private:
    bool binary_search(const vector<int>& vec, int target) {
        int l = 0, r = vec.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (vec[mid] == target)
                return true;
            if (target < vec[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int first = matrix[mid].front(), last = matrix[mid].back();
            if (first == target || last == target) return true;

            if (first < target && target < last) {
                bool found =  binary_search(matrix[mid], target);
                if (found) return true;
            }
                
            if (target < first)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};
