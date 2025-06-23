/** Leetcode Explore BST exercise
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



 struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*  Leetcode constraints 
        - number of nodes in tree is in the range [1, 5000]
        - 1 <= Node.val <= 10^7
        - root is a binary search tree
        - 1 <= target val <= 10^7

*/
class Solution {
public:

    TreeNode* findMin(TreeNode* root, TreeNode* p)
    {
        while(root->left != nullptr){
            root = root->left;
        }

        return root;
    }


    // Recursive Implementation
    // Time Complexity is O(H) where H is the bst height 
    // Space Complexity is 0(constant 1)
    //      memory used for two pointers

    // Operation: Given a root node reference of a BST and a key, delete the node with the 
    // given key in the BST. Return the root node reference (possibly updated) of the BST.
    TreeNode* deleteBST(TreeNode* root, int key) {

        if(root == nullptr){
            return root;
        }
        else if(key > root->val){
            root = deleteBST(root->right, key);
        }
        else if(key < root->val){
            root = deleteBST(root->left, key);
        }
        else{   // root->val == key
            if(root->left == nullptr && root->right == nullptr){
                // Case 1: root is a leaf node 
                delete root;                    // deallocate memory
                root = nullptr;
            }
            else if(root->left == nullptr){
                // Case 2: root has one child
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == nullptr){
                // Case 2: root has one child
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            else{
                // Case 3: root has two children
                // Find minimum value in the right subtree 
                TreeNode *temp = findMin(root->right);
                root->val = temp->val;                    // swap values
                // delete the temp node
                root->right = deleteBST(root->right, temp->val);
            }
        }

        return root;
    }
};


void runTests(void)
{
    {
        // Leetcode example 1:
        // Input 
        //      root = [5,3,6,2,4,null,7], key = 3
        // Output 
        //      [5,4,6,2,null,null,7] 
        // Explanation: 3 is replaced with its right child 4
        // Also acceptablbe: 3 is replaced with its left child 2 
        // [5,2,6,null,4,null,7]
    }

    {
        // Leetcode example 2:
        // Input 
        //      Input: root = [5,3,6,2,4,null,7], key = 0
        // Output 
        //      [] 
        // Explanation: 0 is not in the tree  
    }
}

int main(void)
{
    runTests();
    return 0;
}