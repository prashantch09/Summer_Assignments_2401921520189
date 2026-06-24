#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

TreeNode* buildTree(vector<int>& nodes) {
    if(nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if(i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    cin >> n;

    vector<int> nodes(n);
    for(int i=0; i<n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);

    Solution obj;
    vector<vector<int>> result = obj.levelOrder(root);

    for(auto level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}