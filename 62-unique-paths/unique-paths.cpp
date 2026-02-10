class Solution {
public:

    int rec(int m,int n, int i,int j,vector<vector<int>>&dp) {
        
        if( i<0 || i>=m || j<0 || j>=n) {
            return 0;
        }

        if( dp[i][j] != -1 ){
            return dp[i][j];
        }
        if( i==m-1 && j==n-1){
            return 1;
        }

        int right =  rec(m,n,i+1,j,dp);
        int down =  rec(m,n,i,j+1,dp);

        return dp[i][j] = right+down;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,-1));// dp=[ [-1,-1],[-1,-1],[-1,-1] ]
        return rec(m,n,0,0,dp);
       
    }
};

/*
1 1 0
1 0 0
1 1 -1
*/