class Solution {
private:
    bool canEatPiles(const vector<int>& piles, int rate, int h) {
        int count = 0;
        
        for (const auto& pile: piles) {
            count += (pile + rate - 1) / rate;
        }

        return count <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = *std::max_element(piles.begin(), piles.end());
        int lower = 1;
        int result = upper;
        
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if (canEatPiles(piles, mid, h)) {
                upper = mid - 1;
                result = mid;
            } else {
                lower = mid + 1;
            }
        }

        return result;
    }
};