class Solution {
    public int majorityElement(int[] nums) {
        int vote=0;
        int cand = 0;
        for( int i=0;i<nums.length;i++){
            if( vote==0 ) cand = nums[i];
            if( nums[i] == cand ){
                vote++;
            }
            else{
                vote--;
            }
        }
        return cand;
    }
}