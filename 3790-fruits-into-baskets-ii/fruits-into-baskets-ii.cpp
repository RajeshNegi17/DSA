class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int result=0;
        int n = baskets.size();

        for(int fruit : fruits){
            int flag=0; //flagging
            for(int i=0;i<n;i++){
                if(fruit <= baskets[i]){
                    baskets[i] = -1;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                result++;
            }
        }
        return result;
    }
};