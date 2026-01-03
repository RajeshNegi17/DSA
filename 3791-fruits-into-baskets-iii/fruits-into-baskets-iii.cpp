class Solution {
public:

    void buildSegTree(int segTree[] , int i, int l, int r,vector<int>&baskets){
        if(l==r){
            segTree[i] = baskets[l];
            return;
        }
        int mid = l+(r-l)/2;
        buildSegTree(segTree,2*i+1,l,mid,baskets);
        buildSegTree(segTree,2*i+2,mid+1,r,baskets);

        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
    }

    int *constructST(vector<int>& baskets,int n){
        int *segTree = new int[4*n];
        buildSegTree(segTree, 0 , 0, n-1,baskets);
        return segTree;
    }

    bool queryFound(int i,int l,int r,int fruit,int segTree[]){
        if(segTree[i] < fruit) return false;
        if( l==r ){
            segTree[i] = -1;
            return true;
        }
        int mid = l +(r-l)/2;
        bool placed= false;
        if(segTree[2*i+1] >= fruit){
            placed=queryFound(2*i+1,l,mid,fruit,segTree);
        }
        else{
            placed=queryFound(2*i+2,mid+1,r,fruit,segTree);
        }
        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int *segTree = constructST(baskets,n);
        int result=0;

        for( int &fruit : fruits ){
            if(queryFound(0,0,n-1,fruit,segTree) == false){
                result++;
            }
        }
        return result;
    }
};