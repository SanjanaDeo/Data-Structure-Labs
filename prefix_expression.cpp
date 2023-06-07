#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
class Node {
public:
char data;
Node* left;
Node* right;
Node(char value) : data(value), left(nullptr), right(nullptr) {}
};
bool isOperator(char c) {
return (c == '+' || c == '-' || c == '*' || c == '/');
}
Node* constructExpressionTree(const std::string& expression) {
std::stack<Node*> stack;
for (int i = expression.length() - 1; i >= 0; i--) {
char currentChar = expression[i];
if (isOperator(currentChar)) {
Node* newNode = new Node(currentChar);
newNode->left = stack.top();
stack.pop();
newNode->right = stack.top();
stack.pop();
stack.push(newNode);
} else {
Node* newNode = new Node(currentChar);
stack.push(newNode);
}
}
return stack.top();
}
void postOrderTraversal(Node* root) {
if (root == nullptr) {
return;
}
std::stack<Node*> stack;
stack.push(root);
std::string result;
while (!stack.empty()) {
Node* current = stack.top();
stack.pop();
result += current->data;
if (current->right) {
stack.push(current->right);
}
if (current->left) {
stack.push(current->left);
}
}
// Reverse the result to get the post-order traversal
std::reverse(result.begin(), result.end());
std::cout << "Post-order traversal: " << result << std::endl;
}
void deleteTree(Node* root) {
if (root == nullptr) {
return;
}
deleteTree(root->left);
deleteTree(root->right);
delete root;
}
int main() {
std::string prefixExpression = "+--a*bc/def";
// Construct the expression tree
Node* root = constructExpressionTree(prefixExpression);
// Perform post-order traversal (non-recursive)
postOrderTraversal(root);
// Delete the entire tree
deleteTree(root);
return 0;
}
