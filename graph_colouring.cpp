#include <iostream>
#include <vector>
using namespace std;

// Check if it's safe to assign color to the current vertex
bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[vertex][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

// Utility function to solve the graph coloring problem
bool graphColoringUtil(int vertex, vector<vector<int>>& graph, int m, vector<int>& color) {
    int n = graph.size();
    if (vertex == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, graph, color, c)) {
            color[vertex] = c;
            if (graphColoringUtil(vertex + 1, graph, m, color))
                return true;
            color[vertex] = 0; // backtrack
        }
    }
    return false;
}

void graphColoring(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> color(n, 0); // 0 means no color

    if (!graphColoringUtil(0, graph, m, color)) {
        cout << "Solution does not exist.\n";
        return;
    }

    cout << "Coloring of vertices:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter number of colors: ";
    cin >> m;

    graphColoring(graph, m);

    return 0;
}
