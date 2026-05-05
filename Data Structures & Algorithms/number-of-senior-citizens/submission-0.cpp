class Solution {
public:
    int countSeniors(vector<string>& details) {
        int age, cnt = 0;
        for (const auto& d: details) {
            age = std::stoi(d.substr(11, 2));
            if (age > 60) cnt++;
        }
        return cnt;
    }
};