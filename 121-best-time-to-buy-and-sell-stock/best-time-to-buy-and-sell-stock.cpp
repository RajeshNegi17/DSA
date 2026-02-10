class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int answer=0;
        int buy = prices[0];
        for( int i=1 ;i <n;i++){
            if( prices[i] < buy) {
                buy = prices[i];
            }
            int diff = prices[i] - buy;
            answer = max(answer,diff);
        }
        return answer;
    }
};