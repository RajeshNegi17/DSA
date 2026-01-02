class Solution {
public:

    void updateSegTree(int i,int l,int r, int idx , vector<long long>&segTree){
        if(l==r) {
            segTree[i] = 1; //1 represents already visited
            return;
        }
        int mid = l +(r-l)/2;
        if(idx<=mid){
            updateSegTree(2*i+1,l,mid,idx,segTree);
        }
        else{
            updateSegTree(2*i+2,mid+1,r,idx,segTree);
        }
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    long long queryIDX(int i,int l,int r,int start,int end,vector<long long>&segTree){
        if (l>end || r<start) return 0;
        if (l>=start && r<=end) return segTree[i];
        int mid = l+(r-l)/2;
        long long leftCount = queryIDX(2*i+1,l,mid,start,end,segTree);
        long long rightCount = queryIDX(2*i+2,mid+1,r,start,end,segTree);

        return leftCount+rightCount;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long result=0;
        int n = nums1.size();
        vector<long long> segTree(4*n);
        unordered_map<int,int> map;

        for(int i=0 ; i<n ; i++){
            map[nums2[i]] = i;
        }

        updateSegTree(0,0,n-1,map[nums1[0]],segTree);

        for(int i=1 ; i<n ; i++){
            int idx = map[nums1[i]];

            long long leftCommonCount = queryIDX(0,0,n-1,0,idx,segTree);
            long long leftNotCommon  = i - leftCommonCount;
            long long num2_count_ele_afterIDX = (n-1) - idx;
            long long rightCommonCount = num2_count_ele_afterIDX - leftNotCommon;

            result += leftCommonCount * rightCommonCount;
            updateSegTree(0,0,n-1,idx,segTree);
        }
        return result;
    }
};