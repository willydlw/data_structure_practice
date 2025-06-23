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
        - number of nodes in tree is in the range [1, 10^4]
        - 10^5 <= Node.val <= 10^5
        - all nodes will have unique values
*/
class Solution {
public:
    // Iterative Implementation
    // Time Complexity is O(H) where H is the bst height 
    // Space Complexity is 0(constant)  function declares 3 additonal pointers

    // Given the root of a binary search tree and a node p in it, return the in-order 
    // successor of that node in the BST. If the given node has no in-order successor in the 
    // tree, return null.

    // The successor of a node p is the node with the smallest key greater than p.val.


    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *current = root;

        // The node where the last left branch was taken in the
        // search for p. Since a left branch was taken here to
        // find p, this ancestor value will be greater than p
        TreeNode *lastLeftBranch = nullptr;

        // find p's location 
        while(current != nullptr && current != p){
            if(p->val < current->val){
                lastLeftBranch = current;
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if(current == nullptr){
            return current;         // p not in tree 
        }

        // p is in tree and current points to p
        // case 1: p has a right child 
        // find leftmost child of right subtree 
        if(current->right != nullptr)
        {
            TreeNode *successor = current->right;
            while(successor->left != nullptr){
                successor = successor->left;
            }

            return successor;
        }
        else{
            // Case 2: p node does not have a right child 
            // The inorder successor is the ancestor where the last 
            // left turn was taken 
            return lastLeftBranch;
        }
    }

    // Iterative Implementation 
    // Time complexity is O(H) where H is bst height 
    // Space complexity is O(1) because additional memory required 
    //   is for one TreeNode* 
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
    }
};


void runTests(void)
{
    {
        // Leetcode example 1:
        // Input 
        //      int arr arr[5] = {4,2,7,1,3};
        //      int target = 2;
        // Output 
        //      int ans[3] = {2,1,3};
    }

    {
        // Leetcode example 2:
        // Input 
        //      int arr arr[5] = {4,2,7,1,3};
        //      int target = 5;
        // Output 
        //      int ans[];  
    }
}

int main(void)
{
    runTests();
    return 0;
}