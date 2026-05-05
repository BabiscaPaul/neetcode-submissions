#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int currBuy = prices[0], result = 0, currProfit = 0;

        for (int price: prices) {
            currProfit = price - currBuy;
            if (currProfit <= 0) currBuy = price;
            else if (currProfit > result) result = currProfit;
        }

        return result;
    }
};
