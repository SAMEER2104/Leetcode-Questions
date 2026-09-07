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
    int minDepth(TreeNode* root) {

        // Using DFS -->

        if(root==NULL)
        return 0;

        if(root->left == NULL && root->right == NULL)
        return 1;
        
        if(root -> left == NULL)
        return 1 + minDepth(root -> right);

        if(root -> right == NULL)
        return 1 + minDepth(root -> left);

        int L = minDepth(root->left);

        int R = minDepth(root->right);

        return min(L,R) + 1;
        
    }
};