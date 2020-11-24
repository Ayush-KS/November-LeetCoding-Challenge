// House Robber III

class Solution {
public:
    unordered_map<TreeNode*, int> mp;
    unordered_map<TreeNode*, bool> visited;
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        if(visited[root])
            return mp[root];
        visited[root] = true;
        
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        
        int ans = rob(root -> left) + rob(root -> right);
        int leftAns = 0;
        if(left) {
            leftAns = rob(left -> left) + rob(left -> right);
        }
        int rightAns = 0;
        if(right) {
            rightAns = rob(right -> left) + rob(right -> right);
        }
        
        ans = max(ans, root -> val + leftAns + rightAns);
        
        mp[root] = ans;
        return ans;
    }
};