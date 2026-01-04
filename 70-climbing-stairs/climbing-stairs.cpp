class Solution {
public:
    int climbStairs(int n) {
        vector<int> memArray(n+1);

        if ( n==0 || n==1){
            return n;
        }

        memArray[0] = 0;
        memArray[1] = 1;
        memArray[2] = 2;
        for(int i=3 ; i<=n; i++) {
            memArray[i] = memArray[i-1] + memArray[i-2];
        }
        return memArray[n];
    }
};