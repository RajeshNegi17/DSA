class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        lowest_price = float('inf')
        profit = 0
        for price in prices:
            lowest_price = min(lowest_price,price)
            profit = max(profit,price - lowest_price)
        return profit
            