#include <iostream>
#include <climits>
class Node {
public:
int data;
Node* left;
Node* right;
Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST {
private:
Node* root;
Node* insertNodeRecursive(Node* root, int value) {
if (root == nullptr) {
return new Node(value);
}
if (value < root->data) {
root->left = insertNodeRecursive(root->left, value);
} else if (value > root->data) {
root->right = insertNodeRecursive(root->right, value);
}
return root;
}
int findMinValueRecursive(Node* root) {
if (root == nullptr) {
return INT_MAX;
}
int leftMin = findMinValueRecursive(root->left);
int rightMin = findMinValueRecursive(root->right);
return std::min(root->data, std::min(leftMin, rightMin));
}
void swapLeftRightRecursive(Node* root) {
if (root == nullptr) {
return;
}
Node* temp = root->left;
root->left = root->right;
root->right = temp;
swapLeftRightRecursive(root->left);
swapLeftRightRecursive(root->right);
}
bool searchValueRecursive(Node* root, int value) {
if (root == nullptr) {
return false;
}
if (root->data == value) {
return true;
}
if (value < root->data) {
return searchValueRecursive(root->left, value);
} else {
return searchValueRecursive(root->right, value);
}
}
public:
BST() : root(nullptr) {}
void insert(int value) {
root = insertNodeRecursive(root, value);
}
int findMinValue() {
return findMinValueRecursive(root);
}
void swapLeftRight() {
swapLeftRightRecursive(root);
}
bool searchValue(int value) {
return searchValueRecursive(root, value);
}
};
int main() {
// Construct binary search tree by inserting values
int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
int numValues = sizeof(values) / sizeof(values[0]);
BST bst;
for (int i = 0; i < numValues; i++) {
bst.insert(values[i]);
}
// Find the minimum data value in the tree
int minValue = bst.findMinValue();
std::cout << "Minimum data value in the tree: " << minValue << std::endl;
// Swap left and right pointers at every node
bst.swapLeftRight();
// Search for a value in the tree
int searchValue = 35;
bool found = bst.searchValue(searchValue);
if (found) {
std::cout << "Value " << searchValue << " found in the tree." << std::endl;
} else {
std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
}
return 0;
}
