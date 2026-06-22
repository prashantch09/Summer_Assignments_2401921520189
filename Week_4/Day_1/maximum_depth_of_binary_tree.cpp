#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.size() == 0 || nodes[0] == -1) return nullptr;

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

    Solution sol;
    cout << sol.maxDepth(root) << endl;
    return 0;
}