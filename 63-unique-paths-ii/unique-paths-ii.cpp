class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<vector<int>>& obstacleGrid,int i,int j,int m, int n,vector<vector<int>>& dp){
        if( i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        if( obstacleGrid[i][j]==1 ){
            return 0;
        }
        if( dp[i][j]!=-1 ){
            return dp[i][j];
        }
        if( i==m-1 && j==n-1) {
            return 1;
        }

        int down = rec(obstacleGrid,i+1,j,m,n,dp);//down
        int right = rec(obstacleGrid,i,j+1,m,n,dp);//right
        return dp[i][j] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return rec(obstacleGrid,0,0,m,n,dp);
    }
};