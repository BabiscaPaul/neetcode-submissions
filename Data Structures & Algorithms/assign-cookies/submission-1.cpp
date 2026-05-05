#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int count = 0, i = 0, j = 0;

        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                ++i;
                ++j;
                ++count;
            } else {
                ++j;
            }
        }

        return count;
    }
};