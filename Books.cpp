# include<iostream>
#include <vector>
using namespace std;
class Node {
public:
string name;
vector<Node*> children;
Node(const string& nodeName) : name(nodeName) {}
void addChild(Node* child) {
children.push_back(child);
}
};
void printNodes(Node* node, int depth = 0) {
for (int i = 0; i < depth; i++) {
cout << " ";
}
cout << node->name << endl;
for (Node* child : node->children) {
printNodes(child, depth + 1);
}
}
int countNodes(Node* node) {
int count = 1; // Count the current node itself
for (Node* child : node->children) {
count += countNodes(child);
}
return count;
}
int main() {
// Construct the book tree
Node* book = new Node("Book");
Node* chapter1 = new Node("Chapter 1");
Node* chapter2 = new Node("Chapter 2");
Node* section1_1 = new Node("Section 1.1");
Node* section1_2 = new Node("Section 1.2");
Node* section2_1 = new Node("Section 2.1");
Node* subsection1_1_1 = new Node("Subsection 1.1.1");
Node* subsection2_1_1 = new Node("Subsection 2.1.1");
book->addChild(chapter1);
book->addChild(chapter2);
chapter1->addChild(section1_1);
chapter1->addChild(section1_2);
chapter2->addChild(section2_1);
section1_1->addChild(subsection1_1_1);
section2_1->addChild(subsection2_1_1);
// Print the nodes of the book tree
cout << "Nodes of the book tree:" << endl;
printNodes(book);
// Calculate time and space requirements
int nodeCount = countNodes(book);
cout << "Total nodes: " << nodeCount << endl;
int timeRequirement = nodeCount; // Each node is printed once
int spaceRequirement = nodeCount * sizeof(Node);
cout << "Time requirement: " << timeRequirement << " units" << endl;
cout << "Space requirement: " << spaceRequirement << " bytes" <<endl;
// Deallocate the dynamically allocated memory
delete book;
delete chapter1;
delete chapter2;
delete section1_1;
delete section1_2;
delete section2_1;
delete subsection1_1_1;
delete subsection2_1_1;
return 0;
}
