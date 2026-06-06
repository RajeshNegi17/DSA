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
            map.put(sum,map.getOrDefault(sum,0)+1);
        }
        return count;
    }
}