class Solution {
public:
    int scoreOfString(string s) {
        int previous = 0, sum = 0;
        for (char ch: s) {
            if (previous) {
                int abs_value = abs(int(ch) - previous);
                sum += abs_value;
            }
            previous = int(ch);
        }
        return sum;
    }
};