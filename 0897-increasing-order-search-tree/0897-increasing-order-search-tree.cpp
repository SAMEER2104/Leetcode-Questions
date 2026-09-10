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
    
    TreeNode* dummy = new TreeNode(0);
    TreeNode *curr = dummy;

    void Inorder(TreeNode *root)
    {
         if (root == nullptr) 
         return;

        Inorder(root->left);

        root->left = nullptr; 
        curr->right = root;   

        curr = root;          

        // 3. Traverse the right subtree
        Inorder(root->right);
        
    };

    TreeNode* increasingBST(TreeNode* root) {

        Inorder(root);

        TreeNode* newRoot = dummy->right;

        delete(dummy);

        return newRoot;
    }
};