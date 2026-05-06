class Solution {
public:
    int jump(vector<int>& nums) {
        int destination = nums.size()-1;
        int window_size=0;
        int flag=0;
        int jump=0;
        //edge case
        if( nums.size()==1 ) return 0;
        //greedy apprach
        for( int i=0; i<nums.size(); i++ ){
            window_size=max(window_size,nums[i] + i);

            if( i==flag ){
                flag = window_size;
                jump++;

                if( flag>=destination ){
                    return jump;
                }
            }
        }
        return jump;
    }
};