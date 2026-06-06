class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Long,Integer>map = new HashMap<>();
        map.put(0L,1);
        int count=0;
        Long sum=0L;
        for( int num:nums){
            sum += num;
            if( map.containsKey(sum-k)){
                count+=map.get(sum-k);
            }
            if(!map.containsKey(sum)){
                map.put(sum,1);
            }
            else{
                int i=map.get(sum)+1;
                map.put(sum,i);
            }
        }
        return count;
    }
}