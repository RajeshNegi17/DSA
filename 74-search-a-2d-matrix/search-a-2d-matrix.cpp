class Solution {
public:

    int rowSearch(vector<vector<int>>&matrix,int target){
        int l = 0;
        int r = matrix.size()-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if( matrix[mid][0] == target){
                return mid;
            }
            if( matrix[mid][0] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return r <0 ? 0:r ;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index = rowSearch(matrix,target);
        int l = 0;
        int r = matrix[0].size()-1;

        while(l <= r){
            int mid = l+(r-l)/2;
            if( matrix[index][mid]==target){
                return true;
            }
            if( matrix[index][mid] < target) {
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;
    }
};