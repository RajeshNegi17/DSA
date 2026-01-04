class Solution {
public:
    int countWays(int n , vector<int>& memArray) {
        if (n<0){
            return 0;
        }

        if (memArray[n] != -1){
            return memArray[n];
        }

        if(n ==0 ){ 
            return 1;
        }

        int one_step = countWays(n-1,memArray);
        int two_step = countWays(n-2,memArray);

        return memArray[n] = one_step + two_step;
    }
    int climbStairs(int n) {
        vector<int> memArray(n+1, -1);
        return countWays(n,memArray);
    }
};