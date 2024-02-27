class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int max_diameter = 0;
        depth(root, max_diameter);
        return max_diameter;
    }
    
    int depth(TreeNode* root, int& max_diameter) {
        if (root == nullptr) return 0;
        
        int left_depth = depth(root->left, max_diameter);
        int right_depth = depth(root->right, max_diameter);
        
        // Calculate the diameter passing through the current node
        max_diameter = max(max_diameter, left_depth + right_depth);
        
        // Return the maximum depth of the subtree rooted at the current node
        return 1 + max(left_depth, right_depth);
    }
};
