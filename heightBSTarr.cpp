#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    TreeNode* node = new TreeNode(arr[mid]);
    node->left = sortedArrayToBST(arr, start, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, end);
    return node;
}

void printInOrder(TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }
}

int main() {
    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = sortedArrayToBST(arr, 0, n - 1);
    cout << "In-order traversal of the constructed BST: ";
    printInOrder(root);
    cout << endl;
    return 0;
}
