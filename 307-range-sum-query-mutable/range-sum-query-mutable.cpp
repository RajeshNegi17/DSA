class NumArray {
private:
//segement Treee;
    int n;
    vector<int>segTree;

    void buildTree(vector<int> &nums,int i,int left,int right){
        if(left==right){
            segTree[i] = nums[right];
            return;
        }
        int mid =(left+right)/2;
        buildTree(nums,2*i+1,left,mid);
        buildTree(nums,2*i+2,mid+1,right);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void updateTree(int idx , int val , int i ,int left,int right){
        if(left==right){
            segTree[i] = val;
            return;
        }
        int mid = (left+right)/2;
        if(idx<=mid){
            updateTree(idx,val,2*i+1,left,mid);
        }
        else{
            updateTree(idx,val,2*i+2,mid+1,right);
        }
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int query(int start,int end,int i,int left,int right){
        if(left>end || right<start) return 0;
        if(left>=start && right<=end) return segTree[i];
        int mid = (left+right)/2;
        return query(start,end,2*i+1,left,mid) + query(start,end,2*i+2,mid+1,right);
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        buildTree(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        updateTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */