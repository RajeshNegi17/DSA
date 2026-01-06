class Solution {
public:
    int climbStairs(int n) {
        vector<int>arr(n+1,-1);
        arr[0] = 0;
        arr[1] = 1;
        if( n<=1 ){
            return n;
        }
        arr[2] = 2;
        for(int i=3;i<=n;i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
};
/*
state transition
arr[i] = 0,1,2,3,
t[i] = arr[i-1] + arr[i-2];
arr[4] = arr[3]+arr[2];
*/