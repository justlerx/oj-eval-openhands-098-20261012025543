#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary search tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to insert a value into a BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}

// Function to perform reverse in-order traversal to get values in descending order
void reverseInorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    
    reverseInorder(root->right, result);  // Visit right subtree first (larger values)
    result.push_back(root->val);          // Visit root
    reverseInorder(root->left, result);   // Visit left subtree last (smaller values)
}

// Function to find the cnt-th largest element in BST
int findKthLargest(TreeNode* root, int cnt) {
    vector<int> values;
    reverseInorder(root, values);
    return values[cnt - 1];  // cnt is 1-indexed
}

int main() {
    // Read the 7 node values and cnt
    vector<int> nodeValues(7);
    int cnt;
    
    for (int i = 0; i < 7; i++) {
        cin >> nodeValues[i];
    }
    cin >> cnt;
    
    // Build the BST from the input values
    TreeNode* root = nullptr;
    for (int val : nodeValues) {
        root = insertIntoBST(root, val);
    }
    
    // Find and output the cnt-th largest element
    cout << findKthLargest(root, cnt) << endl;
    
    // Clean up memory (optional for this problem)
    // In a real application, you might want to delete the tree
    // But for competitive programming, this is usually not necessary
    
    return 0;
}