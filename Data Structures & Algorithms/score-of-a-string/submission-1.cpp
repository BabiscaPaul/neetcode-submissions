class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;

        for (int i = 1; i < s.size(); ++i) {
            int abs_diff = abs(s[i] - s[i - 1]);
            sum += abs_diff;
        }

        return sum;
    }
};