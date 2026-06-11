class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit=0
        diff=0
        buy = prices[0]
        for num in prices[1:]:
            if num < buy:
                buy = num
            else:
                diff = num - buy
            profit = max(profit,diff)
        return profit
