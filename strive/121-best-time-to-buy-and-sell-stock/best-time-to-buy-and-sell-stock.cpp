class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_day = INT_MAX;
        int profit = 0;

        for (int price : prices){
            if (price < min_day){
                min_day = price;
            }
            profit = max(profit,price-min_day);
        }
        return profit;
    }
};