// Minimum Height Trees

class Solution {
public:
    int minH = INT_MAX;
    vector<bool> visited;
    vector<int> heights;
    vector<int> op;
    
    int dfs(vector<vector<int>>& tree, int si) {
        for(int ei : tree[si]) {
            if(visited[ei])
                continue;
            visited[ei] = true;
            heights[si] = max(heights[si], 1 + dfs(tree, ei));
        }
        
        return heights[si];
    }
    
    void findMin(vector<vector<int>>& tree, int si, int pl) {
        int fmax = pl, smax = pl;
        for(int ei : tree[si]) {
            if(visited[ei])
                continue;
            if(heights[ei] > fmax) {
                smax = fmax;
                fmax = heights[ei];
            } else if(heights[ei] > smax) {
                smax = heights[ei];
            }
        }
        
        if(fmax < minH) {
            minH = fmax;
            op.clear();
            op.push_back(si);
        } else if(fmax == minH) {
            op.push_back(si);
        }
        
        for(int ei : tree[si]) {
            if(visited[ei])
                continue;
            visited[ei] = true;
            if(heights[ei] == fmax) {
                findMin(tree, ei, smax + 1);
            } else {
                findMin(tree, ei, fmax + 1);
            }
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        heights.resize(n, 1);
        if(n == 1)
            return {0};
        
        vector<vector<int>> tree(n);
        for(vector<int> v : edges) {
            tree[v[0]].push_back(v[1]);
            tree[v[1]].push_back(v[0]);
        }
        
        visited.resize(n, false);
        visited[0] = true;
        dfs(tree, 0);
        
        
        for(int i = 0; i < n; i++)
            visited[i] = false;
        visited[0] = true;
        findMin(tree, 0, 0);
        
        
        return op;
    }
};