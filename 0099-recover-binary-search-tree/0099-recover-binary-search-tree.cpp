class Solution {
public:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* second;
    TreeNode* prev;

    void inOrderTraversal(TreeNode* root) {
        if (root == NULL) return;

        inOrderTraversal(root->left);

        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                second = root;
            }
        }
        prev = root;

        inOrderTraversal(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = second = prev = NULL;

        inOrderTraversal(root);

        if (second != NULL) {
            std::swap(first->val, second->val);
        } else {
            std::swap(first->val, middle->val);
        }
    }
};