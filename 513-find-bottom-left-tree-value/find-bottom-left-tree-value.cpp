/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* &root,int &ans) {
        queue<pair<int,TreeNode*>> q;
        int level=0;
        q.push({0,root});
        while(!q.empty()){

            int prev_level = level;
            
            auto ele = q.front();
            level = ele.first; //0
            TreeNode* trav = ele.second;
          
            q.pop();
            //1
            //cout<<prev_level<<" ";
            if( trav->left ){
                q.push({level+1,trav->left}); //1
            }
            if( trav->right ){
                q.push({level+1,trav->right});//1
            }
            ans = prev_level < level ? trav->val : ans;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        if(!root->left && !root->right){
            return root->val;
        }
        bfs(root,ans);
        return ans;
    }
};