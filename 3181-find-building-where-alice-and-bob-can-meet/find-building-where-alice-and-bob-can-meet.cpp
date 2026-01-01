class Solution {
public:

    void buildTree(int segTree[],vector<int>&heights, int i, int l, int r){
        if(l==r){
            segTree[i] = r; //storing index
            return;
        }
        int mid = l+(r-l)/2;
        buildTree(segTree,heights,2*i+1,l,mid);
        buildTree(segTree,heights,2*i+2,mid+1,r);

        int leftMaxIdx = segTree[2*i+1];
        int rightMaxIdx = segTree[2*i+2];

        if(heights[leftMaxIdx] >= heights[rightMaxIdx]){
            segTree[i] = leftMaxIdx;
        } 
        else{
            segTree[i] = rightMaxIdx;
        }
    }

    int *constructST(vector<int>&heights,int n){
        int *segTree = new int[4*n];
        buildTree(segTree,heights,0,0,n-1);
        return segTree;
    }

    int Idxquery(int segTree[],vector<int>&heights,int start,int end,int i,int l,int r){
        //out of bound
        if( l>end || r<start) return -1;
        //completely inside
        if( l>=start && r<=end) return segTree[i];
        //half overalpping
        int mid = l+(r-l)/2;
        //return (max(idxquery(left),idxquery(right)));
        int leftMaxIdx = Idxquery(segTree,heights,start,end,2*i+1,l,mid);
        int rightMaxIdx = Idxquery(segTree,heights,start,end,2*i+2,mid+1,r);
        
        if(leftMaxIdx==-1) return rightMaxIdx;
        if(rightMaxIdx==-1) return leftMaxIdx;

        if(heights[leftMaxIdx] >= heights[rightMaxIdx]) return leftMaxIdx;
        return rightMaxIdx;
    }

    // find max element index in the range of [a,b]
    int RMIQ(int segTree[],vector<int>&heights,int a,int b,int n){
        return Idxquery(segTree,heights,a,b,0,0,n-1);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int *segTree = constructST(heights,n);
        vector<int> result;
        for(auto &query : queries){
            int min_idx = min(query[0],query[1]);\
            int max_idx = max(query[0],query[1]);
        
            if(min_idx == max_idx){
                result.push_back(max_idx);
                continue;
            }
            else if(heights[max_idx] > heights[min_idx]){
                result.push_back(max_idx);
                continue;
            }
            //binary search approach
            int l = max_idx +1;
            int r = n-1;
            int result_idx = INT_MAX;
            while(l<=r){
                int mid = l+(r-l)/2;
                int idx = RMIQ(segTree,heights,l,mid,n);
                if(heights[idx] > max(heights[min_idx],heights[max_idx])){
                    result_idx = min(result_idx,idx);
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            if(result_idx == INT_MAX){
                result.push_back(-1);
            }
            else{
                result.push_back(result_idx);
            }
        }
        return result;
    }
};