class Solution {
public:

    int solve(vector<string>& strs,
              int i,
              int zerosLeft,
              int onesLeft,
              vector<vector<vector<int>>>& dp) {

        // base case
        if (i == strs.size())
            return 0;

        if (dp[i][zerosLeft][onesLeft] != -1)
            return dp[i][zerosLeft][onesLeft];

        // count zeros and ones in current string
        int zero = 0, one = 0;
        for (char c : strs[i]) {
            if (c == '0') zero++;
            else one++;
        }

        // option 1: skip
        int skip = solve(strs, i+1, zerosLeft, onesLeft, dp);

        // option 2: take (if possible)
        int take = 0;
        if (zero <= zerosLeft && one <= onesLeft) {
            take = 1 + solve(strs,
                             i+1,
                             zerosLeft - zero,
                             onesLeft - one,
                             dp);
        }

        return dp[i][zerosLeft][onesLeft] = max(skip, take);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        int k = strs.size();

        vector<vector<vector<int>>> dp(
            k,
            vector<vector<int>>(m+1,
                vector<int>(n+1, -1)
            )
        );

        return solve(strs, 0, m, n, dp);
    }
};