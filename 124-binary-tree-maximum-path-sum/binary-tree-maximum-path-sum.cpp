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
    int max_sum(TreeNode* head,int &max_yet) {
        if(head==NULL) return 0;
        int left = max_sum(head->left,max_yet);
        int right = max_sum(head->right,max_yet);
        left = max(left,0);
        right = max(right,0);
        int sum = head->val + left + right;
        
        max_yet = max(sum,max_yet);
        return max(head->val+left,head->val+right);
    }
    int maxPathSum(TreeNode* root) {
        int max_yet=INT_MIN;
        max_sum(root,max_yet);
        return max_yet;
    }
};