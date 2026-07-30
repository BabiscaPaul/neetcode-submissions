#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<char>> digits_map{
        {2, {'a', 'b', 'c'}}, 
        {3, {'d', 'e', 'f'}}, 
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}}, 
        {6, {'m', 'n', 'o'}}, 
        {7, {'p', 'q', 'r', 's'}}, 
        {8, {'t', 'u', 'v'}}, 
        {9, {'w', 'x', 'y', 'z'}}, 
    };

    void dfs(int index, string& partial_res, vector<string>& res, const string& digits) {
        if (index >= digits.size()) {
            res.push_back(partial_res);
            return;
        }

        for (char ch: digits_map.at(digits[index] - '0')) {
            partial_res += ch;
            dfs(index + 1, partial_res, res, digits);
            partial_res.pop_back();
        }
    }
public:

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return { };
        vector<string> result;
        string partial_res;
        dfs(0, partial_res ,result, digits);
        return result;
    }
};
