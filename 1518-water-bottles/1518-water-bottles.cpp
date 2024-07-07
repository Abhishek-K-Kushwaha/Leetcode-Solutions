class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        while (true) {
            int newBottles = empty / numExchange;
            if (newBottles == 0)
                break;
            ans += newBottles;
            empty = (empty - newBottles * numExchange) + newBottles;
        }
        return ans;
    }
};