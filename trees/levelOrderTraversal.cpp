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
        vector<vector<int>> levelOrder(TreeNode* root) {
            if(!root) return {};
            queue<TreeNode*>q;
            q.push(root);
            q.push(nullptr);
            vector<vector<int>>ans;
            while(!q.empty()){
                vector<int>v;
                while(!q.empty() && q.front()!=nullptr){
                    TreeNode*t=q.front();
                    q.pop();
                    if(t){
                        v.push_back(t->val);
                        if(t->left) q.push(t->left);
                        if(t->right) q.push(t->right);
                    }
                }
                q.pop();
                ans.push_back(v);
                if(!q.empty()) q.push(nullptr);
            }
            return ans;
        }
    };