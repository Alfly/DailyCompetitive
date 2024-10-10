/**
 * 字节面试题：二叉树两节点的最短路径
 * https://github.com/sisterAn/JavaScript-Algorithms/issues/82
 * 
 * 2096. 从二叉树一个节点到另一个节点每一步的方向
 * 236. 二叉树的最近公共祖先 + 257. 二叉树的所有路径
*/

class Solution {
public:
    int shortestDistance(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lowestCA = lca(root, p, q);
        vector<TreeNode*> p_path, q_path;
        getPath(lowestCA, p, p_path);
        getPath(lowestCA, q, q_path);
        return p_path.size() + q_path.size();
    }
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* l = lca(root->left, p, q);
        TreeNode* r = lca(root->right, p, q);
        if (l && r) return root;
        return l ? l : r;
    }
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        
        path.push_back(root);

        if (root == target) return true;

        bool found = dfs(root->left, target, path) || dfs(root->right, target, path);
        if (!found) {
            path.pop_back();
        }
        return found;
    }
};