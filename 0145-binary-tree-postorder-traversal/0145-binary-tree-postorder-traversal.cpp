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
    vector<int>postorder;
public:
    void helper(TreeNode* root){
        if(root == NULL) return;
        
        helper(root->left);
        helper(root->right);
        postorder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return postorder;
    }
};