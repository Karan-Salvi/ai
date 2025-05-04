#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX_V 100  // Maximum number of vertices, can be adjusted as needed

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm
void primMST(int graph[MAX_V][MAX_V], int V) {
    int parent[V];  // Array to store constructed MST
    int key[V];  // Key values used to pick minimum weight edge
    bool mstSet[V];  // To represent the MST set

    // Initialize key values and MST set
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in the MST
    key[0] = 0;
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);  // Get vertex with minimum key value
        mstSet[u] = true;  // Add vertex to the MST

        // Update the key and parent values of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[MAX_V][MAX_V];

    // Take the adjacency matrix as input
    cout << "Enter the adjacency matrix (use 0 for no edge, positive integer for weights):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Call Prim's algorithm to find the MST
    primMST(graph, V);

    return 0;
}
