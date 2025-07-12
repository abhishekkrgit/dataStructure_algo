
class Solution {
public:
    TreeNode* ans;
    TreeNode* postOrderTraversal(TreeNode*curr, TreeNode*p, TreeNode*q){
        if(!curr) return NULL;
        if(curr->val == p->val || curr->val == q->val) return curr;

        TreeNode* left = postOrderTraversal(curr->left, p, q);
        TreeNode* right = postOrderTraversal(curr->right, p, q);

        if(left && right) return curr;
        return left? left: right;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        return postOrderTraversal(root, p, q);
    }
};