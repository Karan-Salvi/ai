#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adj;

public:
    // Add edge to undirected graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Recursive Helper
    void dfsUtil(int node, unordered_set<int>& visited) {
        visited.insert(node);
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    // DFS traversal
    void dfs(int start) {
        unordered_set<int> visited;
        cout << "DFS Traversal:\n";
        dfsUtil(start, visited);
        cout << endl;
    }

    // BFS traversal
    void bfs(int start) {
        unordered_set<int> visited;
        queue<int> q;

        visited.insert(start);
        q.push(start);

        cout << "BFS Traversal:\n";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

// ---------------------------
// Example Usage
int main() {
    Graph g;

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    g.dfs(0);
    g.bfs(0);

    return 0;
}