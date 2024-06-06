int kthSmallest(struct TreeNode* root, int k) {
    // Stack for iterative traversal
    struct TreeNode* stack[100];
    int top = -1;
   
    // Current node
    struct TreeNode* curr = root;
   
    // Variable to keep track of visited nodes
    int count = 0;
   
    // Traverse the tree until the current node is NULL
    while (curr != NULL || top != -1) {
        // Move to the leftmost node
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
       
        // Pop the top node from the stack
        curr = stack[top--];
       
        // Increment the count
        count++;
       
        // If count equals k, return the value of the current node
        if (count == k) {
            return curr->val;
        }
       
        // Move to the right of the current node
        curr = curr->right;
    }
   
    // If k is greater than the number of nodes in the tree
    return -1; // or any other appropriate error code
}
