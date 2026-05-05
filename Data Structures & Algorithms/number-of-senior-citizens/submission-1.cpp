class Solution {
public:
    int countSeniors(vector<string>& details) {
        int age, cnt = 0;
        for (const auto& d: details) {
            age = (d[11] - '0') * 10 + (d[12] - '0');
            if (age > 60) cnt++;
        }
        return cnt;
    }
};