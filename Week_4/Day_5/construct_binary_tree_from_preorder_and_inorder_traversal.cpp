#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if(left > right) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];

        root->left = build(preorder, inorder, left, mid - 1);
        root->right = build(preorder, inorder, mid + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};

void printLevelOrder(TreeNode* root) {
    if(root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        while(size--) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);

    for(int i=0; i<n; i++) {
        cin >> preorder[i];
    }

    for(int i=0; i<n; i++) {
        cin >> inorder[i];
    }
    Solution obj;
    TreeNode* root = obj.buildTree(preorder, inorder);

    printLevelOrder(root);
    return 0;
}