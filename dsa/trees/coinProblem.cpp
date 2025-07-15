
/**
🔹 Problem: Distribute Coins in Binary Tree (LC 979)

Given a binary tree where each node has val coins, and the total number of coins equals the number of nodes.
In one move, you can move one coin from a node to its parent or child.
Return the minimum number of moves required so that every node has exactly one coin.
**/


class Solution {
public:
    int postOrderTraversal(TreeNode* root, int &move){
        if(!root) return 0;
        int left = postOrderTraversal(root->left, move);
        int right = postOrderTraversal(root->right, move);
        move += abs(left) + abs(right);
        return root->val + left+ right -1;
    }
    int distributeCoins(TreeNode* root) {
        int move = 0;
        int coinRequired = postOrderTraversal(root, move);
        return move;
    }
};