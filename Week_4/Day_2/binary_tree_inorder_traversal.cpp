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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    void inorder(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};

TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
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
    for (int i=0; i<n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);

    Solution obj;
    vector<int> result = obj.inorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}