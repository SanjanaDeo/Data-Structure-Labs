#include <iostream>
#include <vector>
#include <queue>
#include <map>
class Graph {
private:
std::vector<std::vector<int>> adjMatrix;
std::map<int, std::vector<int>> adjList;
public:
Graph(int numNodes) {
adjMatrix.resize(numNodes, std::vector<int>(numNodes, 0));
}
void addEdge(int source, int destination) {
adjMatrix[source][destination] = 1;
adjMatrix[destination][source] = 1;
adjList[source].push_back(destination);
adjList[destination].push_back(source);
}
void printAdjMatrix() {
std::cout << "Adjacency Matrix:" << std::endl;
for (const auto& row : adjMatrix) {
for (const auto& value : row) {
std::cout << value << " ";
}
std::cout << std::endl;
}
}
void printAdjList() {
std::cout << "Adjacency List:" << std::endl;
for (const auto& entry : adjList) {
std::cout << entry.first << " -> ";
for (const auto& neighbor : entry.second) {
std::cout << neighbor << " ";
}
std::cout << std::endl;
}
}
void DFS(int startNode) {
std::vector<bool> visited(adjMatrix.size(), false);
DFSUtil(startNode, visited);
}
void DFSUtil(int currentNode, std::vector<bool>& visited) {
visited[currentNode] = true;
std::cout << currentNode << " ";
for (const auto& neighbor : adjList[currentNode]) {
if (!visited[neighbor]) {
DFSUtil(neighbor, visited);
}
}
}
void BFS(int startNode) {
std::vector<bool> visited(adjMatrix.size(), false);
std::queue<int> queue;
visited[startNode] = true;
queue.push(startNode);
while (!queue.empty()) {
int currentNode = queue.front();
queue.pop();
std::cout << currentNode << " ";
for (const auto& neighbor : adjList[currentNode]) {
if (!visited[neighbor]) {
visited[neighbor] = true;
queue.push(neighbor);
}
}
}
}
};
int main() {
// Create a graph
Graph graph(6);
// Add edges between landmarks
graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 3);
graph.addEdge(2, 3);
graph.addEdge(2, 4);
graph.addEdge(3, 4);
graph.addEdge(3, 5);
// Print the adjacency matrix and adjacency list
graph.printAdjMatrix();
graph.printAdjList();
// Perform DFS starting from node 0
std::cout << "DFS: ";
graph.DFS(0);
std::cout << std::endl;
// Perform BFS starting from node 0
std::cout << "BFS: ";
graph.BFS(0);
std::cout << std::endl;
return 0;
}
